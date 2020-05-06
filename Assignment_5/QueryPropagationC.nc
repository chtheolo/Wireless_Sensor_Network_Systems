#include <string.h>
#include "Timer.h"

#include "QueryRadioFlooding.h"
#include "QueryPacket.h"
#include "SamplingPacket.h"
#include "StatsSamplingPacket.h"
#include "ActiveQueryQueue.h"
#include "SendersHistory.h"
#include "Contributed_Nodes.h"
#include "QueryCancel.h"
#include "Update.h"
#include "ResponseUpdate.h"
#include "Serial_BinaryCode.h"
#include "Binary_Response.h"
#include "Application_Image.h"


#define NUMBER_OF_MSGS 20
#define SIZE 10
#define NUMBER_OF_QUERIES 3
#define LAST_SENDERS 5
#define OFFSET 20
#define MAX_APPLICATIONS 2

module QueryPropagationC @safe()
{
	uses interface Boot;
	uses interface Leds;
	uses interface Timer<TMilli> as TimerQueryBroadcast;
	uses interface Timer<TMilli> as TimerReadSensor;
	uses interface Timer<TMilli> as TimerSendPCSerial;
	uses interface Timer<TMilli> as TimerQueryFired;
	uses interface Timer<TMilli> as TimerReUnicast;
	uses interface Timer<TMilli> as TimerQueryCancelResponse;
	uses interface Timer<TMilli> as Timer_StatsUnicast_Unicast;
	uses interface Timer<TMilli> as TimerApplications;
	//uses interface Timer<TMilli> as TimerCacheDataSensor;

	uses interface Read<uint16_t>;

	uses interface Packet as SamplingAMPacket;
	uses interface AMSend as SamplingRadioAMSend;
	uses interface Receive as SamplingRadioReceive;
 
	uses interface Packet;
	//uses interface AMPacket;
	uses interface AMSend as RadioAMSend;
	uses interface Receive as RadioReceive;
	uses interface SplitControl as RadioAMControl;

