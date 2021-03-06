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
#define SIZE 20
#define NUMBER_OF_QUERIES 3
#define LAST_SENDERS 5
#define OFFSET 20
#define MAX_APPLICATIONS 2
#define CONTEXT_SWITCH_INSTRUCTIONS 3

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
	uses interface Timer<TMilli> as TimerCallingInterpretation;
	uses interface Timer<TMilli> as TimerConfigurePacket;
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
	//uint8_t maxInterpreterIterations;			/*Set the max interpretations for an application in order to avoid calculate them every time in a while-loop. Reduce the calculations but increase by 8-bit the memory.*/
	uint8_t appHoldingController;				/*Current Application that holds the controller.*/
	uint8_t appHoldingTimer;					/*Current Application that holds the timer.*/
	uint8_t pc;									/*Program counter.*/
	uint8_t number_of_active_apps;				/*The whole of active applications in the VM.*/
	uint8_t count_instructions;					/*Count the instructions for context-switch.*/
	uint8_t appWaitSensor;						/*The first application that called the ReadSensor.*/
	uint8_t application_id;						/*Send application_id*/

/*  16-bit  */
	uint16_t time4MeasurementStartAt;			/*Timer start flag for measurements scheduling.*/
	uint16_t minPeriod; 
	uint16_t sensor_data;						/*Variable to save the sensor's value.*/
	uint16_t average;
	uint16_t startDelay;
	uint16_t dtDelay;
/*-----------------------*/
	int16_t data_1;								/*The minimum brightness value from all wireless sensor network.*/
	int16_t data_2;								/*The maximum brightness value from all wireless sensor network.*/
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
	bool incoming = FALSE;

/* ----------------------- ARRAYS -------------------- */	
	message_t PacketBuffer[SIZE], SamplingPacketBuffer[SIZE], StatsSamplingPacketBuffer[SIZE];
	ActiveQueryQueue_t AQQ[MAX_APPLICATIONS];
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
		for (start=0; start < MAX_APPLICATIONS; start++) {
			AQQ[start].state = 0;
			AQQ[start].sampling_id = 0;			/*new*/
			AQQ[start].state = 0;
			AQQ[start].app_id = 0;
			AQQ[start].RegisterReadSensor = 0; // 0 value depicts that there isn't register which needs sensors data.
			for (i=0; i<6; i++) {
				AQQ[start].registers[i] = 0;
			}
		}
	}

	task void init_ContributedNodes() {
		for (start = 0; start < LAST_SENDERS; start++) {
			ContributedNodes[start].node_id = 0;
		}
	}

	task void init_AQQ() {
		for (start = 0; start < 2; start++) {
			AQQ[start].state = 0;
			AQQ[start].app_id = 0;
			AQQ[start].RegisterReadSensor = 0; // 0 value depicts that there isn't register which needs sensors data.
			for (i=0; i<10; i++) {
				AQQ[start].registers[i] = 0;
			}
		}
	}

/* ------------------------------- Delay Measurement Scheduling -------------------------------- */
	task void DelayMeasurementScheduling() {
							/****** ORIGINATOR NODE ******/
		if (AQQ[appHoldingController].source_id == TOS_NODE_ID) {
			if (call TimerSendPCSerial.isRunning() == TRUE && Hold_Waiting_Timer != appHoldingController) {  /** if the new waiting time calculation is for a new query then schedule */
				checkTimer = call TimerSendPCSerial.getNow();										//AQQ[remindQuery].source_id
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
				Hold_Waiting_Timer = appHoldingController;
				call TimerSendPCSerial.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime);
				AQQ[Hold_Waiting_Timer].startDelay = call TimerSendPCSerial.getNow();
			}
		}
		else {							/***** MIDDLE NODE ******/
			if (call Timer_StatsUnicast_Unicast.isRunning() == TRUE && Hold_Waiting_Timer != appHoldingController) {  /** if the new waiting time calculation is for a new query then schedule */
				checkTimer = call Timer_StatsUnicast_Unicast.getNow();
				runningTime = checkTimer - AQQ[Hold_Waiting_Timer].startDelay;
				dt = AQQ[remindQuery].RemaingTime - runningTime;
				AQQ[appHoldingController].startDelay = call Timer_StatsUnicast_Unicast.getNow();						/* keep what time the new q ask for timer */

				if (dt > AQQ[appHoldingController].WaitingTime) {											/*If WT for new q is smaller than one that hold the timer */
					Hold_Waiting_Timer = appHoldingController;
					call Timer_StatsUnicast_Unicast.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime +(20 * TOS_NODE_ID));
				}

				query_pos = 0;
				while( query_pos < NUMBER_OF_QUERIES) {
					if (AQQ[query_pos].state == 1 && query_pos != appHoldingController) {
						AQQ[query_pos].RemaingTime -= runningTime;									/*remaing time */
					}
					query_pos++;
				}
			}
			else {																					/** else if the new waiting time calculation is for the same query */
				Hold_Waiting_Timer = appHoldingController;
				call Timer_StatsUnicast_Unicast.startOneShot(AQQ[Hold_Waiting_Timer].WaitingTime + (20* TOS_NODE_ID));
				AQQ[Hold_Waiting_Timer].startDelay = call Timer_StatsUnicast_Unicast.getNow();		/* Keep a flag, to remember when you start the clock */
			}
		}
		call TimerCallingInterpretation.startOneShot(10);
	}

