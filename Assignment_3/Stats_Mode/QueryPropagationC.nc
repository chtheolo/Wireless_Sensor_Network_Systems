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

#define NUMBER_OF_MSGS 20
#define SIZE 10
#define NUMBER_OF_QUERIES 3
#define LAST_SENDERS 5
#define OFFSET 20

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
	query_flooding_msg_t *r_pkt, *bcast_pkt;
	query_cancel_msg_t *srl_query_cancel, *rcv_query_cacnel, *bcast_query_cancel, *ucast_query_cancel;
	sampling_msg_t *r_sampling_pkt, *s_sampling_pkt, *ucast_pkt;
	stats_sampling_msg_t *r_stats_sampling_pkt, *s_stats_sampling_pkt, *stats_ucast_pkt;
	query_msg_t* s_pkt;
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
	uint8_t i;

/*  16-bit  */
	uint16_t t0,dt;
	uint16_t runningTime;
	uint16_t checkTimer;
	uint16_t timerStartAt;
	uint16_t time4MeasurementStartAt;
	uint16_t minPeriod; 
	uint16_t sensor_data;
	uint16_t min;
	uint16_t max;
	uint16_t average;
	uint16_t startDelay;
	uint16_t dtDelay;

/*  bool  */	
	bool busy = FALSE;
	bool unicast_busy = FALSE;
	bool serial_busy = FALSE;