	uses interface Packet as SerialPacket;
	//uses interface AMPacket as SerialAMPacket;
	uses interface AMSend as SerialAMSend;
	uses interface Receive as SerialReceive;
	uses interface SplitControl as SerialAMControl;

}
implementation
{
/* --------------- POINTERS TO BUFFERS -------------- */
	response_update_msg_t *ucast_ReUpd;
	update_msg_t *upd_bcast, *rcv_bcast_upd;
	query_flooding_msg_t *r_pkt, *bcast_pkt;
	query_cancel_msg_t *srl_query_cancel, *rcv_query_cacnel, *bcast_query_cancel, *ucast_query_cancel;
	sampling_msg_t *r_sampling_pkt, *s_sampling_pkt, *ucast_pkt;
	stats_sampling_msg_t *r_stats_sampling_pkt, *s_stats_sampling_pkt, *stats_ucast_pkt;
	query_msg_t* s_pkt;
	binary_msg_t* s_bin_code;
	binary_rsp_t *bin_response;

	message_t pkt, serial_pkt;
	
/* --------------- HELPING VARIABLES ----------------- */

/*  8-bit  */
	uint8_t send,save;							/* BROADCAST - indicates free pos to save the msg and which msg is ready to send in PacketBuffer[] */
	uint8_t sampling_send, sampling_save;		/* UNICAST - indicates free pos to save the msg and which msg is ready to send in SamplingPacketBuffer[] */
	uint8_t stats_sampling_send;				/* UNICAST - indicates which msg is ready to send in StatsSamplingPacketBuffer[] */
	uint8_t stats_sampling_save;				/* UNICAST - indicates free pos to save the msg in StatsSamplingPacketBuffer[] */
	uint8_t number_Of_queries;					/* Counter to save the number of active queries */
	uint8_t next;								/* Dipicts the next free pos in QuerySendersHistory[] */
	uint8_t remindQuery;						/* Helping variable to keep the query in which we are working for. */
	uint8_t start; 								/* Counter used for accessing elements from arrays, e.g. AQQ[]*/
	uint8_t HoldTimer;							/* Variable in which we store the query that last called the TimerQueryFired().*/
	uint8_t query_pos;							/* Counter used for accessing elements from arrays, e.g. AQQ[]*/
	uint8_t minQuery;							/* Variable to keep the query with min time to fire. */
	uint8_t expiredQuery;						/* It shows the query whose lifetime has just ended. */
	uint8_t sendQuery;							/* It indicates the query which is ready to be broadcast. */
	uint8_t Hold_Sampling_Timer;				/* Variable in which we store the query that last called the TimerReadSensor().*/
	uint8_t sequence_number; // 8
	uint8_t data_id; // 8
	uint8_t s_data_id; // 8
	uint8_t sampling_id;
	uint8_t forwarder_id; // 8
	uint8_t destination_id; // 8
	uint8_t hops; // 8
	uint8_t source_id;
	uint8_t Hold_Waiting_Timer;
	uint8_t nextChild;							/* circular pointer for adding children in AQQ.children[] */
	uint8_t sendTofather;
	uint8_t query_cancel;
	uint8_t send_qcancelTo_node;
	uint8_t count_received_children;			/*A counter that informs in every iteration how many children send me a msg.*/
	uint8_t mode;
	uint8_t new_entry_node;
	uint8_t i,j;								/*Helping Counters*/
	uint8_t instruction;						/*The instruction that is being decoded from the application that holds the controller.*/
	uint8_t maxInterpreterIterations;			/*Set the max interpretations for an application in order to avoid calculate them every time in a while-loop. Reduce the calculations but increase by 8-bit the memory.*/
	uint8_t appHoldingController;				/*Current Application that holds the controller.*/
	uint8_t appHoldingTimer;					/*Current Application that holds the timer.*/
	uint8_t pc;									/*Program counter.*/
	uint8_t number_of_active_apps;				/*The whole of active applications in the VM.*/
	uint8_t count_instructions;					/*Count the instructions for context-switch.*/
	uint8_t appWaitSensor;						/*The first application that called the ReadSensor.*/

/*  16-bit  */
	uint16_t time4MeasurementStartAt;			/*Timer start flag for measurements scheduling.*/
	uint16_t minPeriod; 
	uint16_t sensor_data;						/*Variable to save the sensor's value.*/
	uint16_t min;								/*The minimum brightness value from all wireless sensor network.*/
	uint16_t max;								/*The maximum brightness value from all wireless sensor network.*/
	uint16_t average;
	uint16_t startDelay;
	uint16_t dtDelay;
	int16_t rx,ry;								/*Registers mask variables*/

/*	32-bit	*/
	uint32_t t0,dt;
	uint32_t runningTime;						/*The amount of time that the current timer is up and running.*/
	uint32_t checkTimer;						/*Check the amount of time passed through the start time of the current timer.*/
	uint32_t timerStartAt;						/*Timer Start at flag for query scheduling.*/
	uint32_t timerApplicationStartAt;			/*Timer start at flag for application timer scheduling.*/


/*  bool  */	
	bool busy = FALSE;
	bool unicast_busy = FALSE;
	bool serial_busy = FALSE;

/* ----------------------- ARRAYS -------------------- */	
	message_t PacketBuffer[SIZE], SamplingPacketBuffer[SIZE], StatsSamplingPacketBuffer[SIZE];
	Application_Image_t Apps_Queue[2];																		/* Active Applactions data structure*/
	ActiveQueryQueue_t AQQ[NUMBER_OF_QUERIES];
	SendersHistory_t QuerySendersHistory[LAST_SENDERS];
	contributed_nodes_t ContributedNodes[LAST_SENDERS];
	uint16_t TimeToMeasure[3];
	
/* %% ------------------------------------------------------ TASKS --------------------------------------------------- %% */
	task void init_StateMessages() {
		for (start=0; start < LAST_SENDERS; start++) {
			QuerySendersHistory[start].source_id = 0;
			QuerySendersHistory[start].sequence_number = 0;
		}
	}

	task void init_ActiveQueryQ() {
		for (start=0; start < NUMBER_OF_QUERIES; start++) {
			AQQ[start].state = 0;
			AQQ[start].sampling_id = 0;			/*new*/
		}
	}

	task void init_ContributedNodes() {
		for (start = 0; start < LAST_SENDERS; start++) {
			ContributedNodes[start].node_id = 0;
		}
	}

	task void init_Apps_Queue() {
		for (start = 0; start < 2; start++) {
			Apps_Queue[start].state = 0;
			Apps_Queue[start].app_id = 0;
			Apps_Queue[start].RegisterReadSensor = 0; // 0 value depicts that there isn't register which needs sensors data.
			for (i=0; i<6; i++) {
				Apps_Queue[start].registers[i] = 0;
			}
		}
	}

/* ------------------------------- Interpretation ----------------------------- */
	task void Interpretation() {
		
		pc = Apps_Queue[appHoldingController].pc;							/** set new program counter.*/ 
		count_instructions = 0;
		//maxInterpretations mporei na mhn xreiazetai 
		while (pc < maxInterpreterIterations && Apps_Queue[appHoldingController].state != 0) {

			/* ---------------------------------------------------- CONTEXT SWITCHING -------------------------------------------------------- */
			if (count_instructions >= 3 || Apps_Queue[appHoldingController].RegisterReadSensor != 0) {
				Apps_Queue[appHoldingController].pc = pc;					/**Save where current application pc points.*/
				
				start = appHoldingController;
				appHoldingController++;
				appHoldingController = appHoldingController%MAX_APPLICATIONS;
		
				while (start != appHoldingController) {							/* Psaxnw ws epomeno application ena energo kai kapoio pou den exei kanei return.
																				** An 3anaftasw thn idia efarmogi, profanws den uparxei kapoia allh gia na parei ton controller, opote sunexizw sthn idia. */
					if (Apps_Queue[appHoldingController].state == 1 && Apps_Queue[appHoldingController].pc != 0x00 && Apps_Queue[appHoldingController].TimerCalled == FALSE ) {  /* check if there is any active application that hasn't return.*/
						
						if (Apps_Queue[appHoldingController].RegisterReadSensor == 0) {										/*there is an active app. check if this app waits Sensor's data in order to continue its execution.*/
							maxInterpreterIterations = Apps_Queue[appHoldingController].BinaryMessage[0];
							count_instructions = 0;
							post Interpretation();
							return;
						}
						call Read.read();
						return;
					}
					appHoldingController++;
					appHoldingController = appHoldingController%MAX_APPLICATIONS;
				}

				if (Apps_Queue[appHoldingController].RegisterReadSensor != 0) {		/*This conditioin will be executed only if there is no other application in the system and the controller is back to the same application.*/
					call Read.read();												/*Check if i want Sensor's data to continue.*/
					return;
				}

			}
			/* ------------------------------------------------- END OF CONTEXT SWITCHING ------------------------------------------------------- */
			
			instruction = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0xF0;
			
			switch (instruction) {
				case 0x00:											/*return*/
					if (Apps_Queue[appHoldingController].TimerCalled == FALSE) {	/*If an application returned before calling Timer Handler, means that the current application terminated its execution. */
						Apps_Queue[appHoldingController].state = 0;
					}

					count_instructions = 0;
					Apps_Queue[appHoldingController].pc = pc;					/**Save where current application pc points.*/

					start = appHoldingController;
					appHoldingController++;
					appHoldingController = appHoldingController%MAX_APPLICATIONS;
			
					while (start != appHoldingController) {							/* Psaxnw ws epomeno application ena energo kai kapoio pou den exei kanei thn entolh return.
																					** An 3anaftasw thn idia efarmogi tote sunexizw sthn idia. */
						if (Apps_Queue[appHoldingController].state == 1 /*&& Apps_Queue[appHoldingController].pc != 0x00 && Apps_Queue[appHoldingController].TimerCalled == FALSE*/) {  /* check if active application and has instructions to do.*/
							if (Apps_Queue[appHoldingController].RegisterReadSensor == 0) {
								
								maxInterpreterIterations = Apps_Queue[appHoldingController].BinaryMessage[0];
								post Interpretation();
								return;
							}
							call Read.read();
							return;
						}
						appHoldingController++;
						appHoldingController = appHoldingController%MAX_APPLICATIONS;
					}
								/*if no other active application in the system, just return from the execution.*/
					return;
				case 0x10:											/* set, rx = val (1rx)*/
					rx = (Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F);
					Apps_Queue[appHoldingController].registers[--rx] = Apps_Queue[appHoldingController].BinaryMessage[++pc];
					pc++;
					break;
				case 0x20:											/* cpy, rx = ry */
					rx = (Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F);
					Apps_Queue[appHoldingController].registers[--rx] = Apps_Queue[appHoldingController].registers[Apps_Queue[appHoldingController].BinaryMessage[++pc]];
					pc++;
					break;
				case 0x30:											/* add, rx = rx + ry */
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					ry = Apps_Queue[appHoldingController].BinaryMessage[++pc] & 0x0F;
					rx--;
					ry--;
					Apps_Queue[appHoldingController].registers[rx] += Apps_Queue[appHoldingController].registers[ry];
					pc++;
					break;
				case 0x40:											/* sub,rx = rx-ry */
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					ry = Apps_Queue[appHoldingController].BinaryMessage[++pc] & 0x0F;
					rx--;
					ry--;
					Apps_Queue[appHoldingController].registers[rx] -= Apps_Queue[appHoldingController].registers[ry];
					pc++;
					break;
				case 0x50:											/* inc, rx = rx + 1 */
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					Apps_Queue[appHoldingController].registers[--rx]++;
					pc++;
					break;
				case 0x60:											/* dec, rx = rx - 1 */
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					Apps_Queue[appHoldingController].registers[--rx]--;
					pc++;
					break;
				case 0x70:											/* max, rx = max(rx,ry) */
					j=0;
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					while (j < 6) {
						if (Apps_Queue[appHoldingController].registers[--rx] < Apps_Queue[appHoldingController].registers[j]) {
							Apps_Queue[appHoldingController].registers[--rx] = Apps_Queue[appHoldingController].registers[j];
						}
						j++;
					}
					pc++;
					break;
				case 0x80:											/* min, rx = min(rx,ry) */
					j=0;
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					while (j < 6) {
						if (Apps_Queue[appHoldingController].registers[--rx] > Apps_Queue[appHoldingController].registers[j]) {
							Apps_Queue[appHoldingController].registers[--rx] = Apps_Queue[appHoldingController].registers[j];
						}
						j++;
					}
					pc++;
					break;
				case 0x90:											/* bgz, if ( rx > 0 ) pc = pc + off */
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					rx--;
					if (Apps_Queue[appHoldingController].registers[rx] > 0) {
						pc += (Apps_Queue[appHoldingController].BinaryMessage[++pc]);
						break;
					}
					pc+=2;
					break;
				case 0xA0:											/* bez, if ( rx == 0 ) pc = pc + off */
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					rx--;
					if (Apps_Queue[appHoldingController].registers[rx] == 0) {
						pc += Apps_Queue[appHoldingController].BinaryMessage[++pc];
						break;
					}
					pc+=2;
					break;
				case 0xB0:											/* bra, pc = pc + off */
					pc += (Apps_Queue[appHoldingController].BinaryMessage[++pc]);
					break;
				case 0xC0:											/* led, f ( val != 0 ) turn led on else turn led off */
					if ((Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F) == 0x01){
						if (Apps_Queue[appHoldingController].app_id == 0) { 
							call Leds.led1On();
						}
						else { 
							call Leds.led2On();
						}
						
						pc++;
						break;
					}
					if (Apps_Queue[appHoldingController].app_id == 0) { call Leds.led1Off(); }
					else { call Leds.led2Off(); }
					pc++;
					break;
				case 0xD0:											/* rdb, rx = current brightness value */
					if (Apps_Queue[appHoldingController].app_id == 0) {
						call Leds.led0Off();
					}
					else if (Apps_Queue[appHoldingController].app_id == 1) {
						call Leds.led1On();
					}
					rx = Apps_Queue[appHoldingController].BinaryMessage[pc] & 0x0F;
					//if (call TimerCacheDataSensor.isRunning() == TRUE) {
					//	Apps_Queue[appHoldingController].registers[--rx] = sensor_data;
					//	pc++;
					//	break;
					//}
					Apps_Queue[appHoldingController].RegisterReadSensor = rx;
					pc++;
					break;
				case 0xE0:											/* tmr */
					pc++;
					Apps_Queue[appHoldingController].TimerRemainingTime = Apps_Queue[appHoldingController].BinaryMessage[pc] * 1000;  /*Keep the remaining time*/
					Apps_Queue[appHoldingController].TimerCalled = TRUE;

					if (call TimerApplications.isRunning() == TRUE) {

						checkTimer = call TimerApplications.getNow();
						runningTime = checkTimer - timerApplicationStartAt;
						dt = Apps_Queue[appHoldingTimer].TimerRemainingTime - runningTime;

						if (dt > Apps_Queue[appHoldingController].TimerRemainingTime /*(Apps_Queue[appHoldingController].BinaryMessage[pc]*1000)*/) {
							appHoldingTimer = appHoldingController;
							call TimerApplications.startOneShot(Apps_Queue[appHoldingController].BinaryMessage[pc]*1000);
							timerApplicationStartAt = call TimerApplications.getNow();
						}
						else {
							timerApplicationStartAt = call TimerApplications.getNow();
						}
						
						j=0;
						while (j < MAX_APPLICATIONS) {
							if (Apps_Queue[j].state == 1 && j!= appHoldingController) {
								Apps_Queue[j].TimerRemainingTime -= runningTime;
							}
							j++;
						}

					}
					else {
						appHoldingTimer = appHoldingController;
						call TimerApplications.startOneShot(Apps_Queue[appHoldingController].TimerRemainingTime/*Apps_Queue[appHoldingController].BinaryMessage[pc]*1000*/);
						timerApplicationStartAt = call TimerApplications.getNow();
					}
					
					pc++;
					break;
			}
			count_instructions++;
		}
	}
	
/* ------------------------------- Query Scheduling --------------------------- */
	task void QueryScheduling() {
		/* check if i am alone or other queries also running */
		if (call TimerQueryFired.isRunning() == TRUE) {
			checkTimer = call TimerQueryFired.getNow();
			runningTime = checkTimer - timerStartAt;
			dt = AQQ[HoldTimer].query_lifetime - runningTime; //remaining_time to expire.

			if (dt > AQQ[sendQuery].query_lifetime) {
				HoldTimer = sendQuery; 
				call TimerQueryFired.startOneShot(AQQ[HoldTimer].query_lifetime);
				timerStartAt = call TimerQueryFired.getNow();
			}
			else {
				timerStartAt = call TimerQueryFired.getNow();
			}

			query_pos = 0;
			while(query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].state == 1 && query_pos != sendQuery) {
					AQQ[query_pos].query_lifetime = AQQ[query_pos].query_lifetime - runningTime; //remaining_timer to expire
				}
				query_pos++;
			}
		}
		else {
			HoldTimer = sendQuery; 
			call TimerQueryFired.startOneShot(AQQ[HoldTimer].query_lifetime); //end query lifetime when TimerQueryFired fire
			timerStartAt = call TimerQueryFired.getNow();
			call Leds.led0On();
		}
		/* __________________________________________________ */

		if (call TimerQueryBroadcast.isRunning() == TRUE) {
			t0 = call TimerQueryBroadcast.gett0();
			dt = call TimerQueryBroadcast.getdt();
			call TimerQueryBroadcast.startOneShot(t0 + dt);
		}
		else {
			call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 30);
		}

	}