/* ------------------------------- Interpretation ----------------------------- */
	task void Interpretation() {
		
		while (AQQ[appHoldingController].state != 0) {

			/* ---------------------------------------------------- CONTEXT SWITCHING -------------------------------------------------------- */
			if (count_instructions >= CONTEXT_SWITCH_INSTRUCTIONS || AQQ[appHoldingController].RegisterReadSensor != 0) {
				
				AQQ[appHoldingController].pc = pc;												/**Save where current application pc points.*/
				
				start = appHoldingController;
				appHoldingController++;
				appHoldingController = appHoldingController%MAX_APPLICATIONS;
		
				while (start != appHoldingController) {											/* Psaxnw ws epomeno application ena energo kai kapoio pou den exei kanei return.
																								** An 3anaftasw thn idia efarmogi, profanws den uparxei kapoia allh gia na parei ton controller, opote sunexizw sthn idia. */
					if (AQQ[appHoldingController].state == 1 && AQQ[appHoldingController].pc != 0x00 && AQQ[appHoldingController].TimerCalled == FALSE ) {  /* check if there is any active application that hasn't return.*/
						
						if (AQQ[appHoldingController].RegisterReadSensor == 0) {				/*there is an active app. check if this app waits Sensor's data in order to continue its execution.*/
							count_instructions = 0;
							pc = AQQ[appHoldingController].pc;
							post Interpretation();
							return;
						}
						call Read.read();
						return;
					}
					appHoldingController++;
					appHoldingController = appHoldingController%MAX_APPLICATIONS;
				}

				if (AQQ[appHoldingController].RegisterReadSensor != 0) {						/* This conditioin will be executed only if there is no other application in the system and the controller is back to the same application.*/
					call Read.read();															/* Check if i want Sensor's data to continue.*/
					return;
				}

			}
			/* ------------------------------------------------- END OF CONTEXT SWITCHING ------------------------------------------------------- */
			
			instruction = AQQ[appHoldingController].BinaryMessage[pc] & 0xF0;
			
			switch (instruction) {
				case 0x00:											/*return*/
					if (pc > (4 + AQQ[appHoldingController].BinaryMessage[1] + AQQ[appHoldingController].BinaryMessage[2]) && mode == 1 && incoming == TRUE) {
						call TimerConfigurePacket.startOneShot(10);
						return;
					}
					if (AQQ[appHoldingController].TimerCalled == FALSE) {						/*If an application returned before calling Timer Handler, means that the current application terminated its execution. */
						AQQ[appHoldingController].state = 0;
					}

					count_instructions = 0;
					AQQ[appHoldingController].pc = pc;											/**Save where current application pc points.*/

					start = appHoldingController;
					appHoldingController++;
					appHoldingController = appHoldingController%MAX_APPLICATIONS;
			
					while (start != appHoldingController) {										/* Psaxnw ws epomeno application ena energo kai kapoio pou den exei kanei thn entolh return.
																								** An 3anaftasw thn idia efarmogi tote sunexizw sthn idia. */
						if (AQQ[appHoldingController].state == 1 && AQQ[appHoldingController].pc != 0x00) {  	/* check if active application and has instructions to do.*/
							if (AQQ[appHoldingController].RegisterReadSensor == 0) {
								count_instructions = 0;
								pc = AQQ[appHoldingController].pc;
								post Interpretation();
								return;
							}
							call Read.read();
							return;
						}
						appHoldingController++;
						appHoldingController = appHoldingController%MAX_APPLICATIONS;
					}
					count_instructions++;
					/*if no other active application in the system, just return from the execution.*/
					return;
				case 0x10:											/* set, rx = val (1rx)*/
					rx = (AQQ[appHoldingController].BinaryMessage[pc] & 0x0F);
					rx--;
					AQQ[appHoldingController].registers[rx] = AQQ[appHoldingController].BinaryMessage[++pc] & 0xFF;
					pc++;
					break;
				case 0x20:											/* cpy, rx = ry */
					rx = (AQQ[appHoldingController].BinaryMessage[pc] & 0x0F);
					ry = AQQ[appHoldingController].BinaryMessage[++pc] & 0xFF;
					rx--;
					ry--;
					AQQ[appHoldingController].registers[rx] = AQQ[appHoldingController].registers[ry];
					pc++;
					break;
				case 0x30:											/* add, rx = rx + ry */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					ry = AQQ[appHoldingController].BinaryMessage[++pc] & 0xFF;
					rx--;
					ry--;
					AQQ[appHoldingController].registers[rx] += AQQ[appHoldingController].registers[ry];
					pc++;
					break;
				case 0x40:											/* sub,rx = rx-ry */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					ry = AQQ[appHoldingController].BinaryMessage[++pc] & 0x0F;
					rx--;
					ry--;
					AQQ[appHoldingController].registers[rx] -= AQQ[appHoldingController].registers[ry];
					pc++;
					break;
				case 0x50:											/* inc, rx = rx + 1 */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					rx--;
					AQQ[appHoldingController].registers[rx]++;
					pc++;
					break;
				case 0x60:											/* dec, rx = rx - 1 */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					rx--;
					AQQ[appHoldingController].registers[rx]--;
					pc++;
					break;
				case 0x70:											/* max, rx = max(rx,ry) */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					pc++;
					ry = AQQ[appHoldingController].BinaryMessage[pc] & 0xFF;
					rx--;
					ry--;
					if (AQQ[appHoldingController].registers[rx] < AQQ[appHoldingController].registers[ry]) {
						AQQ[appHoldingController].registers[rx] = AQQ[appHoldingController].registers[ry];
					}
					pc++;
					break;
				case 0x80:											/* min, rx = min(rx,ry) */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					pc++;
					ry = AQQ[appHoldingController].BinaryMessage[pc] & 0xFF;
					rx--;
					ry--;
					if (AQQ[appHoldingController].registers[rx] > AQQ[appHoldingController].registers[ry]) {
						AQQ[appHoldingController].registers[rx] = AQQ[appHoldingController].registers[ry];
					}
					pc++;
					break;
				case 0x90:											/* bgz, if ( rx > 0 ) pc = pc + off */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					rx--;
					if (AQQ[appHoldingController].registers[rx] > 0) {
						pc += (AQQ[appHoldingController].BinaryMessage[++pc]);
						count_instructions++;
						break;
					}
					pc+=2;
					break;
				case 0xA0:											/* bez, if ( rx == 0 ) pc = pc + off */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					rx--;
					if (AQQ[appHoldingController].registers[rx] == 0) {
						pc += AQQ[appHoldingController].BinaryMessage[++pc];
						count_instructions++;
						break;
					}
					pc+=2;
					break;
				case 0xB0:											/* bra, pc = pc + off */
					pc += (AQQ[appHoldingController].BinaryMessage[++pc]);
					break;
				case 0xC0:											/* led, f ( val != 0 ) turn led on else turn led off */
					if ((AQQ[appHoldingController].BinaryMessage[pc] & 0x0F) == 0x01){
						if (AQQ[appHoldingController].app_id == 0) { 
							call Leds.led1On();
						}
						else { 
							call Leds.led2On();
						}
						
						pc++;
						break;
					}
					if (AQQ[appHoldingController].app_id == 0) { 
						call Leds.led1Off(); 
					}
					else { 
						call Leds.led2Off(); 
					}
					pc++;
					break;
				case 0xD0:											/* rdb, rx = current brightness value */
					call Leds.led2Toggle();
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					AQQ[appHoldingController].RegisterReadSensor = rx;
					data_id++;
					pc++;
					break;
				case 0xE0:											/* tmr */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					pc++;
					AQQ[appHoldingController].TimerRemainingTime = AQQ[appHoldingController].BinaryMessage[pc] & 0xFFFF;  	/*Keep the remaining time*/
					AQQ[appHoldingController].TimerRemainingTime = AQQ[appHoldingController].TimerRemainingTime*1000;
					AQQ[appHoldingController].TimerCalled = TRUE;

					if (call TimerApplications.isRunning() == TRUE) {

						checkTimer = call TimerApplications.getNow();
						runningTime = checkTimer - timerApplicationStartAt;
						dt = AQQ[appHoldingTimer].TimerRemainingTime - runningTime;

						if (dt > AQQ[appHoldingController].TimerRemainingTime ) {			/*The second app gets the timer*/
							appHoldingTimer = appHoldingController;
							call TimerApplications.startOneShot(AQQ[appHoldingController].TimerRemainingTime); //BinaryMessage[pc]*1000);
							timerApplicationStartAt = call TimerApplications.getNow();
						}
						else {
							timerApplicationStartAt = call TimerApplications.getNow();
						}
						
						j=0;
						while (j < MAX_APPLICATIONS) {										/*Update the Remaining time of every application.*/
							if (AQQ[j].state == 1 && j!= appHoldingController) {
								AQQ[j].TimerRemainingTime -= runningTime;
							}
							j++;
						}

					}
					else {
						appHoldingTimer = appHoldingController;
						call TimerApplications.startOneShot(AQQ[appHoldingController].TimerRemainingTime);
						timerApplicationStartAt = call TimerApplications.getNow();
					}
					
					pc++;
					break;
				case 0xF0:											/* snd (0 -> r7 only, 1 -> r7 and r8) */
					rx = AQQ[appHoldingController].BinaryMessage[pc] & 0x0F;
					application_id = AQQ[appHoldingController].app_id;
					mode = rx;
					AQQ[appHoldingController].propagation_mode = mode;
					//incoming = FALSE;

					pc++;
					AQQ[appHoldingController].pc = pc;							/* Save where current application pc points. */
					count_instructions++;
					call TimerConfigurePacket.startOneShot(10);
					return;
			}
			count_instructions++;
		}
	}
	