/* ----------------------- ARRAYS -------------------- */	
	message_t PacketBuffer[SIZE], SamplingPacketBuffer[SIZE], StatsSamplingPacketBuffer[SIZE];//, QueryCancelBuffer[NUMBER_OF_QUERIES];
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
		}
	}

	task void init_ContributedNodes() {
		for (start = 0; start < LAST_SENDERS; start++) {
			ContributedNodes[start].node_id = 0;
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
			if (AQQ[remindQuery].propagation_mode == 0) {
				s_sampling_pkt = (sampling_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (sampling_msg_t) ));
				if (s_sampling_pkt == NULL) {
					return;
				}
				
				s_sampling_pkt->source_id = source_id;
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
			else if (AQQ[remindQuery].propagation_mode == 1) {

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
			AQQ[query_cancel].query_lifetime = runningTime;			/* save how much did it miss running */
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

		call RadioAMControl.start();
		call SerialAMControl.start();
	}
	
/* ------------------------------------------------- RADIO CONTROL ---------------------------------------------------------- */	
	event void RadioAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "RADIO_CONTROL = OK %s.\n", sim_time_string());
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

			if (bcast_pkt->propagation_mode == 2) {
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
/* ------------------------- TimerQueryCancelResponse =>  WAITING UPPER BOUND TIME, WHO SEND CANCEL RESPONSE -------------------------- */ 
	event void TimerQueryCancelResponse.fired() {
		query_pos = 0;
		start=0;
		while (query_pos < LAST_SENDERS) {
			if (AQQ[query_cancel].children[query_pos] != 0){
				send_qcancelTo_node = AQQ[query_cancel].children[query_pos];
				AQQ[query_cancel].children[query_pos] = 0;
				post QueryCancelConfirmation();
				break;
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
		if(result == SUCCESS){
			/** Save what query we are handling */
			remindQuery = Hold_Sampling_Timer;

			/* IF i am the query originator */
			if (TOS_NODE_ID == AQQ[Hold_Sampling_Timer].source_id) {
				source_id = TOS_NODE_ID;
				s_data_id = data_id;
				forwarder_id = TOS_NODE_ID;
							/*  . . .  */   	/* independs on the propagation_mode */
				destination_id = AQQ[Hold_Sampling_Timer].source_id;
				sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;

				if (AQQ[Hold_Sampling_Timer].propagation_mode == 0) {  // SIMPLE mode == 0
					sensor_data = data;

					call TimerSendPCSerial.startOneShot(20);  // to serial send valto kalutera se ena task
				}
				else if (AQQ[Hold_Sampling_Timer].propagation_mode == 1) { // STATS mode == 1
					hops = AQQ[Hold_Sampling_Timer].hops;
					min = data;
					max = data;
					average = data;
					//stats_ucast_pkt->contributed_ids[0] = TOS_NODE_ID;

					post DelayMeasurementScheduling();
				}		
			}
			else { /* ELSE IF  MIDDLE NODE, then read and forward the values */ 
				
				/** My Father Node is the one who send me the query bcast, so i will forward the measurements back to him */
				sendTofather = AQQ[Hold_Sampling_Timer].forwarder_id;	 

				if (AQQ[Hold_Sampling_Timer].propagation_mode == 0) {  // SIMPLE mode == 0
					sampling_save = sampling_save%SIZE;
					ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
					if (ucast_pkt == NULL) {
						return;
					}
					sampling_save++;

					ucast_pkt->source_id = TOS_NODE_ID;
					ucast_pkt->data_id = data_id;
					ucast_pkt->forwarder_id = TOS_NODE_ID;
					ucast_pkt->sensor_data = data;
					ucast_pkt->destination_id = AQQ[Hold_Sampling_Timer].source_id;
					ucast_pkt->sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;
					ucast_pkt->mode = 0;

					call Timer_StatsUnicast_Unicast.startOneShot(TOS_NODE_ID * 20);  					   // Timer for Unicast Message - TOS_NODE_ID * 20				
				}
				else if (AQQ[Hold_Sampling_Timer].propagation_mode == 1) { // STATS mode == 1

					stats_sampling_save = stats_sampling_save%SIZE;
					stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_save], sizeof (stats_sampling_msg_t)));
					if (stats_ucast_pkt == NULL) {
						return;
					}
					stats_sampling_save++;

					stats_ucast_pkt->source_id = TOS_NODE_ID;
					stats_ucast_pkt->data_id = data_id;
					stats_ucast_pkt->forwarder_id = TOS_NODE_ID;
					stats_ucast_pkt->hops = AQQ[Hold_Sampling_Timer].hops;
					stats_ucast_pkt->min = data;
					stats_ucast_pkt->max = data;
					stats_ucast_pkt->average = data;
					stats_ucast_pkt->destination_id = AQQ[Hold_Sampling_Timer].source_id;
					stats_ucast_pkt->sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;
					//stats_ucast_pkt->contributed_ids[0] = TOS_NODE_ID;
					stats_ucast_pkt->mode = 1;

					post DelayMeasurementScheduling();
				}
			}
			data_id++;
			
			if (number_Of_queries > 0) {
			
				expiredQuery = Hold_Sampling_Timer; // this points to the expired query sampling period
				runningTime = TimeToMeasure[expiredQuery];
				minPeriod = 0;
				start = 0;	
				while(start < NUMBER_OF_QUERIES) {
					if (AQQ[start].state == 1) {
						if (start == expiredQuery) {
							TimeToMeasure[start] = AQQ[start].sampling_period; // if finished, initialize again the sampling period
						}
						else {
							TimeToMeasure[start] = TimeToMeasure[start] - runningTime;
						}

						if (TimeToMeasure[start] <= TimeToMeasure[minPeriod] && TimeToMeasure[start] != 0) {	/*find the min but exclude the 0 time */
							Hold_Sampling_Timer = start;
						}
					}
					else {
						minPeriod++; // if in first positions there is no active query,then move on and minPeriod moves on too
					}
					start++;
				}

				call TimerReadSensor.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
				time4MeasurementStartAt = call TimerReadSensor.getNow();
			}
		}
	}

/* ----------------------------------------- TimerSendPCSerial => SERIAL SEND : MOTE -> PC -------------------------------------------- */ 
	event void TimerSendPCSerial.fired() {
		post SendSerial();
		count_received_children = 0;

		if (number_Of_queries > 1) {  /*>1 because if we have one query it is not neccessary to find the wait remaining time.*/
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
			if (AQQ[remindQuery].propagation_mode == 0) {
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
			else if (AQQ[remindQuery].propagation_mode == 1) {
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
				ucast_pkt->data_id = r_sampling_pkt->data_id;
				ucast_pkt->forwarder_id = TOS_NODE_ID;
				ucast_pkt->sensor_data = r_sampling_pkt->sensor_data;
				ucast_pkt->destination_id = r_sampling_pkt->destination_id;
				ucast_pkt->sequence_number = r_sampling_pkt->sequence_number;
				ucast_pkt->mode = 0;
				
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
				s_data_id =  r_sampling_pkt->data_id;
				forwarder_id = r_sampling_pkt->forwarder_id;
				sensor_data = r_sampling_pkt->sensor_data;
				destination_id = r_sampling_pkt->destination_id;
				sequence_number = r_sampling_pkt->sequence_number;

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

				stats_sampling_save = stats_sampling_save%SIZE;
				stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_save], sizeof (stats_sampling_msg_t)));
				if (stats_ucast_pkt == NULL) {
					return;
				}
				stats_sampling_save++;
	 
				stats_ucast_pkt->source_id = r_stats_sampling_pkt->source_id;
				stats_ucast_pkt->data_id = r_stats_sampling_pkt->data_id;
				stats_ucast_pkt->forwarder_id = TOS_NODE_ID;
				stats_ucast_pkt->hops = r_stats_sampling_pkt->hops;
				stats_ucast_pkt->min = min;
				stats_ucast_pkt->max = max;
				stats_ucast_pkt->average = average;
				stats_ucast_pkt->destination_id = r_stats_sampling_pkt->destination_id;
				stats_ucast_pkt->sequence_number = r_stats_sampling_pkt->sequence_number;
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
				AQQ[query_pos].WaitingTime = dtDelay - AQQ[query_pos].startDelay + 100; /** query_pos calculate above and points to the query in whice we receive the measurement ucast.*/
				AQQ[query_pos].RemaingTime = AQQ[query_pos].WaitingTime;

				/*If i got msg from all my children, stop the timer and procceed to serial transmission*/
				if (count_received_children == AQQ[query_pos].number_of_children) { 
					call TimerSendPCSerial.stop();
					call TimerSendPCSerial.startOneShot(20);
				}
			}
		}
		else if (len == sizeof(query_cancel_msg_t)) {
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
				}	
			} /** If i have reveived that msg before, i try to find if this msg belongs to a child node */
			else if (r_pkt->sequence_number == QuerySendersHistory[query_pos].sequence_number && query_pos < NUMBER_OF_QUERIES) {
				/* Find if that query is active on my system. */
				start = 0;
				while (start < NUMBER_OF_QUERIES) {
					if (AQQ[start].source_id == r_pkt->source_id && AQQ[start].sequence_number == r_pkt->sequence_number){
						AQQ[start].WaitingTime = AQQ[start].sampling_period - 1000 ;				/*And set for that query an upper bound for waiting time. */
						AQQ[start].RemaingTime = AQQ[start].WaitingTime;
						AQQ[start].number_of_children++;
						break;
					}
					start++;
				}

				if (r_pkt->father_node == TOS_NODE_ID) {	/* if this node that send me a bcast, has chosen me as his father, then save him in my child list. */
					nextChild = nextChild%LAST_SENDERS;
					AQQ[start].children[nextChild] = r_pkt->forwarder_id;
					nextChild++;
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

			send_qcancelTo_node = AQQ[query_cancel].father_node;
			post QueryCancelConfirmation();			/* Give a response to the father node that send you the query cancelation */
		}
		return msg;
	}