/* ------------------------------- Measurement Scheduling -------------------------------- */
	task void MeasurementScheduling() {
		if (call TimerReadSensor.isRunning() == TRUE) {
			checkTimer = call TimerReadSensor.getNow();
			runningTime = checkTimer - time4MeasurementStartAt;
			dt = TimeToMeasure[Hold_Sampling_Timer] - runningTime;
			
			if (dt > TimeToMeasure[sendQuery]) {
				Hold_Sampling_Timer = sendQuery;
				call TimerReadSensor.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
				time4MeasurementStartAt = call TimerReadSensor.getNow();
			}
			else {
				time4MeasurementStartAt = call TimerReadSensor.getNow();
			}

			query_pos = 0;
			while( query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].state == 1 && query_pos != sendQuery) {
					TimeToMeasure[query_pos] = TimeToMeasure[query_pos] - runningTime; // remaining_timer to expire
				}
				query_pos++;
			}
		}
		else {
			Hold_Sampling_Timer = sendQuery;
			call TimerReadSensor.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
			time4MeasurementStartAt = call TimerReadSensor.getNow();
		}
	}
/* ------------------------------- Delay Measurement Scheduling -------------------------------- */
	task void DelayMeasurementScheduling() {
		if (AQQ[remindQuery].source_id == TOS_NODE_ID) {											/****** ORIGINATOR NODE ******/
			if (call TimerSendPCSerial.isRunning() == TRUE && Hold_Waiting_Timer != remindQuery) {  /** if the new waiting time calculation is for a new query then schedule */
				checkTimer = call TimerSendPCSerial.getNow();
				runningTime = checkTimer - AQQ[Hold_Waiting_Timer].startDelay;
				dt = AQQ[remindQuery].RemaingTime - runningTime;
				AQQ[remindQuery].startDelay = call TimerSendPCSerial.getNow();						/* keep what time the new q ask for timer */

				if (dt > AQQ[remindQuery].WaitingTime) {											/*If WT for new q is smaller than one that hold the timer */
					Hold_Waiting_Timer = remindQuery;
					call TimerSendPCSerial.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime);
				}

				query_pos = 0;
				while( query_pos < NUMBER_OF_QUERIES) {
					if (AQQ[query_pos].state == 1 && query_pos != remindQuery) {
						AQQ[query_pos].RemaingTime -= runningTime;									/*remaing time */
					}
					query_pos++;
				}
			}
			else {																					/** else if the new waiting time calculation is for the same query */
				Hold_Waiting_Timer = remindQuery;
				call TimerSendPCSerial.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime);
				AQQ[Hold_Waiting_Timer].startDelay = call TimerSendPCSerial.getNow();
			}
		}
		else {																						/***** MIDDLE NODE ******/
			if (call Timer_StatsUnicast_Unicast.isRunning() == TRUE && Hold_Waiting_Timer != remindQuery) {  /** if the new waiting time calculation is for a new query then schedule */
				checkTimer = call Timer_StatsUnicast_Unicast.getNow();
				runningTime = checkTimer - AQQ[Hold_Waiting_Timer].startDelay;
				dt = AQQ[remindQuery].RemaingTime - runningTime;
				AQQ[remindQuery].startDelay = call Timer_StatsUnicast_Unicast.getNow();						/* keep what time the new q ask for timer */

				if (dt > AQQ[remindQuery].WaitingTime) {											/*If WT for new q is smaller than one that hold the timer */
					Hold_Waiting_Timer = remindQuery;
					call Timer_StatsUnicast_Unicast.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime);
				}

				query_pos = 0;
				while( query_pos < NUMBER_OF_QUERIES) {
					if (AQQ[query_pos].state == 1 && query_pos != remindQuery) {
						AQQ[query_pos].RemaingTime -= runningTime;									/*remaing time */
					}
					query_pos++;
				}
			}
			else {																					/** else if the new waiting time calculation is for the same query */
				Hold_Waiting_Timer = remindQuery;
				call Timer_StatsUnicast_Unicast.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime);
				AQQ[Hold_Waiting_Timer].startDelay = call Timer_StatsUnicast_Unicast.getNow();		/* Keep a flag, to remember when you start the clock */
			}
		}	
	}
/* ------------------------------- Serial Send -------------------------------- */
	task void SendSerial() {
		if (!serial_busy) {			/* SIMPLE mode == 1 */
			if (/*AQQ[remindQuery].propagation_mode == 0*/mode == 0) {
				s_sampling_pkt = (sampling_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (sampling_msg_t) ));
				if (s_sampling_pkt == NULL) {
					return;
				}
				
				s_sampling_pkt->source_id = source_id;
				s_sampling_pkt->sampling_id = sampling_id;
				s_sampling_pkt->data_id = s_data_id;
				s_sampling_pkt->forwarder_id = forwarder_id;
				s_sampling_pkt->sensor_data = sensor_data;
				s_sampling_pkt->destination_id = destination_id;
				s_sampling_pkt->sequence_number = sequence_number;
				s_sampling_pkt->mode = 0;

				if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (sampling_msg_t)) == SUCCESS){
					dbg("BroadcastingC", "Start sending serial packet\n\n ");
					serial_busy = TRUE;
				}

			}/* STATS mode == 1 */
			else if (/*AQQ[remindQuery].propagation_mode*/mode == 1) {

				s_stats_sampling_pkt = (stats_sampling_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (stats_sampling_msg_t) ));
				if (s_stats_sampling_pkt == NULL) {
					return;
				}
				
				s_stats_sampling_pkt->source_id = source_id;
				s_stats_sampling_pkt->data_id = s_data_id;
				s_stats_sampling_pkt->forwarder_id = forwarder_id;
				s_stats_sampling_pkt->hops = hops;
				s_stats_sampling_pkt->min = min;
				s_stats_sampling_pkt->max = max;
				s_stats_sampling_pkt->average = average;
				s_stats_sampling_pkt->destination_id = destination_id;
				s_stats_sampling_pkt->sequence_number = sequence_number;
				s_stats_sampling_pkt->mode = 1;

				start = 0;
				while(start < LAST_SENDERS) {
					if (ContributedNodes[start].node_id == 0) {
						ContributedNodes[start].node_id = TOS_NODE_ID;
						break;
					}
					start++;
				}
				memcpy(s_stats_sampling_pkt->contributed_ids, ContributedNodes, LAST_SENDERS * sizeof(nx_uint8_t));
	
				if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (stats_sampling_msg_t)) == SUCCESS){
					dbg("BroadcastingC", "Start sending serial packet\n\n ");
					serial_busy = TRUE;
				}
			}
		}
	}