/* ---------------------------- Query Scheduling ------------------------------- */
	task void QueryScheduling() {
		if (call TimerQueryFired.isRunning() == TRUE) {								/* check if i am alone or other queries also running */
			checkTimer = call TimerQueryFired.getNow();
			runningTime = checkTimer - timerStartAt;
			dt = AQQ[HoldTimer].query_lifetime - runningTime; 						/* remaining_time to expire. */

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
					AQQ[query_pos].query_lifetime = AQQ[query_pos].query_lifetime - runningTime; 	/* remaining_timer to expire */
				}
				query_pos++;
			}
		}
		else {
			HoldTimer = sendQuery; 
			call TimerQueryFired.startOneShot(AQQ[HoldTimer].query_lifetime); 		/* end query lifetime when TimerQueryFired fire */
			timerStartAt = call TimerQueryFired.getNow();
			appHoldingController = sendQuery;
			count_instructions = 0;													/* It's the only one application in the system. So init count_instructions*/
			pc = AQQ[appHoldingController].pc;
			post Interpretation();													/* auto edw den mou aresei. Mhpws na to valw na kaleite afou oloklirwthei to broadcast.(dhldh sto telos tou kwdika)*/
			call Leds.led0On();
		}
		/*Call interpreter, if only there is no other active application in the system.*/
		if (number_of_active_apps > 1 && AQQ[appHoldingController].BinaryMessage[pc] == 0x00 && call TimerApplications.isRunning() == TRUE) {
			appHoldingController = sendQuery;
			pc = AQQ[appHoldingController].pc;										/*init*/
			count_instructions = 0;
			post Interpretation();
		}

		if (call TimerQueryBroadcast.isRunning() == TRUE) {							/* Send A Broadcast message after TOS_NODE_ID * 30 time. */
			t0 = call TimerQueryBroadcast.gett0();
			dt = call TimerQueryBroadcast.getdt();
			call TimerQueryBroadcast.startOneShot(t0 + dt);
		}
		else {
			mode = 0;
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

/* ------------------------------- Serial Send -------------------------------- */
	task void SendSerial() {
		if (!serial_busy) {															/* SIMPLE mode == 0 */

			switch (mode) {
				case 0:
					s_sampling_pkt = (sampling_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (sampling_msg_t) ));
					if (s_sampling_pkt == NULL) {
						return;
					}
					
					s_sampling_pkt->source_id = source_id;
					s_sampling_pkt->application_id = application_id;
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
					break;
				case 1:
					s_stats_sampling_pkt = (stats_sampling_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (stats_sampling_msg_t) ));
					if (s_stats_sampling_pkt == NULL) {
						return;
					}
					
					s_stats_sampling_pkt->source_id = source_id;
					s_stats_sampling_pkt->application_id = application_id;
					s_stats_sampling_pkt->data_id = s_data_id;
					s_stats_sampling_pkt->forwarder_id = forwarder_id;
					s_stats_sampling_pkt->hops = hops;
					s_stats_sampling_pkt->data_1 = data_1;
					s_stats_sampling_pkt->data_2 = data_2;
					s_stats_sampling_pkt->destination_id = destination_id;
					s_stats_sampling_pkt->sequence_number = sequence_number;
					s_stats_sampling_pkt->mode = mode;

					//start = 0;
					//while(start < LAST_SENDERS) {
					//	if (ContributedNodes[start].node_id == 0) {
					//		ContributedNodes[start].node_id = TOS_NODE_ID;
					//		break;
					//	}
					//	start++;
					//}
					//memcpy(s_stats_sampling_pkt->contributed_ids, ContributedNodes, LAST_SENDERS * sizeof(nx_uint8_t));
		
					if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (stats_sampling_msg_t)) == SUCCESS){
						dbg("BroadcastingC", "Start sending serial packet\n\n ");
						serial_busy = TRUE;
					}
					break;
				case 2:
					srl_query_cancel = (query_cancel_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (query_cancel_msg_t) ));
					if (srl_query_cancel == NULL) {
						return;
					}
					srl_query_cancel->source_id = TOS_NODE_ID;
					srl_query_cancel->app_id = AQQ[query_cancel].app_id;
					//srl_query_cancel->sequence_number = AQQ[query_cancel].sequence_number;
					srl_query_cancel->mode = mode;
					srl_query_cancel->forwarder_id = TOS_NODE_ID;

					if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (query_cancel_msg_t)) == SUCCESS){
						dbg("BroadcastingC", "Start sending serial packet\n\n ");
						serial_busy = TRUE;
					}
					break;
			}
		}
	}