/* -------------------------------------------- QUERY SERIAL RECEIVE MESSAGE ------------------------------------------------------ */
	event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (query_msg_t)) {
			s_pkt = (query_msg_t*) payload;
			
			if (number_Of_queries < NUMBER_OF_QUERIES) {
				number_Of_queries++;
				sequence_number++; // seq_num

				query_pos = 0;
				while(AQQ[query_pos].state == 1 && query_pos < NUMBER_OF_QUERIES) {
					query_pos++;
				}

				AQQ[query_pos].source_id = TOS_NODE_ID; 
				AQQ[query_pos].sequence_number = sequence_number;
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

				TimeToMeasure[sendQuery] = AQQ[sendQuery].sampling_period;		/* save the sampling period */
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
			}	
		}
		else if (len == sizeof(query_cancel_msg_t)) {
			srl_query_cancel = (query_cancel_msg_t*) payload;

			if (number_Of_queries > 0) {
				query_pos = 0;
				while (query_pos < NUMBER_OF_QUERIES) {
					if (AQQ[query_pos].source_id == srl_query_cancel->source_id && AQQ[query_pos].sequence_number == srl_query_cancel->sequence_number && AQQ[query_pos].state == 1) {
						query_cancel = query_pos;
						break;
					}
				}
			}
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
		}
		return msg;
	}
	
/* ----------------------------------------------------- RADIO DONE  -------------------------------------------------------- */
	event void RadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;

			call Leds.led1Off(); // yellow
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