/* ------------------------------- Query Canceling -------------------------------- */
	task void QueryCancel() {
		if (HoldTimer == query_cancel) {
			checkTimer = call TimerQueryFired.getNow();
			runningTime = checkTimer - timerStartAt;
			AQQ[query_cancel].query_lifetime = runningTime;			/* krata to running time etsi wste na na upologiseis thn diafora xronoy apo ta alla queries sthn oura */
			call TimerQueryFired.stop();
			call TimerQueryFired.startOneShot(10);
		}
		else {
			AQQ[query_cancel].state = 0;
		}

		if (call TimerQueryBroadcast.isRunning() == TRUE) {
			t0 = call TimerQueryBroadcast.gett0();
			dt = call TimerQueryBroadcast.getdt();
			call TimerQueryBroadcast.startOneShot(t0 + dt);
		}
		else {
			call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 30);
		}
	}

	task void QueryCancelConfirmation() {
		if (!unicast_busy) {
			ucast_query_cancel = (query_cancel_msg_t*) (call SamplingAMPacket.getPayload(&pkt, sizeof (query_cancel_msg_t)));
			if (ucast_query_cancel == NULL) {
				return;
			}

			ucast_query_cancel->source_id = AQQ[query_cancel].source_id;
			ucast_query_cancel->sequence_number = AQQ[query_cancel].sequence_number;
			ucast_query_cancel->propagation_mode = 2;
			ucast_query_cancel->forwarder_id = TOS_NODE_ID;

			if (call SamplingRadioAMSend.send(send_qcancelTo_node /*AQQ[query_cancel].father_node */, &pkt, sizeof (sampling_msg_t)) == SUCCESS){
				unicast_busy = TRUE;
				call Leds.led2On();
			}
		}
	}

	task void FindQueryAndSend() {
		query_pos = 0;
		while (query_pos < NUMBER_OF_QUERIES) {
			if (AQQ[query_pos].state == 1) {
				//sampling_save = sampling_save%SIZE;
				ucast_ReUpd = (response_update_msg_t*) (call SamplingAMPacket.getPayload(&/*SamplingPacketBuffer[sampling_save]*/pkt, sizeof (response_update_msg_t)));
				if (ucast_ReUpd == NULL) {
					return;
				}
				//sampling_save++;

				ucast_ReUpd->source_id = AQQ[query_pos].source_id;
				ucast_ReUpd->sequence_number = AQQ[query_pos].sequence_number;
				ucast_ReUpd->forwarder_id = TOS_NODE_ID;
				ucast_ReUpd->father_node = AQQ[query_pos].father_node;
				ucast_ReUpd->hops = AQQ[query_pos].hops;
				ucast_ReUpd->sampling_period = AQQ[query_pos].sampling_period;
				ucast_ReUpd->query_lifetime = AQQ[query_pos].query_lifetime;
				ucast_ReUpd->propagation_mode = AQQ[query_pos].propagation_mode;
				//ucast_ReUpd->rest_of_time_period = TimeToMeasure[query_pos]; 
				mode = 4;

				if (AQQ[query_pos].propagation_mode == 1) {
					checkTimer = call TimerReadSensor.getNow();
					dt = checkTimer - time4MeasurementStartAt;
					ucast_ReUpd->rest_of_time_period = TimeToMeasure[query_pos] - dt;
				}

				checkTimer = call TimerQueryFired.getNow(); /*calculate and send the remaing query lifetime*/
				dt = checkTimer - timerStartAt;
				ucast_ReUpd->query_lifetime  = AQQ[query_pos].query_lifetime - dt;

				call Leds.led2On();
				if (!unicast_busy) {
					if (call SamplingRadioAMSend.send(new_entry_node, &pkt, sizeof (response_update_msg_t)) == SUCCESS){
						unicast_busy = TRUE;
						//call Leds.led2On();
					}
				}
			}
			query_pos++;
		}
	}

/* --------------------------------------------------------- BOOTED -------------------------------------------------------- */		
	event void Boot.booted() {
		
		send = 0;
		save = 0;
		next = 0;
		data_id = 0;
		query_pos = 0;
		nextChild = 0;
		sampling_save = 0;
		sampling_send = 0;
		sequence_number = 0;
		number_Of_queries = 0;
		count_received_children = 0;

		call Leds.led0Off();
		call Leds.led1Off();
		call Leds.led2Off();

		post init_StateMessages();
		post init_ActiveQueryQ();
		post init_ContributedNodes();
		post init_Apps_Queue();

		call RadioAMControl.start();
		call SerialAMControl.start();
	}
	
/* ------------------------------------------------- RADIO CONTROL ---------------------------------------------------------- */	
	event void RadioAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "RADIO_CONTROL = OK %s.\n", sim_time_string());
			save = save%SIZE;
			upd_bcast = (update_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (update_msg_t) ));
			if (upd_bcast == NULL) {
				return;
			}
			save++;

			upd_bcast->node_id = TOS_NODE_ID;
			upd_bcast->propagation_mode = 3;								/*Propagation_mode = 3 means that is discover broadcast.*/
			mode = 3;
			call Leds.led2On();
			call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 30);			/* When boot, send a bcast messaage to learn the network state.*/
		}
		else {
			call RadioAMControl.start();
		}
	}
	
	event void RadioAMControl.stopDone(error_t err) { /* do nothing */ }

/* ---------------------------------------------------- SERIAL CONTROL ------------------------------------------------------- */
	event void SerialAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "SERIAL_CONTROL = OK %s.\n", sim_time_string());
		}
		else {
			call SerialAMControl.start();
		}
	}
	
	event void SerialAMControl.stopDone(error_t err) { /* do nothing */ }

/* -------------------------------------------------------- TimerApplications ------------------------------------------------------------------ */
	event void TimerApplications.fired() {

		/*The current application that holding the timer, is going to get the controller. */
		//if (appHoldingController != appHoldingTimer) { 
		//	Apps_Queue[appHoldingController].pc = pc;
		//}

		appHoldingController = appHoldingTimer;
		count_instructions = 0; 

		maxInterpreterIterations = Apps_Queue[appHoldingController].BinaryMessage[0];										//refresh the maxInterpretations of this application
		Apps_Queue[appHoldingController].pc = Apps_Queue[appHoldingController].BinaryMessage[0] - Apps_Queue[appHoldingController].BinaryMessage[2];		//refresh where the pc points in this application
		Apps_Queue[appHoldingController].TimerCalled = FALSE;
		

		j=0;
		minQuery = 0;
		while (j < MAX_APPLICATIONS) {
			if (Apps_Queue[j].state == 1 && j != appHoldingController) {
				minQuery = j;
				break;
			}
			j++;
		}

		j=0;
		while (j < MAX_APPLICATIONS) {
			if (Apps_Queue[j].state == 1 && j != appHoldingController && Apps_Queue[j].TimerCalled == TRUE) {
				Apps_Queue[j].TimerRemainingTime -= Apps_Queue[appHoldingController].TimerRemainingTime;
				if (Apps_Queue[j].TimerRemainingTime <= Apps_Queue[minQuery].TimerRemainingTime &&  Apps_Queue[j].TimerRemainingTime != 0) {
					minQuery = j;
				}
			}
			j++;
		}
		Apps_Queue[appHoldingController].TimerRemainingTime = 0;
		appHoldingTimer = minQuery;

		if (Apps_Queue[appHoldingTimer].TimerRemainingTime > 0 && Apps_Queue[appHoldingTimer].TimerCalled == TRUE) {
			//Apps_Queue[appHoldingTimer].TimerCalled = TRUE;
			call TimerApplications.startOneShot(Apps_Queue[appHoldingTimer].TimerRemainingTime);
			timerApplicationStartAt = call TimerApplications.getNow();
		}
		post Interpretation();
		
	}

/* -------------------------------------------- TimerQueryBroadcast =>  SOURCE QUERY BROADCAST ------------------------------------------------- */ 	
	event void TimerQueryBroadcast.fired() {
		/** if i am the query message source then save that info to SH the array SendersHistory is used to remember the last 5 last
		  * nodes that send a query, in order to recognize the new message.
		  */
		if (TOS_NODE_ID == bcast_pkt->source_id) {
			start = 0;
			query_pos = 0;
			while (start < LAST_SENDERS) {
				if (QuerySendersHistory[start].source_id == TOS_NODE_ID) {
					QuerySendersHistory[start].sequence_number = bcast_pkt->sequence_number;
					query_pos++;
					break;
				}
				start++;
			}
			if (query_pos == 0) {
				next = next % LAST_SENDERS;
				QuerySendersHistory[next].source_id = bcast_pkt->source_id;
				QuerySendersHistory[next].sequence_number = bcast_pkt->sequence_number;
				next++;
			}
		}

		if (!busy) {
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			if (mode == 3) {																				/*mode = 3 update bcast */
				if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (update_msg_t)) == SUCCESS){
					busy = TRUE;
					call Leds.led1On();
				}
			}
			else if (/*bcast_pkt->propagation_mode*/ mode == 2) {
				call TimerQueryCancelResponse.startOneShot(AQQ[query_cancel].WaitingTime);				/*Waiting upper bound before resending the query cancel */

				if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_cancel_msg_t)) == SUCCESS){
					busy = TRUE;
					call Leds.led1On();
				}
			}
			else {
				if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){
					busy = TRUE;
					call Leds.led1On();
				}
			}		
		}
	}