/* ------------------------------- Query Canceling -------------------------------- */
	task void QueryCancel() {
		//if (HoldTimer == query_cancel) {
		//	checkTimer = call TimerQueryFired.getNow();
		//	runningTime = checkTimer - timerStartAt;
		//	AQQ[query_cancel].query_lifetime = runningTime;			/* krata to running time etsi wste na na upologiseis thn diafora xronoy apo ta alla queries sthn oura */
		//	call TimerQueryFired.stop();
		//	call TimerQueryFired.startOneShot(20); //10
		//}

		mode = 2;
		if (call TimerQueryBroadcast.isRunning() == TRUE) {
			t0 = call TimerQueryBroadcast.gett0();
			dt = call TimerQueryBroadcast.getdt();
			call TimerQueryBroadcast.startOneShot(t0 + dt);
		}
		else {
			call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 50); //30
		}
	}

	task void QueryCancelConfirmation() {
		if (!unicast_busy) {
			ucast_query_cancel = (query_cancel_msg_t*) (call SamplingAMPacket.getPayload(&pkt, sizeof (query_cancel_msg_t)));
			if (ucast_query_cancel == NULL) {
				return;
			}

			ucast_query_cancel->source_id = AQQ[query_cancel].source_id;
			ucast_query_cancel->app_id = AQQ[query_cancel].app_id;
			//ucast_query_cancel->sequence_number = AQQ[query_cancel].sequence_number;
			ucast_query_cancel->mode = 2;
			ucast_query_cancel->forwarder_id = TOS_NODE_ID;

			if (call SamplingRadioAMSend.send(send_qcancelTo_node /*AQQ[query_cancel].father_node */, &pkt, sizeof (sampling_msg_t)) == SUCCESS){
				unicast_busy = TRUE;
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
				ucast_ReUpd->query_lifetime = AQQ[query_pos].query_lifetime;
				//ucast_ReUpd->propagation_mode = AQQ[query_pos].propagation_mode;
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
		number_of_active_apps = 0;
		count_received_children = 0;

		call Leds.led0Off();
		call Leds.led1Off();
		call Leds.led2Off();

		post init_StateMessages();
		post init_ActiveQueryQ();
		post init_ContributedNodes();
		//post init_AQQ();

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
			call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 30);		/* When boot, send a bcast messaage to learn the network state.*/
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

/* ----------------------------------------------------- TimerCallingInterpretation ------------------------------------------------------------ */
	event void TimerCallingInterpretation.fired() {			/*call interpreter after the delayMeasurement.*/
		pc = AQQ[appHoldingController].pc;
		post Interpretation();
	}

/* -------------------------------------------------------- TimerApplications ------------------------------------------------------------------ */
	event void TimerApplications.fired() {
		if (mode != 2) {																		/*if the appliation is deleted.*/
			if (AQQ[appHoldingController].BinaryMessage[pc] != 0x00) {							/* If the timer cut the execution from the application that was running in the interpreter.*/
				AQQ[appHoldingController].pc = pc;												/* ,then save the current program counter in order to continue its execution from that point.*/
			}
			appHoldingController = appHoldingTimer;
			AQQ[appHoldingController].pc = 4 + AQQ[appHoldingController].BinaryMessage[1]; 		/* 4 + Sz(InH) refresh where the pc points in this application */
			AQQ[appHoldingController].TimerCalled = FALSE;

			j=0;
			minQuery = 0;
			while (j < MAX_APPLICATIONS) {
				if (AQQ[j].state == 1 && j != appHoldingController) {
					minQuery = j;
					break;
				}
				j++;
			}

			j=0;
			while (j < MAX_APPLICATIONS) {
				if (AQQ[j].state == 1 && j != appHoldingController && AQQ[j].TimerCalled == TRUE) {
					AQQ[j].TimerRemainingTime -= AQQ[appHoldingController].TimerRemainingTime;						/*afairw oso xrono etrexe to app apo thn teleutaio interupt*/
					if (AQQ[j].TimerRemainingTime <= AQQ[minQuery].TimerRemainingTime) {
						minQuery = j;
					}
				}
				j++;
			}
			AQQ[appHoldingController].TimerRemainingTime = 0;
			appHoldingTimer = minQuery;

			if (AQQ[appHoldingTimer].TimerRemainingTime > 0 && AQQ[appHoldingTimer].TimerCalled == TRUE) {
				call TimerApplications.startOneShot(AQQ[appHoldingTimer].TimerRemainingTime);
				timerApplicationStartAt = call TimerApplications.getNow();
			}
			count_instructions = 0;
			pc = AQQ[appHoldingController].pc;
		}
		else if (mode == 2) {
			j=0;
			minQuery = 0;
			while (j < MAX_APPLICATIONS) {
				if (AQQ[j].state == 1 && j != appHoldingTimer) {
					minQuery = j;
					break;
				}
				j++;
			}

			j=0;
			while (j < MAX_APPLICATIONS) {
				if (AQQ[j].state == 1 && j != appHoldingTimer && AQQ[j].TimerCalled == TRUE) {
					AQQ[j].TimerRemainingTime -= AQQ[appHoldingTimer].TimerRemainingTime;						/*afairw oso xrono etrexe to app apo thn teleutaio interupt*/
					if (AQQ[j].TimerRemainingTime <= AQQ[minQuery].TimerRemainingTime) {
						minQuery = j;
					}
				}
				j++;
			}
			AQQ[appHoldingTimer].TimerRemainingTime = 0;
			appHoldingTimer = minQuery;

			if (AQQ[appHoldingTimer].TimerRemainingTime > 0 && AQQ[appHoldingTimer].TimerCalled == TRUE) {
				call TimerApplications.startOneShot(AQQ[appHoldingTimer].TimerRemainingTime);
				timerApplicationStartAt = call TimerApplications.getNow();
			}
			call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 30);
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
			switch (mode) {
				case 0:																							/* BROADCAST (just to remember the mode = 0 in QueryScheduling task) */
					if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){
						busy = TRUE;
					}
					break;
				case 2:
					//call TimerQueryCancelResponse.startOneShot(AQQ[query_cancel].WaitingTime);					/* Waiting upper bound before resending the query cancel */
					if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_cancel_msg_t)) == SUCCESS){
						busy = TRUE;
					}
					break;
				case 3:																							/* mode = 3 update bcast */
					if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (update_msg_t)) == SUCCESS){
						busy = TRUE;
					}
					break;
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