/* -------------------- TimerQueryCancelResponse =>  WAITING UPPER BOUND TIME,TO CHECK WHO SEND CANCEL RESPONSE ---------------------- */ 
	event void TimerQueryCancelResponse.fired() {
		query_pos = 0;
		start=0;
		while (query_pos < LAST_SENDERS) {
			if (AQQ[query_cancel].children[query_pos] != 0){
				send_qcancelTo_node = AQQ[query_cancel].children[query_pos];
				AQQ[query_cancel].children[query_pos] = 0;
				post QueryCancelConfirmation();
				//break;
			}
			query_pos++;
		}
	}

/* -------------------------------------- TimerCacheDataSensor =>  Deactivete the sensor value ---------------------------------------- */ 	
	//event void TimerCacheDataSensor.fired() {
	//	post Interpretation();
	//}

/* -------------------------------------- TimerReadSensor =>  START READING VALUES FROM SENSOR ---------------------------------------- */ 	
	event void TimerReadSensor.fired() {	
		/* initiate read op */
		call Read.read(); 
		/* if the state == 0 then the query has expired */
		if (AQQ[Hold_Sampling_Timer].state == 0) {
			call TimerReadSensor.stop();
		}
	
	}

/* --------------------------------------------------- READ VALUES DONE, SO SEND ------------------------------------------------------ */
	event void Read.readDone(error_t result, uint16_t data) {
		if (result == SUCCESS) {
			sensor_data = data;
			j=0;
			while (j < MAX_APPLICATIONS) {
				if(Apps_Queue[j].RegisterReadSensor != 0) {
					i = Apps_Queue[j].RegisterReadSensor;
					Apps_Queue[j].registers[--i] = sensor_data;
					Apps_Queue[j].RegisterReadSensor = 0;
				}
				j++;
			}
			
			//call TimerCacheDataSensor.startOneShot(10000);		/*Cache data for 1 minute.*/
			post Interpretation();
		}
//		if(result == SUCCESS){
//			/** Save what query we are handling */
//			remindQuery = Hold_Sampling_Timer;
//
//			/* IF i am the query originator */
//			if (TOS_NODE_ID == AQQ[Hold_Sampling_Timer].source_id) {
//				source_id = TOS_NODE_ID;
//				s_data_id = data_id;
//				forwarder_id = TOS_NODE_ID;
//							/*  . . .  */   	/* independs on the propagation_mode */
//				destination_id = AQQ[Hold_Sampling_Timer].source_id;
//				sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;
//				sampling_id = AQQ[Hold_Sampling_Timer].sampling_id++;			/*new*/
//
//				if (AQQ[Hold_Sampling_Timer].propagation_mode == 0) {  // SIMPLE mode == 0
//					sensor_data = data;
//					mode = 0;
//
//					call TimerSendPCSerial.startOneShot(20);  // to serial send valto kalutera se ena task
//				}
//				else if (AQQ[Hold_Sampling_Timer].propagation_mode == 1) { // STATS mode == 1
//					hops = AQQ[Hold_Sampling_Timer].hops;
//					min = data;
//					max = data;
//					average = data;
//					//stats_ucast_pkt->contributed_ids[0] = TOS_NODE_ID;
//					mode = 1;
//
//					post DelayMeasurementScheduling();
//				}		
//			}
//			else { /* ELSE IF  MIDDLE NODE, then read and forward the values */ 
//				
//				/** My Father Node is the one who send me the query bcast, so i will forward the measurements back to him */
//				sendTofather = AQQ[Hold_Sampling_Timer].forwarder_id;	 
//
//				if (AQQ[Hold_Sampling_Timer].propagation_mode == 0) {  // SIMPLE mode == 0
//					sampling_save = sampling_save%SIZE;
//					ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
//					if (ucast_pkt == NULL) {
//						return;
//					}
//					sampling_save++;
//
//					ucast_pkt->source_id = TOS_NODE_ID;
//					ucast_pkt->sampling_id = AQQ[Hold_Sampling_Timer].sampling_id++;		/*new*/
//					ucast_pkt->data_id = data_id;
//					ucast_pkt->forwarder_id = TOS_NODE_ID;
//					ucast_pkt->sensor_data = data;
//					ucast_pkt->destination_id = AQQ[Hold_Sampling_Timer].source_id;
//					ucast_pkt->sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;
//					ucast_pkt->mode = 0;
//					mode = 0;
//					
//					call Timer_StatsUnicast_Unicast.startOneShot(TOS_NODE_ID * 20);  					   // Timer for Unicast Message - TOS_NODE_ID * 20				
//				}
//				else if (AQQ[Hold_Sampling_Timer].propagation_mode == 1) { // STATS mode == 1
//
//					stats_sampling_save = stats_sampling_save%SIZE;
//					stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_save], sizeof (stats_sampling_msg_t)));
//					if (stats_ucast_pkt == NULL) {
//						return;
//					}
//					stats_sampling_save++;
//
//					stats_ucast_pkt->source_id = TOS_NODE_ID;
//					stats_ucast_pkt->data_id = data_id;
//					stats_ucast_pkt->forwarder_id = TOS_NODE_ID;
//					stats_ucast_pkt->hops = AQQ[Hold_Sampling_Timer].hops;
//					stats_ucast_pkt->min = data;
//					stats_ucast_pkt->max = data;
//					stats_ucast_pkt->average = data;
//					stats_ucast_pkt->destination_id = AQQ[Hold_Sampling_Timer].source_id;
//					stats_ucast_pkt->sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;
//					stats_ucast_pkt->mode = 1;
//					mode = 1;//AQQ[Hold_Sampling_Timer].propagation_mode;
//
//					min = data;
//					max = data;
//					average = data;
//					post DelayMeasurementScheduling();
//				}
//			}
//			data_id++;
//			
//			if (number_Of_queries > 0) {
//			
//				expiredQuery = Hold_Sampling_Timer; // this points to the expired query sampling period
//				runningTime = TimeToMeasure[expiredQuery];
//				minPeriod = 0;
//				start = 0;	
//				while(start < NUMBER_OF_QUERIES) {
//					if (AQQ[start].state == 1) {
//						if (start == expiredQuery) {
//							TimeToMeasure[start] = AQQ[start].sampling_period; // if finished, initialize again the sampling period
//						}
//						else {
//							TimeToMeasure[start] = TimeToMeasure[start] - runningTime;
//						}
//
//						if (TimeToMeasure[start] <= TimeToMeasure[minPeriod] && TimeToMeasure[start] != 0) {	/*find the min but exclude the 0 time */
//							Hold_Sampling_Timer = start;
//						}
//					}
//					else {
//						minPeriod++; // if in first positions there is no active query,then move on and minPeriod moves on too
//					}
//					start++;
//				}
//
//				call TimerReadSensor.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
//				time4MeasurementStartAt = call TimerReadSensor.getNow();
//			}
//		}
	}

/* ----------------------------------------- TimerSendPCSerial => SERIAL SEND : MOTE -> PC -------------------------------------------- */ 
	event void TimerSendPCSerial.fired() {
		post SendSerial();
		count_received_children = 0;

		if (number_Of_queries > 1) {  /*>1 because if we have one query it is neccessary*/
			start = 0;
			minPeriod = 0;
			while (start < NUMBER_OF_QUERIES) {
				if (start == 0) {
					while (minPeriod < NUMBER_OF_QUERIES && AQQ[minPeriod].state == 0) {
						minPeriod++;
					}
				}
				if (AQQ[start].state == 1) {
					AQQ[start].RemaingTime -= AQQ[Hold_Waiting_Timer].RemaingTime;
					if (AQQ[start].RemaingTime <= AQQ[minPeriod].RemaingTime && AQQ[start].RemaingTime != 0) {
						minPeriod = start;
					}
				}
				start++;
			}

			if (minPeriod != Hold_Waiting_Timer) {
				Hold_Waiting_Timer = minPeriod;
				call TimerSendPCSerial.startOneShot(AQQ[Hold_Waiting_Timer].RemaingTime);
				AQQ[Hold_Waiting_Timer].startDelay = call TimerSendPCSerial.getNow();
			}
		}
	}