/* ------------------------------------------------------ TimerConfigurePacket -------------------------------------------------------- */
	event void TimerConfigurePacket.fired() {
		/****** ORIGINATOR ******/
		if (TOS_NODE_ID == AQQ[appHoldingController].source_id) {	
			if (incoming == FALSE) {
				source_id = TOS_NODE_ID;
				s_data_id = data_id;
				forwarder_id = TOS_NODE_ID;
				hops = AQQ[appHoldingController].hops;
				destination_id = AQQ[appHoldingController].source_id;
				sequence_number = AQQ[appHoldingController].sequence_number;
			}

			switch (mode) {
				case 0:														/* SIMPLE mode == 0 */
					sensor_data = AQQ[appHoldingController].registers[6];
					incoming = FALSE;
					call TimerSendPCSerial.startOneShot(10);  					
					break;
				case 1:														/* STATS mode == 1 */
					if (incoming == FALSE) {
						data_1 = AQQ[appHoldingController].registers[6];		/* reg_7 */
						data_2 = AQQ[appHoldingController].registers[7];		/* reg_8*/
						post DelayMeasurementScheduling();
						break;
					}
					else if (incoming == TRUE) {
						incoming = FALSE;
						data_1 = AQQ[appHoldingController].registers[6];		/* reg_7 */
						data_2 = AQQ[appHoldingController].registers[7];		/* reg_8*/
						AQQ[appHoldingController].registers[6] = AQQ[appHoldingController].temporary_reg7;		/*init registers*/
						AQQ[appHoldingController].registers[7] = AQQ[appHoldingController].temporary_reg8;		/*init registers*/
					}

					if (AQQ[appHoldingController].count_received_children == AQQ[appHoldingController].number_of_children) {
						AQQ[appHoldingController].count_received_children = 0;
						call TimerSendPCSerial.startOneShot(10);
						break;
					}
					else {									/*in case i have to wait for the rest of my children, give back the execution to interpreter*/
						pc = AQQ[appHoldingController].pc;
						post Interpretation();
					}
			}
		}	/****** MIDDLE NODE *******/
		else {
			sendTofather = AQQ[appHoldingController].forwarder_id;	 		/* My Father Node is the one who send me the query bcast, so i will forward the measurements back to him */
			
			switch (mode) {
				case 0:
					if (incoming == FALSE) {
						sampling_save = sampling_save%SIZE;
						ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
						if (ucast_pkt == NULL) {
							return;
						}
						sampling_save++;

						ucast_pkt->source_id = TOS_NODE_ID;
						ucast_pkt->application_id = application_id;
						ucast_pkt->data_id = data_id;
						ucast_pkt->forwarder_id = TOS_NODE_ID;
						ucast_pkt->sensor_data = AQQ[appHoldingController].registers[6];			/*send reg_7.*/
						ucast_pkt->destination_id = AQQ[appHoldingController].forwarder_id;
						ucast_pkt->sequence_number = AQQ[appHoldingController].sequence_number;
						ucast_pkt->mode = mode;

						call Timer_StatsUnicast_Unicast.startOneShot(TOS_NODE_ID * 20);  	// Timer for Unicast Message - TOS_NODE_ID * 20				
						break;
					}
					/* kane to configuration twn data sto shmeio pou kanei receive kai edw alla3e mono to sendor_data*/
					
					ucast_pkt->sensor_data = AQQ[appHoldingController].registers[6];

					call Timer_StatsUnicast_Unicast.startOneShot(TOS_NODE_ID * 20);  	// Timer for Unicast Message - TOS_NODE_ID * 20				
					break;
				case 1:
					if (incoming == FALSE) {								/* IF it is my packet. . . */
						stats_sampling_save = stats_sampling_save%SIZE;
						stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_save], sizeof (stats_sampling_msg_t)));
						if (stats_ucast_pkt == NULL) {
							return;
						}
						stats_sampling_save++;

						stats_ucast_pkt->source_id = TOS_NODE_ID;
						stats_ucast_pkt->data_id = data_id;
						stats_ucast_pkt->forwarder_id = TOS_NODE_ID;
						stats_ucast_pkt->hops = AQQ[appHoldingController].hops;
						stats_ucast_pkt->data_1 = AQQ[appHoldingController].registers[6];
						stats_ucast_pkt->data_2 = AQQ[appHoldingController].registers[7];
						stats_ucast_pkt->destination_id = AQQ[appHoldingController].source_id;
						stats_ucast_pkt->sequence_number = AQQ[appHoldingController].sequence_number;
						stats_ucast_pkt->mode = mode;
						post DelayMeasurementScheduling();
						break;
					}
					else if(incoming == TRUE) {
						incoming = FALSE;			/*make incoming FALSE and if another packet received, it will be responsible to make it TRUE*/
						stats_ucast_pkt->data_1 = AQQ[appHoldingController].registers[6];						/* set the values coming from the application.*/
						stats_ucast_pkt->data_2 = AQQ[appHoldingController].registers[7];
						AQQ[appHoldingController].registers[6] = AQQ[appHoldingController].temporary_reg7;		/* restore the init values for the next ecexution. */
						AQQ[appHoldingController].registers[7] = AQQ[appHoldingController].temporary_reg8;
					}

					if (AQQ[appHoldingController].count_received_children == AQQ[appHoldingController].number_of_children) {
						AQQ[appHoldingController].count_received_children = 0;
						call Timer_StatsUnicast_Unicast.startOneShot(TOS_NODE_ID * 20);
						break;
					}
			}
		}
	} 		

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
				if(AQQ[j].RegisterReadSensor != 0) {
					i = AQQ[j].RegisterReadSensor;			/*i has the register id*/
					AQQ[j].registers[--i] = sensor_data;
					AQQ[j].RegisterReadSensor = 0;
				}
				j++;
			}
			//call TimerCacheDataSensor.startOneShot(10000);		/*Cache data for 1 minute.*/
			pc = AQQ[appHoldingController].pc;
			post Interpretation();
		}
	}

/* ----------------------------------------- TimerSendPCSerial => SERIAL SEND : MOTE -> PC -------------------------------------------- */ 
	event void TimerSendPCSerial.fired() {
		post SendSerial();
	}

/* ------------------------------------------- TimerQueryFired => Query_Lifetime END -------------------------------------------------- */ 
	event void TimerQueryFired.fired() {
		dbg("QueryC", "The query_%hu expired! @ %s", sim_time_string());
		/*Disable the expired query*/
		number_of_active_apps--;
		AQQ[HoldTimer].state = 0;

		if (AQQ[HoldTimer].app_id == 0) {
			call Leds.led1Off();
		}
		else { 
			call Leds.led2Off(); 
		}

		if (number_of_active_apps > 0) {
			expiredQuery = HoldTimer;
			minQuery = 0;
			query_pos = 0;
			while (query_pos < MAX_APPLICATIONS) {
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

		if (mode == 2) {
			if (appHoldingTimer == AQQ[HoldTimer].app_id) {
				checkTimer = call TimerApplications.getNow();
				runningTime = checkTimer - timerApplicationStartAt;
				AQQ[appHoldingTimer].TimerRemainingTime -= runningTime;
				call TimerApplications.stop();
				call TimerApplications.startOneShot(10);
			}
			else {
				call TimerQueryBroadcast.startOneShot(TOS_NODE_ID * 30);
			}
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

			switch (mode) {
								/*SIMPLE MODE*/
				case 0:	
					ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_send], sizeof (sampling_msg_t)));
					if (ucast_pkt == NULL) {
						return;
					}
					memcpy(&pkt, &SamplingPacketBuffer[sampling_send], sizeof(message_t));

					if (call SamplingRadioAMSend.send(sendTofather, &pkt, sizeof (sampling_msg_t)) == SUCCESS){
						unicast_busy = TRUE;
					}
					break;
								/*STATS MODE*/
				case 1:
					count_received_children = 0;	/*init the counter for the next ucast transmission */
					stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_send], sizeof (stats_sampling_msg_t)));
					if (stats_ucast_pkt == NULL) {
						return;
					}
					//start = 0;
					//while(start < LAST_SENDERS) {
					//	if (ContributedNodes[start].node_id == 0) {
					//		ContributedNodes[start].node_id = TOS_NODE_ID;
					//		break;
					//	}
					//	start++;
					//}
					//memcpy(stats_ucast_pkt->contributed_ids, ContributedNodes, LAST_SENDERS * sizeof(nx_uint8_t));
					memcpy(&pkt, &StatsSamplingPacketBuffer[stats_sampling_send], sizeof(message_t));
					if (call SamplingRadioAMSend.send(sendTofather, &pkt, sizeof (stats_sampling_msg_t)) == SUCCESS){
						unicast_busy = TRUE;
					}
					break;
			}
		}
	}