/* ------------------------------------------- TimerQueryFired => Query_Lifetime END -------------------------------------------------- */ 
	event void TimerQueryFired.fired() {
		dbg("QueryC", "The query_%hu expired! @ %s", sim_time_string());
		/*Disable the expired query*/
		number_Of_queries--;
		AQQ[HoldTimer].state = 0;
		//AQQ[HoldTimer].sampling_id = 0; 

		if (number_Of_queries > 0) {
			expiredQuery = HoldTimer;
			minQuery = 0;
			query_pos = 0;
			while (query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].state == 1) {
					AQQ[query_pos].query_lifetime -= AQQ[expiredQuery].query_lifetime;
					if (AQQ[query_pos].query_lifetime <= AQQ[minQuery].query_lifetime && AQQ[query_pos].query_lifetime != 0) {
						HoldTimer = query_pos;
					}
				}
				else {
					minQuery++;
				}
				query_pos++;
			}			
			call TimerQueryFired.startOneShot(AQQ[HoldTimer].query_lifetime);
			timerStartAt = call TimerQueryFired.getNow();
		}
		else {
			call Leds.led0Off();
		}
	}

/* ---------------------------------------- TimerReUnicast => Re-UNICAST MEASUREMENTS --------------------------------------------- */
	event void TimerReUnicast.fired() {
		if (!unicast_busy) {
			ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_send], sizeof (sampling_msg_t)));
			if (ucast_pkt == NULL) {
				return;
			}

			memcpy(&pkt, &SamplingPacketBuffer[sampling_send], sizeof(message_t));

			if (call SamplingRadioAMSend.send(sendTofather, &pkt, sizeof (sampling_msg_t)) == SUCCESS){
				unicast_busy = TRUE;
				call Leds.led2On();
			}
		}
	} 

/* ---------------------------------------- Timer_StatsUnicast_Unicast => UNICAST MEASUREMENTS --------------------------------------------- */
	event void Timer_StatsUnicast_Unicast.fired() {
		if (!unicast_busy) {
			if (/*AQQ[remindQuery].propagation_mode*/mode == 0) {
				ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_send], sizeof (sampling_msg_t)));
				if (ucast_pkt == NULL) {
					return;
				}

				memcpy(&pkt, &SamplingPacketBuffer[sampling_send], sizeof(message_t));

				if (call SamplingRadioAMSend.send(sendTofather, &pkt, sizeof (sampling_msg_t)) == SUCCESS){
					unicast_busy = TRUE;
					call Leds.led2On();
				}
			}
			else if (/*AQQ[remindQuery].propagation_mode*/mode == 1) {
				count_received_children = 0;	/*init the counter for the next ucast transmission */
				stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_send], sizeof (stats_sampling_msg_t)));
				if (stats_ucast_pkt == NULL) {
					return;
				}

				start = 0;
				while(start < LAST_SENDERS) {
					if (ContributedNodes[start].node_id == 0) {
						ContributedNodes[start].node_id = TOS_NODE_ID;
						break;
					}
					start++;
				}
				memcpy(stats_ucast_pkt->contributed_ids, ContributedNodes, LAST_SENDERS * sizeof(nx_uint8_t));


				memcpy(&pkt, &StatsSamplingPacketBuffer[stats_sampling_send], sizeof(message_t));

				if (call SamplingRadioAMSend.send(sendTofather, &pkt, sizeof (stats_sampling_msg_t)) == SUCCESS){
					unicast_busy = TRUE;
					call Leds.led2On();
				}
			}
		}
	}

/* ----------------------------------------- SAMPLING RADIO RECEIVE MESSAGES ------------------------------------------------ */
	event message_t* SamplingRadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(sampling_msg_t)) {					/** RECEIVE SIMPLE SAMPLING MESSAGE **/
			r_sampling_pkt = (sampling_msg_t*) payload;

			/** If i receive a msg and i am the MIDDLE node then i will re-unicast the msg to my father. */
			if (r_sampling_pkt->destination_id != TOS_NODE_ID) {

				sampling_save = sampling_save%SIZE;
				ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
				if (ucast_pkt == NULL) {
					return;
				}
				sampling_save++;	

				ucast_pkt->source_id = r_sampling_pkt->source_id;
				ucast_pkt->sampling_id = r_sampling_pkt->sampling_id;   /*new*/
				ucast_pkt->data_id = r_sampling_pkt->data_id;
				ucast_pkt->forwarder_id = TOS_NODE_ID;
				ucast_pkt->sensor_data = r_sampling_pkt->sensor_data;
				ucast_pkt->destination_id = r_sampling_pkt->destination_id;
				ucast_pkt->sequence_number = r_sampling_pkt->sequence_number;
				ucast_pkt->mode = 0;
				mode = 0;
				
				query_pos = 0;
				while (AQQ[query_pos].source_id != r_sampling_pkt->destination_id && AQQ[query_pos].sequence_number != r_sampling_pkt->sequence_number && query_pos < NUMBER_OF_QUERIES) {
					query_pos++;
				}
				if (query_pos < NUMBER_OF_QUERIES) {
					sendTofather = AQQ[query_pos].forwarder_id;
				}
				
				call TimerReUnicast.startOneShot(TOS_NODE_ID * 20); // Re-Unicast the received sampling packet - TOS_NODE_ID * 20
			}
			else {  /* if i am the one who send the query (TOS_NODE_ID == destination_id )then call TimerSendPCSerial to print the values*/
				source_id = r_sampling_pkt->source_id;
				sampling_id = r_sampling_pkt->sampling_id;
				s_data_id =  r_sampling_pkt->data_id;
				forwarder_id = r_sampling_pkt->forwarder_id;
				sensor_data = r_sampling_pkt->sensor_data;
				destination_id = r_sampling_pkt->destination_id;
				sequence_number = r_sampling_pkt->sequence_number;
				mode = 0;

				call TimerSendPCSerial.startOneShot(20);
			}
		} 
		else if (len == sizeof(stats_sampling_msg_t)) {				/** RECEIVE STATS SAMPLING MESSAGE */
			r_stats_sampling_pkt = (stats_sampling_msg_t*) payload;
			count_received_children++;

			if (min > r_stats_sampling_pkt->min) {
				min = r_stats_sampling_pkt->min;
			}
			if (max < r_stats_sampling_pkt->max) {
				max = r_stats_sampling_pkt->max;
			}

			query_pos = 0;
			while (query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].source_id == r_stats_sampling_pkt->destination_id && AQQ[query_pos].sequence_number == r_stats_sampling_pkt->sequence_number) {
					average = (max + min) / (count_received_children+1);		// false --> if the topology is tree???
					sendTofather = AQQ[query_pos].forwarder_id;		/** Save the father node */
					break;
				}
				query_pos++;
			}
			/** If MIDDLE NODE then RE-UNICAST to my father. */
			if (r_stats_sampling_pkt->destination_id != TOS_NODE_ID) {

				//stats_sampling_save = stats_sampling_save%SIZE;
				stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_send], sizeof (stats_sampling_msg_t)));
				if (stats_ucast_pkt == NULL) {
					return;
				}
				//stats_sampling_save++;
	 
				stats_ucast_pkt->source_id = r_stats_sampling_pkt->source_id;
				stats_ucast_pkt->data_id = r_stats_sampling_pkt->data_id;
				stats_ucast_pkt->forwarder_id = TOS_NODE_ID;
				stats_ucast_pkt->hops = r_stats_sampling_pkt->hops;
				stats_ucast_pkt->min = min;
				stats_ucast_pkt->max = max;
				stats_ucast_pkt->average = average;
				stats_ucast_pkt->destination_id = r_stats_sampling_pkt->destination_id;
				stats_ucast_pkt->sequence_number = r_stats_sampling_pkt->sequence_number;
				mode = 1;

				start = 0;
				i = 0;
				while (start < LAST_SENDERS) {
					if (ContributedNodes[start].node_id == 0) {
						ContributedNodes[start].node_id = r_stats_sampling_pkt->contributed_ids[i];
						i++;
					}
					start++;
				}
				stats_ucast_pkt->mode = 1;

				dtDelay = call Timer_StatsUnicast_Unicast.getNow();
				AQQ[query_pos].WaitingTime = dtDelay - AQQ[query_pos].startDelay;	/** query_pos calculate above and points to the query in whice we receive the measurement ucast.*/
				AQQ[query_pos].RemaingTime = AQQ[query_pos].WaitingTime;

				/*If i got msg from all my children, stop the timer and procceed to ucast transmission*/
				if (count_received_children == AQQ[query_pos].number_of_children) { 
					call Timer_StatsUnicast_Unicast.stop();
					call Timer_StatsUnicast_Unicast.startOneShot(20);
				}

			}
			else { 			/*If ORIGINATOR NODE, then send to serial*/
				source_id = r_stats_sampling_pkt->source_id;
				s_data_id =  r_stats_sampling_pkt->data_id;
				forwarder_id = r_stats_sampling_pkt->forwarder_id;
				destination_id = r_stats_sampling_pkt->destination_id;
				sequence_number = r_stats_sampling_pkt->sequence_number;
				mode = 1;

				start = 0;
				i = 0;
				while (start < LAST_SENDERS) {
					if (ContributedNodes[start].node_id == 0) {
						ContributedNodes[start].node_id = r_stats_sampling_pkt->contributed_ids[i];
						i++;
					}
					start++;
				}

				dtDelay = call TimerSendPCSerial.getNow();
				AQQ[query_pos].WaitingTime = dtDelay - AQQ[query_pos].startDelay + 200; /** query_pos calculate above and points to the query in whice we receive the measurement ucast.*/
				AQQ[query_pos].RemaingTime = AQQ[query_pos].WaitingTime;

				/*If i got msg from all my children, stop the timer and procceed to serial transmission*/
				if (count_received_children == AQQ[query_pos].number_of_children) { 
					call TimerSendPCSerial.stop();
					call TimerSendPCSerial.startOneShot(200);
				}
			}
		}
		else if (len == sizeof(query_cancel_msg_t)) {					/*RECEIVE QUERY CANCEL MESSAGE*/
			rcv_query_cacnel = (query_cancel_msg_t*) payload;

			query_pos = 0;
			while (query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].source_id == rcv_query_cacnel->source_id && AQQ[query_pos].sequence_number == rcv_query_cacnel->sequence_number){
					start = 0;
					while (start < LAST_SENDERS){
						if (AQQ[query_pos].children[start] == rcv_query_cacnel->forwarder_id) {
							AQQ[query_pos].children[start] = 0;
							break;
						}
						start++;
					}
				}	
			}
		}
		else if (len == sizeof(response_update_msg_t)) {				/*RECEIVE RESPONSE UPDATE FROM THE NETWORK.*/
			ucast_ReUpd = (response_update_msg_t*) payload;
			call Leds.led1On();
			/* Check if i have already taken a query message from this source_id */
			query_pos = 0;
			while (query_pos < LAST_SENDERS && QuerySendersHistory[query_pos].source_id != r_pkt->source_id) {
				query_pos++;
			}

			/** If reached the end of the array,means that it is the first time receving a query message from that source_id. */
			if (query_pos == LAST_SENDERS) { 
				next = next%LAST_SENDERS;
				QuerySendersHistory[next].sequence_number = 0;
				QuerySendersHistory[next].source_id = ucast_ReUpd->source_id;
				query_pos = next;
			}

			/** I found that the source_id and now i check the sequence number to define if it is a unique msg. */
			if (ucast_ReUpd->sequence_number > QuerySendersHistory[query_pos].sequence_number &&  query_pos < LAST_SENDERS) { // query_pos < LS is unnecessary
				next++;
				QuerySendersHistory[query_pos].sequence_number = ucast_ReUpd->sequence_number;

				if (number_Of_queries < NUMBER_OF_QUERIES) {
					number_Of_queries++;

					dbg("ReceiveC", "NEW QUERY \n");

					query_pos = 0;
					while(AQQ[query_pos].state == 1 && query_pos < NUMBER_OF_QUERIES) {
						query_pos++;
					}

					if (query_pos < NUMBER_OF_QUERIES){
						AQQ[query_pos].source_id = ucast_ReUpd->source_id; 
						AQQ[query_pos].sequence_number = ucast_ReUpd->sequence_number;
						AQQ[query_pos].forwarder_id = ucast_ReUpd->forwarder_id; // father
						AQQ[query_pos].father_node = ucast_ReUpd->forwarder_id;
						AQQ[query_pos].hops = ucast_ReUpd->hops + 1;
						AQQ[query_pos].sampling_period = ucast_ReUpd->sampling_period;
						AQQ[query_pos].query_lifetime = ucast_ReUpd->query_lifetime;
						AQQ[query_pos].propagation_mode = ucast_ReUpd->propagation_mode;
						AQQ[query_pos].WaitingTime = OFFSET;
						AQQ[query_pos].RemaingTime = OFFSET;
						AQQ[query_pos].state = 1;
					} 
					
					sendQuery = query_pos;
					post QueryScheduling();

					TimeToMeasure[sendQuery] = ucast_ReUpd->rest_of_time_period;
					post MeasurementScheduling();

					save = save%SIZE;
					bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
					if (bcast_pkt == NULL) {
						return;
					}
					save++;

					bcast_pkt->source_id = AQQ[sendQuery].source_id;
					bcast_pkt->sequence_number = AQQ[sendQuery].sequence_number;
					bcast_pkt->forwarder_id = TOS_NODE_ID;
					bcast_pkt->father_node = AQQ[sendQuery].father_node;
					bcast_pkt->hops = AQQ[sendQuery].hops;
					bcast_pkt->sampling_period = AQQ[sendQuery].sampling_period;
					bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
					bcast_pkt->propagation_mode = AQQ[sendQuery].propagation_mode;
					/*____*/
					mode = AQQ[sendQuery].propagation_mode;
				}															/*else if receive a same response message.*/
				else if (ucast_ReUpd->sequence_number == QuerySendersHistory[query_pos].sequence_number && query_pos < NUMBER_OF_QUERIES) {
					start = 0;									/*if it exists in my system.*/
					while (start < NUMBER_OF_QUERIES) {
						if (AQQ[start].source_id == ucast_ReUpd->source_id && AQQ[start].sequence_number == ucast_ReUpd->sequence_number){
							if (ucast_ReUpd->hops + 1 < AQQ[start].hops) {
								AQQ[start].hops = ucast_ReUpd->hops + 1;
								AQQ[start].father_node = ucast_ReUpd->forwarder_id;
							}
						}
					}
				}
			}
		}
		return msg;
	}

/* ------------------------------------------- QUERY RADIO RECEIVE MESSAGES ------------------------------------------------- */
	event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(query_flooding_msg_t)) {
			r_pkt = (query_flooding_msg_t*) payload;

			/* Check if i have already taken a query message from this source_id */
			query_pos = 0;
			while (query_pos < LAST_SENDERS && QuerySendersHistory[query_pos].source_id != r_pkt->source_id) {
				query_pos++;
			}

			/** If reached the end of the array,means that it is the first time receving a query message from that source_id. */
			if (query_pos == LAST_SENDERS) { 
				next = next%LAST_SENDERS;
				QuerySendersHistory[next].sequence_number = 0;
				QuerySendersHistory[next].source_id = r_pkt->source_id;
				query_pos = next;
			}

			/** I found that the source_id and now i check the sequence number to define if it is a unique msg. */
			if (r_pkt->sequence_number > QuerySendersHistory[query_pos].sequence_number &&  query_pos < LAST_SENDERS) { // query_pos < LS is unnecessary
				next++;
				QuerySendersHistory[query_pos].sequence_number = r_pkt->sequence_number;

				if (number_Of_queries < NUMBER_OF_QUERIES) {
					number_Of_queries++;

					dbg("ReceiveC", "NEW QUERY \n");

					query_pos = 0;
					while(AQQ[query_pos].state == 1 && query_pos < NUMBER_OF_QUERIES) {
						query_pos++;
					}

					if (query_pos < NUMBER_OF_QUERIES){
						AQQ[query_pos].source_id = r_pkt->source_id; 
						AQQ[query_pos].sequence_number = r_pkt->sequence_number;
						AQQ[query_pos].sampling_id = 0;
						AQQ[query_pos].forwarder_id = r_pkt->forwarder_id; // father
						AQQ[query_pos].father_node = r_pkt->forwarder_id;
						AQQ[query_pos].hops = r_pkt->hops + 1;
						AQQ[query_pos].sampling_period = r_pkt->sampling_period;
						AQQ[query_pos].query_lifetime = r_pkt->query_lifetime;
						AQQ[query_pos].propagation_mode = r_pkt->propagation_mode;
						AQQ[query_pos].WaitingTime = OFFSET;
						AQQ[query_pos].RemaingTime = OFFSET;
						AQQ[query_pos].state = 1;
					} 
					
					sendQuery = query_pos;
					post QueryScheduling();

					TimeToMeasure[sendQuery] = AQQ[sendQuery].sampling_period;
					post MeasurementScheduling();

					save = save%SIZE;
					bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
					if (bcast_pkt == NULL) {
						return;
					}
					save++;

					bcast_pkt->source_id = AQQ[sendQuery].source_id;
					bcast_pkt->sequence_number = AQQ[sendQuery].sequence_number;
					bcast_pkt->forwarder_id = TOS_NODE_ID;
					bcast_pkt->father_node = AQQ[sendQuery].father_node;
					bcast_pkt->hops = AQQ[sendQuery].hops;
					bcast_pkt->sampling_period = AQQ[sendQuery].sampling_period;
					bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
					bcast_pkt->propagation_mode = AQQ[sendQuery].propagation_mode;
					/*____*/
					mode = AQQ[sendQuery].propagation_mode;
				}	
			} /** If i have reveived that msg before, i try to find if this msg belongs to a child node */
			else if (r_pkt->sequence_number == QuerySendersHistory[query_pos].sequence_number && query_pos < NUMBER_OF_QUERIES) {
				/* Find if that query is active on my system and check if the node that send that message has hop number bigger than mine.*/
				start = 0;
				while (start < NUMBER_OF_QUERIES) {
					if (AQQ[start].source_id == r_pkt->source_id && AQQ[start].sequence_number == r_pkt->sequence_number && AQQ[start].hops == r_pkt->hops -1){
						if (r_pkt->father_node == TOS_NODE_ID) {	/* if this node that send me a bcast, has chosen me as his father, then save him in my child list. */
							AQQ[start].WaitingTime = AQQ[start].sampling_period - 1000 ;				/*And set for that query an upper bound for waiting time. */
							AQQ[start].RemaingTime = AQQ[start].WaitingTime;
							AQQ[start].number_of_children++;
							nextChild = nextChild%LAST_SENDERS;
							AQQ[start].children[nextChild] = r_pkt->forwarder_id;
							nextChild++;
						} 
						break;
					}
					start++;
				}
			}
		}
		else if (len == sizeof(query_cancel_msg_t)) {
			rcv_query_cacnel = (query_cancel_msg_t*) payload;

			if (number_Of_queries > 0) {
				query_pos = 0;
				while (query_pos < NUMBER_OF_QUERIES) {
					if (AQQ[query_pos].source_id == rcv_query_cacnel->source_id && AQQ[query_pos].sequence_number == rcv_query_cacnel->sequence_number && AQQ[query_pos].state == 1) {
						query_cancel = query_pos;
						break;
					}
					query_pos++;
				}
			}
			post QueryCancel();  			/* task to find the query and cancel its operation */

			save = save%SIZE;
			bcast_query_cancel = (query_cancel_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_cancel_msg_t) ));
			if (bcast_query_cancel == NULL) {
				return;
			}
			save++;

			bcast_pkt->source_id = rcv_query_cacnel->source_id;
			bcast_pkt->sequence_number = rcv_query_cacnel->sequence_number;
			bcast_pkt->propagation_mode = rcv_query_cacnel->propagation_mode;
			bcast_pkt->forwarder_id = TOS_NODE_ID;								/*who is sending the broadcast */

			mode = 2;

			send_qcancelTo_node = AQQ[query_cancel].father_node;
			post QueryCancelConfirmation();			/* Give a response to the father node that send you the query cancelation */
		}
		else if (len == sizeof(update_msg_t)) {				/*UPDATE NEW NODE ENTRY MESSAGE*/
			rcv_bcast_upd = (update_msg_t*) payload;

			new_entry_node = rcv_bcast_upd->node_id;
			if (number_Of_queries > 0) {
				call Leds.led2On();
				post FindQueryAndSend();	
			}
			
		}
		return msg;
	}