/* ----------------------------------------- SAMPLING RADIO RECEIVE MESSAGES ------------------------------------------------ */
	event message_t* SamplingRadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		//AQQ[appHoldingController].pc = pc; 								/* Save the state of the current application running in the interpreter.*/

		if (len == sizeof(sampling_msg_t)) {													/** RECEIVE SIMPLE SAMPLING MESSAGE **/
			call Leds.led1Toggle();
			r_sampling_pkt = (sampling_msg_t*) payload;

			incoming = TRUE;											/*depicts that it is an incoming packet, not generated by me.*/
			AQQ[appHoldingController].pc = pc; 							/* Save the state of the current application running in the interpreter.*/
			start = 0;
			while (start < MAX_APPLICATIONS) {
				if (AQQ[start].app_id == r_sampling_pkt->application_id) {
					break;
				}
				start++;
			}
														/* Application does not have MESSAGE HANDLER. */
			if (AQQ[start].BinaryMessage[3] == 0x00) {
					/** If i receive a msg and i am the MIDDLE node then i will re-unicast the msg to my father. */
					if (r_sampling_pkt->destination_id != TOS_NODE_ID) {

						sampling_save = sampling_save%SIZE;
						ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
						if (ucast_pkt == NULL) {
							return;
						}
						sampling_save++;

						ucast_pkt->source_id = r_sampling_pkt->source_id;
						ucast_pkt->application_id = r_sampling_pkt->application_id;   /*new*/
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
						application_id = r_sampling_pkt->application_id;
						s_data_id =  r_sampling_pkt->data_id;
						forwarder_id = r_sampling_pkt->forwarder_id;
						sensor_data = r_sampling_pkt->sensor_data;
						destination_id = r_sampling_pkt->destination_id;
						sequence_number = r_sampling_pkt->sequence_number;
						mode = 0;

						call TimerSendPCSerial.startOneShot(20);
					}
			}				/****** Application MESSAGE HANDLER. ******/
			else {
				if (r_sampling_pkt->destination_id != TOS_NODE_ID) {	/** If i receive a msg and i am the MIDDLE node then i will re-unicast the msg to my father. */
					sampling_save = sampling_save%SIZE;
					ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
					if (ucast_pkt == NULL) {
						return;
					}
					sampling_save++;	

					ucast_pkt->source_id = r_sampling_pkt->source_id;
					ucast_pkt->application_id = r_sampling_pkt->application_id;   /*new*/
					ucast_pkt->data_id = r_sampling_pkt->data_id;
					ucast_pkt->forwarder_id = TOS_NODE_ID;
					AQQ[appHoldingController].registers[8] = r_sampling_pkt->sensor_data; 	/*receive the data and save them into r9*/ 
					ucast_pkt->destination_id = r_sampling_pkt->destination_id;
					ucast_pkt->sequence_number = r_sampling_pkt->sequence_number;
					ucast_pkt->mode = 0;
					
					query_pos = 0;
					while (AQQ[query_pos].source_id != r_sampling_pkt->destination_id && AQQ[query_pos].sequence_number != r_sampling_pkt->sequence_number && query_pos < MAX_APPLICATIONS) {
						query_pos++;
					}
					if (query_pos < MAX_APPLICATIONS) {
						sendTofather = AQQ[query_pos].forwarder_id;
					}
				}
				else {		/* if i am the one who send the query (TOS_NODE_ID == destination_id )then call TimerSendPCSerial to print the values*/
					source_id = r_sampling_pkt->source_id;
					application_id = r_sampling_pkt->application_id;
					s_data_id =  r_sampling_pkt->data_id;
					forwarder_id = r_sampling_pkt->forwarder_id;
					AQQ[start].registers[8] = r_sampling_pkt->sensor_data;				/* save incoming data to reg_9. */
					destination_id = r_sampling_pkt->destination_id;
					sequence_number = r_sampling_pkt->sequence_number;
				}

				appHoldingController = start;
				pc = 4 + AQQ[appHoldingController].BinaryMessage[1] + AQQ[appHoldingController].BinaryMessage[2];		/**PC points to MESSAGE Handler. */
				count_instructions = 0;
				post Interpretation();
			}
		} 
		else if (len == sizeof(stats_sampling_msg_t)) {									/** RECEIVE STATS SAMPLING MESSAGE */
			r_stats_sampling_pkt = (stats_sampling_msg_t*) payload;

			AQQ[appHoldingController].pc = pc; 			/* In case we had an iterupt while interpretation, save the state of the current application running in the interpreter.*/
			start = 0;
			while (start < MAX_APPLICATIONS) {
				if (AQQ[start].app_id == r_stats_sampling_pkt->application_id) {
					AQQ[start].count_received_children++;
					break;
				}
				start++;
			}
			mode = 1;
			appHoldingController = start;
			incoming = TRUE;																	/*depicts that it is an incoming packet, not generated by me.*/
			AQQ[appHoldingController].temporary_reg7 = AQQ[appHoldingController].registers[6];	/*Save the current state of the r7,r8*/
			AQQ[appHoldingController].temporary_reg8 = AQQ[appHoldingController].registers[7];
			AQQ[appHoldingController].registers[6] = data_1;									/*restore the r7,r8 state in order to execute the Message Handler instructions.*/
			AQQ[appHoldingController].registers[7] = data_2;

			/** If MIDDLE NODE then RE-UNICAST to my father. */
			if (r_stats_sampling_pkt->destination_id != TOS_NODE_ID) {
				
				AQQ[appHoldingController].registers[8] = r_stats_sampling_pkt->data_1;
				AQQ[appHoldingController].registers[9] = r_stats_sampling_pkt->data_2;

				dtDelay = call Timer_StatsUnicast_Unicast.getNow();
				AQQ[appHoldingController].WaitingTime = dtDelay - AQQ[appHoldingController].startDelay;	/** query_pos calculate above and points to the query in whice we receive the measurement ucast.*/
				AQQ[appHoldingController].RemaingTime = AQQ[appHoldingController].WaitingTime;

				/*If i got msg from all my children, stop the timer and procceed to ucast transmission*/
				if (AQQ[appHoldingController].count_received_children == AQQ[appHoldingController].number_of_children) { 
					call Timer_StatsUnicast_Unicast.stop();
				}
			}
			else { 			/*If ORIGINATOR NODE, then send to serial*/
				AQQ[appHoldingController].registers[8] = r_stats_sampling_pkt->data_1;
				AQQ[appHoldingController].registers[9] = r_stats_sampling_pkt->data_2;

				//start = 0;
				//i = 0;
				//while (start < LAST_SENDERS) {
				//	if (ContributedNodes[start].node_id == 0) {
				//		ContributedNodes[start].node_id = r_stats_sampling_pkt->contributed_ids[i];
				//		i++;
				//	}
				//	start++;
				//}

				dtDelay = call TimerSendPCSerial.getNow();
				AQQ[appHoldingController].WaitingTime = dtDelay - AQQ[appHoldingController].startDelay + 200; /** query_pos calculate above and points to the query in whice we receive the measurement ucast.*/
				AQQ[appHoldingController].RemaingTime = AQQ[appHoldingController].WaitingTime;

				/*If i got msg from all my children, stop the timer and procceed to serial transmission*/
				if (AQQ[appHoldingController].count_received_children == AQQ[appHoldingController].number_of_children) { 
					call TimerSendPCSerial.stop();
					//call TimerSendPCSerial.startOneShot(200);
				}
			}

			pc = 4 + AQQ[appHoldingController].BinaryMessage[1] + AQQ[appHoldingController].BinaryMessage[2];		/**PC points to MESSAGE Handler. */
			count_instructions = 0;
			post Interpretation();
		}