/* -------------------------------------------- QUERY SERIAL RECEIVE MESSAGE ------------------------------------------------------ */
	event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (binary_msg_t)) {
			s_pkt = (binary_msg_t*) payload;

			if (number_of_active_apps < MAX_APPLICATIONS) {
				number_of_active_apps++;											/*increase the number of active apps.*/
				sequence_number++; 													/* seq_num of that message. */

				start = 0;
				if (s_pkt->action == 0) {											/*Delete an application.*/
					while (start < MAX_APPLICATIONS) {
						if (Apps_Queue[start].state == 1 && Apps_Queue[start].app_id == s_pkt->app_id) {
							Apps_Queue[start].state = 0;
							if (s_pkt->app_id == 0) {
								call Leds.led1Off();
							}
							else { 
								call Leds.led2Off(); 
							}
							break;
						}
						start++;
					}
				}
				else if (s_pkt->action == 1) {

					while (start < MAX_APPLICATIONS) {
						if (Apps_Queue[start].state == 0) { 							/* run if you are new app ,until the end of the array to find a position into the system*/
							Apps_Queue[start].app_id = s_pkt->app_id;
							memcpy(Apps_Queue[start].BinaryMessage, s_pkt->BinaryMessage, 25 * sizeof(nx_uint8_t));
							Apps_Queue[start].state = 1;
							Apps_Queue[start].pc = 3; 									/** the Init handler always starts on the fourth position of BinaryMessage, that is 3*/
							maxInterpreterIterations = 3 + Apps_Queue[start].BinaryMessage[1];

							j=0;
							number_of_active_apps = 0;
							while (j < MAX_APPLICATIONS) {
								if (Apps_Queue[j].state == 1) { 						/*&& Apps_Queue[j].TimerCalled == TRUE && Apps_Queue[j].pc != 0x00*/
								 	number_of_active_apps++; 
								}
								j++;
							}

							if (number_of_active_apps == 1) {							/*Call interpreter, if only there is no other active application in the system.*/
								appHoldingController = start;							/*init*/
								count_instructions = 0;
								post Interpretation();
							}
							break;
						}

						start++;
					}	
				}		

				query_pos = 0;
				while(AQQ[query_pos].state == 1 && query_pos < MAX_APPLICATIONS) {
					query_pos++;
				}

				AQQ[query_pos].source_id = TOS_NODE_ID; 
				AQQ[query_pos].sequence_number = sequence_number;
				AQQ[query_pos].sampling_id = 0;
				AQQ[query_pos].forwarder_id = TOS_NODE_ID;
				AQQ[query_pos].father_node = TOS_NODE_ID;
				AQQ[query_pos].number_of_children = 0;
				AQQ[query_pos].hops = 0;
				AQQ[query_pos].sampling_period = s_pkt->sampling_period;
				AQQ[query_pos].query_lifetime = s_pkt->query_lifetime;
				AQQ[query_pos].propagation_mode = s_pkt->propagation_mode;
				AQQ[query_pos].WaitingTime = OFFSET;
				AQQ[query_pos].RemaingTime = OFFSET;
				AQQ[query_pos].state = 1;

				sendQuery = query_pos;
				post QueryScheduling();

				TimeToMeasure[sendQuery] = AQQ[sendQuery].sampling_period;			/* save the sampling period */
				post MeasurementScheduling();

				// configure the Broadcast
				save = save%SIZE;
				bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
				if (bcast_pkt == NULL) {
					return;
				}
				save++;

				bcast_pkt->source_id = AQQ[sendQuery].source_id;
				bcast_pkt->sequence_number = AQQ[sendQuery].sequence_number;
				bcast_pkt->forwarder_id = AQQ[sendQuery].forwarder_id;
				bcast_pkt->father_node = AQQ[sendQuery].father_node;
				bcast_pkt->hops = 0;//AQQ[sendQuery].hops;
				bcast_pkt->sampling_period = AQQ[sendQuery].sampling_period;
				bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
				bcast_pkt->propagation_mode = AQQ[sendQuery].propagation_mode;
				/*-----*/
				mode = AQQ[sendQuery].propagation_mode;
			}	
		}
		else if (len == sizeof(query_cancel_msg_t)) {
			srl_query_cancel = (query_cancel_msg_t*) payload;

			if (number_Of_queries > 0) {
				query_pos = 0;
				while (query_pos < NUMBER_OF_QUERIES) {
					if (AQQ[query_pos].source_id == srl_query_cancel->source_id && AQQ[query_pos].sequence_number == srl_query_cancel->sequence_number && AQQ[query_pos].state == 1) {
						query_cancel = query_pos;
						post QueryCancel();

						save = save%SIZE;
						bcast_query_cancel = (query_cancel_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_cancel_msg_t) ));
						if (bcast_query_cancel == NULL) {
							return;
						}
						save++;

						bcast_pkt->source_id = srl_query_cancel->source_id;
						bcast_pkt->sequence_number = srl_query_cancel->sequence_number;
						bcast_pkt->propagation_mode = srl_query_cancel->propagation_mode;
						bcast_pkt->forwarder_id = TOS_NODE_ID;
						mode = 2;
						break;
					}
					query_pos++;
				}
			}
		}
		
		return msg;
	}
	
/* ----------------------------------------------------- RADIO DONE  -------------------------------------------------------- */
	event void RadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;

			call Leds.led1Off(); // yellow
			call Leds.led2Off();
			send++;
			if (send > SIZE) {
				send = 0;
			}
		}		
	}

	event void SamplingRadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			unicast_busy = FALSE;

			call Leds.led2Off(); // blue
			if (AQQ[remindQuery].propagation_mode == 0) {
				sampling_send++;
				if (sampling_send > SIZE) {
					sampling_send = 0;
				}
			}
			else if (AQQ[remindQuery].propagation_mode == 1) {
				stats_sampling_send++;
				if (stats_sampling_send > SIZE) {
					stats_sampling_send = 0;
				}
			}	
			post init_ContributedNodes();
		}		
	}

/* ----------------------------------------------------- SERIAL DONE --------------------------------------------------------- */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;
		}
		post init_ContributedNodes();
	}

}