//		else if (len == sizeof(query_cancel_msg_t)) {					/*RECEIVE QUERY CANCEL MESSAGE*/
//			rcv_query_cacnel = (query_cancel_msg_t*) payload;
//
//			query_pos = 0;
//			while (query_pos < MAX_APPLICATIONS) {
//				if (AQQ[query_pos].source_id == rcv_query_cacnel->source_id && AQQ[query_pos].sequence_number == rcv_query_cacnel->sequence_number){
//					start = 0;
//					while (start < LAST_SENDERS){
//						if (AQQ[query_pos].children[start] == rcv_query_cacnel->forwarder_id) {  /*Delete my child from that application, as the app was deleted.*/
//							AQQ[query_pos].children[start] = 0;
//							break;
//						}
//						start++;
//					}
//				}
//				query_pos++;	
//			}
//		}
		else if (len == sizeof(response_update_msg_t)) {				/*RECEIVE RESPONSE UPDATE FROM THE NETWORK.*/
			ucast_ReUpd = (response_update_msg_t*) payload;
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
						AQQ[query_pos].query_lifetime = ucast_ReUpd->query_lifetime;
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
					bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
					//bcast_pkt->propagation_mode = AQQ[sendQuery].propagation_mode;
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

			/* Check if i have already taken a query message from this source_id */ 		/* This is where may i have a bug!!!!!!!!!*/
			query_pos = 0;
			while (query_pos < LAST_SENDERS && QuerySendersHistory[query_pos].source_id != r_pkt->source_id) {
				query_pos++;
			}

			/** If reached the end of the array,means that it is the first time receving a query message from that source_id. */
			if (query_pos == LAST_SENDERS) { 
				next = next%LAST_SENDERS;
				QuerySendersHistory[next].sequence_number = 0;  //den xreiazontai 2 if, tha to kanw iso me auto pou mou irthe logika
				QuerySendersHistory[next].source_id = r_pkt->source_id;
				query_pos = next;
			}

			/** I found that the source_id and now i check the sequence number to define if it is a unique msg. */
			if (r_pkt->sequence_number > QuerySendersHistory[query_pos].sequence_number &&  query_pos < LAST_SENDERS) { // query_pos < LS is unnecessary
				next++;
				QuerySendersHistory[query_pos].sequence_number = r_pkt->sequence_number;

				start = 0;														/********** ADD APPLICATION ***********/
				if (number_of_active_apps < MAX_APPLICATIONS) {
					while (start < MAX_APPLICATIONS) {
						if (AQQ[start].state == 0) { 							/*run if you are new app ,until the end of the array to find a position into the system*/
							AQQ[start].state = 1;
							number_of_active_apps++;							/*increase the number of active apps.*/
							AQQ[start].app_id = r_pkt->app_id;
							memcpy(AQQ[start].BinaryMessage, r_pkt->BinaryMessage, 30 * sizeof(nx_uint8_t));
							AQQ[start].pc = 4; 									/** the Init handler always starts on the fourth position of BinaryMessage, that is 3*/
							break;
						}
						start++;
					}

					AQQ[start].source_id = TOS_NODE_ID; 
					AQQ[start].sequence_number = sequence_number;
					AQQ[start].sampling_id = 0;
					AQQ[start].forwarder_id = TOS_NODE_ID;
					AQQ[start].father_node = TOS_NODE_ID;
					AQQ[start].number_of_children = 0;
					AQQ[start].count_received_children = 0;
					AQQ[start].hops = 0;
					AQQ[start].query_lifetime = r_pkt->query_lifetime;
					AQQ[start].WaitingTime = OFFSET;
					AQQ[start].RemaingTime = OFFSET;

					sendQuery = start;
					post QueryScheduling();

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
					bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
					bcast_pkt->app_id = r_pkt->app_id;
					memcpy(bcast_pkt->BinaryMessage, r_pkt->BinaryMessage, 30 * sizeof(nx_uint8_t));
					bcast_pkt->state = r_pkt->state;
					bcast_pkt->action = r_pkt->action;
				}
			} 					/** If i have reveived that msg before, i try to find if this msg belongs to a child node */
			else if (r_pkt->sequence_number == QuerySendersHistory[query_pos].sequence_number && query_pos < MAX_APPLICATIONS) {
				/* Find if that query is active on my system and check if the node that send that message has hop number bigger than mine.*/
				start = 0;
				while (start < MAX_APPLICATIONS) {
					if (AQQ[start].source_id == r_pkt->source_id && AQQ[start].sequence_number == r_pkt->sequence_number && AQQ[start].hops == r_pkt->hops -1){
						if (r_pkt->father_node == TOS_NODE_ID) {	/* if this node that send me a bcast, has chosen me as his father, then save him in my child list. */
							j = 4;
							i = 4 + AQQ[start].BinaryMessage[1];
							while(j < i) {
								if ((AQQ[start].BinaryMessage[j] & 0xF0) == 0xE0) {
									j++;
									AQQ[start].WaitingTime = AQQ[start].BinaryMessage[j] & 0xFFFF; 		/*And set for that query an upper bound for waiting time. */		
									AQQ[start].WaitingTime = AQQ[start].WaitingTime * 1000;
									AQQ[start].WaitingTime -= 1000;
									break;
								}
								j++;
							}
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

			start = 0;
			if (TOS_NODE_ID != rcv_query_cacnel->source_id && number_of_active_apps > 0) {		/*Check if i am not the originator and i have #apps > 0*/
				while (start < MAX_APPLICATIONS) {
					if (AQQ[start].app_id == rcv_query_cacnel->app_id && AQQ[start].state == 1) {
						call Leds.led1Toggle();
						AQQ[start].state = 0;										/*decrease the number of active applications.*/
						if (rcv_query_cacnel->app_id == 0) {
							call Leds.led1Off();
						}
						else { 
							call Leds.led2Off(); 
						}

						query_cancel = start;										/* Define which application will take the controller if the delelted app was the last one that was holding the controller. */
						
						if (appHoldingController == AQQ[start].app_id && number_of_active_apps > 1) {
							start++;
							start = start%MAX_APPLICATIONS;
							i=0;
							while (i < MAX_APPLICATIONS) {
								if (AQQ[start].state == 1) {
									count_instructions = 0;
									appHoldingController = AQQ[start].app_id;		/* found the next application */
									break;
								}
								i++;
								start++;
								start = start%MAX_APPLICATIONS;
							}
						}

						//post QueryCancel();  										/* task to find the query and cancel its operation */
						send_qcancelTo_node = AQQ[query_cancel].father_node;

						save = save%SIZE;
						bcast_query_cancel = (query_cancel_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_cancel_msg_t) ));
						if (bcast_query_cancel == NULL) {
							return;
						}
						save++;

						bcast_query_cancel->source_id = rcv_query_cacnel->source_id;
						bcast_query_cancel->app_id = rcv_query_cacnel->app_id;
						bcast_query_cancel->mode = rcv_query_cacnel->mode;
						bcast_query_cancel->forwarder_id = TOS_NODE_ID;								/*who is sending the broadcast */

						mode = 2;
						send_qcancelTo_node = AQQ[query_cancel].father_node;
						//post QueryCancelConfirmation();					/* Give a response to the father node that send you the query cancelation */
						if (HoldTimer == query_cancel) {
							checkTimer = call TimerQueryFired.getNow();
							runningTime = checkTimer - timerStartAt;
							AQQ[query_cancel].query_lifetime = runningTime;			/* krata to running time etsi wste na na upologiseis thn diafora xronoy apo ta alla queries sthn oura */
							call TimerQueryFired.stop();
							call TimerQueryFired.startOneShot(10); //10
						}
						break;
					}
					start++;
				}
			}
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
			s_bin_code = (binary_msg_t*) payload;

			start = 0;

			switch (s_bin_code->action) {
				case 0:										/********** DELETE APPLICATION ***********/
					while (start < MAX_APPLICATIONS) {
						if (AQQ[start].state == 1 && AQQ[start].app_id == s_bin_code->app_id) {
							AQQ[start].state = 0;								/*decrease the number of active applications.*/
							if (s_bin_code->app_id == 0) {
								call Leds.led1Off();
							}
							else { 
								call Leds.led2Off(); 
							}
							break;
						}
						start++;
					}
					query_cancel = start;										/* Define which application will take the controller if the delelted app was the last one that was holding the controller. */
					if (appHoldingController == AQQ[start].app_id && number_of_active_apps > 1) {
						start++;
						start = start%MAX_APPLICATIONS;
						i=0;
						while (i < MAX_APPLICATIONS) {
							if (AQQ[start].state == 1) {
								count_instructions = 0;
								appHoldingController = AQQ[start].app_id;		/* found the next application */
								break;
							}
							i++;
							start++;
							start = start%MAX_APPLICATIONS;
						}
					}

					//post QueryCancel();  										/* task to find the query and cancel its operation */
					send_qcancelTo_node = AQQ[query_cancel].father_node;
					post SendSerial();

					save = save%SIZE;
					bcast_query_cancel = (query_cancel_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_cancel_msg_t) ));
					if (bcast_query_cancel == NULL) {
						return;
					}
					save++;

					bcast_query_cancel->source_id = TOS_NODE_ID;//s_bin_code->source_id;
					bcast_query_cancel->app_id = s_bin_code->app_id;
					bcast_query_cancel->mode  = 2;
					bcast_query_cancel->forwarder_id = TOS_NODE_ID;

					mode = 2;
					if (HoldTimer == query_cancel) {
						checkTimer = call TimerQueryFired.getNow();
						runningTime = checkTimer - timerStartAt;
						AQQ[query_cancel].query_lifetime = runningTime;			/* krata to running time etsi wste na na upologiseis thn diafora xronoy apo ta alla queries sthn oura */
						call TimerQueryFired.stop();
						call TimerQueryFired.startOneShot(10); //10
					}
					break;
				case 1:												/********** ADD APPLICATION ***********/
					if (number_of_active_apps < MAX_APPLICATIONS) {
						sequence_number++; 											/*seq_num of that message.*/
						while (start < MAX_APPLICATIONS) {
							if (AQQ[start].state == 0) { 							/*run if you are new app ,until the end of the array to find a position into the system*/
								number_of_active_apps++;							/*increase the number of active apps.*/
								AQQ[start].app_id = s_bin_code->app_id;
								memcpy(AQQ[start].BinaryMessage, s_bin_code->BinaryMessage, 30 * sizeof(nx_uint8_t));
								AQQ[start].state = 1;
								AQQ[start].pc = 4; 									/** the Init handler always starts on the fourth position of BinaryMessage, that is 3*/
								break;
							}
							start++;
						}

						AQQ[start].source_id = TOS_NODE_ID; 
						AQQ[start].sequence_number = sequence_number;
						AQQ[start].sampling_id = 0;
						AQQ[start].forwarder_id = TOS_NODE_ID;
						AQQ[start].father_node = TOS_NODE_ID;
						AQQ[start].number_of_children = 0;
						AQQ[start].count_received_children = 0;
						AQQ[start].hops = 0;
						AQQ[start].query_lifetime = s_bin_code->query_lifetime;
						AQQ[start].WaitingTime = OFFSET;
						AQQ[start].RemaingTime = OFFSET;

						sendQuery = start;
						post QueryScheduling();
						/* Configure the Broadcast messasge. */
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
						bcast_pkt->hops = 0;													//AQQ[sendQuery].hops;
						bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
						bcast_pkt->app_id = s_bin_code->app_id;
						memcpy(bcast_pkt->BinaryMessage, s_bin_code->BinaryMessage, 30 * sizeof(nx_uint8_t));
						bcast_pkt->state = s_bin_code->state;
						bcast_pkt->action = s_bin_code->action;
					}
					break;
			}
		}	
		return msg;
	}
	
/* ----------------------------------------------------- RADIO DONE  -------------------------------------------------------- */
	event void RadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;
			send++;
			if (send > SIZE) {
				send = 0;
			}
		}		
	}

	event void SamplingRadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			unicast_busy = FALSE;
			switch (mode) {
				case 0:
					sampling_send++;
					if (sampling_send > SIZE) {
						sampling_send = 0;
					}
					break;
				case 1:
					stats_sampling_send++;
					if (stats_sampling_send > SIZE) {
						stats_sampling_send = 0;
					}
					break;		
			}
			post init_ContributedNodes();
			post Interpretation();
		}		
	}

/* ----------------------------------------------------- SERIAL DONE --------------------------------------------------------- */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;
		}
		post init_ContributedNodes();
		post Interpretation();
	}
}