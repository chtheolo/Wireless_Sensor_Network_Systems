#include <string.h>
#include "Timer.h"

#include "QueryRadioFlooding.h"
#include "QueryPacket.h"
#include "SamplingPacket.h"
#include "StatsSamplingPacket.h"
#include "ActiveQueryQueue.h"
#include "SendersHistory.h"
#include "Contributed_Nodes.h"
#include "ChildrenNodes.h"

#define NUMBER_OF_MSGS 20
#define SIZE 10
#define NUMBER_OF_QUERIES 3
#define LAST_SENDERS 5
#define OFFSET 20


// ftia3e ena pianaka ston opoio na vlepeis apo poiouw perase to paketo 

module QueryPropagationC @safe()
{
	uses interface Boot;
	uses interface Leds;
	uses interface Timer<TMilli> as TimerQueryBroadcast;
	uses interface Timer<TMilli> as TimerReadSensor;
	uses interface Timer<TMilli> as TimerSendPCSerial;
	uses interface Timer<TMilli> as TimerQueryFired;
	uses interface Timer<TMilli> as TimerSimpleMeasurementUcast;
	uses interface Timer<TMilli> as TimerStatsMeasurement_ReUcastSimple;

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
	sampling_msg_t *r_sampling_pkt, *s_sampling_pkt, *ucast_pkt;
	stats_sampling_msg_t *r_stats_sampling_pkt, *s_stats_sampling_pkt, *stats_ucast_pkt;
	query_msg_t* s_pkt;

	message_t pkt, serial_pkt;

/* --------------- serial query payload -------------- */
	
	//uint16_t query_lifetime;
	//uint16_t propagation_mode;
	
/* --------------- HELPING VARIABLES ----------------- */

/*  8-bit  */
	uint8_t send,save;							/* BROADCAST - indicates free pos to save the msg and which msg is ready to send in PacketBuffer[] */
	uint8_t sampling_send, sampling_save;		/* UNICAST - indicates free pos to save the msg and which msg is ready to send in SamplingPacketBuffer[] */
	uint8_t stats_sampling_send;				/* UNICAST - indicates which msg is ready to send in StatsSamplingPacketBuffer[] */
	uint8_t stats_sampling_save;				/* UNICAST - indicates free pos to save the msg in StatsSamplingPacketBuffer[] */
	uint8_t number_Of_queries;					/* Counter to save the number of active queries */
	uint8_t next;								/* Dipicts the next free pos in QuerySendersHistory[] */
	uint8_t WaitingTime;						/* The amount of time, waiting for your children, before forwarding STATS values*/
	uint8_t remindQuery;
	uint8_t divideNumber;
	uint8_t start; //8
	uint8_t HoldTimer; //8
	uint8_t query_pos; // 8
	uint8_t minQuery; // 8
	uint8_t expiredQuery; // 8
	uint8_t sendQuery; // 8
	uint8_t Hold_Sampling_Timer;  //8
	uint8_t sequence_number; // 8
	uint8_t data_id; // 8
	uint8_t s_data_id; // 8
	uint8_t forwarder_id; // 8
	uint8_t destination_id; // 8
	uint8_t hops; // 8
	uint8_t source_id;

/*  16-bit  */
	uint16_t t0,dt;
	uint16_t runningTime;
	uint16_t checkTimer;
	uint16_t timerStartAt;
	uint16_t time4MeasurementStartAt;
	uint16_t minPeriod; 
	uint16_t sendTofather;
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
	uint16_t TimeToMeasure[3]/*, ContributedNodes[SIZE]*/;
	message_t PacketBuffer[SIZE], SamplingPacketBuffer[SIZE], StatsSamplingPacketBuffer[SIZE];
	ActiveQueryQueue_t AQQ[NUMBER_OF_QUERIES];
	SendersHistory_t QuerySendersHistory[LAST_SENDERS];
	contributed_nodes_t ContributedNodes[LAST_SENDERS];
	ChildrenNodes_t Children_Nodes[LAST_SENDERS];

	
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

	task void init_Children_Nodes() {
		for (start = 0; start < LAST_SENDERS; start++) {
			Children_Nodes[start].state = 0;
		}
	}

	task void init_ContributedNodes() {
		for (start = 0; start < LAST_SENDERS; start++) {
			ContributedNodes[start].node_id = 0;
		}
	}

/* ------------------------------------- Query Scheduling --------------------------- */
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
			HoldTimer = sendQuery; //query_pos;
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

			query_pos = 0; //start=0;
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

	//task void DelayMeasurementScheduling() {
	//	if (call TimerSendPCSerial.isRunning() == TRUE) {
	//		dtDelay = call TimerSendPCSerial.getNow();
	//		runningTime = dtDelay - startDelay;
	//		dt = AQQ[remindQuery].
	//	}
	//	else {
	//		
	//	}
	//}

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

				//memcpy(s_sampling_pkt->ContributedNodes, ContributedNodes, SIZE * sizeof(uint16_t));

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
				memcpy(s_stats_sampling_pkt->contributed_ids, ContributedNodes /*r_stats_sampling_pkt->contributed_ids*/, LAST_SENDERS * sizeof(nx_uint8_t));

				query_pos = 0;
				while(query_pos < LAST_SENDERS) {
					if (s_stats_sampling_pkt->contributed_ids[query_pos] == 0) {
						s_stats_sampling_pkt->contributed_ids[query_pos] = TOS_NODE_ID;
						break;
					}
					query_pos++;	
				}
				
				
				if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (stats_sampling_msg_t)) == SUCCESS){
					dbg("BroadcastingC", "Start sending serial packet\n\n ");
					serial_busy = TRUE;
				}
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
		WaitingTime = OFFSET;
		sampling_save = 0;
		sampling_send = 0;
		sequence_number = 0;
		number_Of_queries = 0;

		call Leds.led0Off();
		call Leds.led1Off();
		call Leds.led2Off();

		post init_StateMessages();
		post init_ActiveQueryQ();
		post init_Children_Nodes();
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
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){
				busy = TRUE;
				call Leds.led1On();
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

/* ---------------------------------------------- READ VALUES DONE, SO SEND -------------------------------------------------- */
	event void Read.readDone(error_t result, uint16_t data) {
		if(result == SUCCESS){

			/** Save the position in order to check the propagation_mode when a Timer fired */
			remindQuery = Hold_Sampling_Timer;

			/* IF i am the query originator */
			if (TOS_NODE_ID == AQQ[Hold_Sampling_Timer].source_id) {
				source_id = TOS_NODE_ID;
				s_data_id = data_id;
				forwarder_id = TOS_NODE_ID;

				/*  . . .  */   		/* independs on the propagation_mode */

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

					post DelayMeasurementScheduling();

					call TimerSendPCSerial.startOneShot(WaitingTime + OFFSET);
					startDelay = call TimerSendPCSerial.getNow();
				}		
			}
			else { /* ELSE IF  NOT ORIGINATOR NODE, then forward the values */ 
				
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

					call TimerStatsMeasurement_ReUcastSimple.startOneShot(TOS_NODE_ID * 20);  					   // Timer for Unicast Message - TOS_NODE_ID * 20				
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
					stats_ucast_pkt->contributed_ids[0] = TOS_NODE_ID;
					//query_pos = 1;
					//while (query_pos < LAST_SENDERS) {
					//	if (ContributedNodes[query_pos].node_id == 0) {
					//		ContributedNodes[query_pos] = TOS_NODE_ID;
					//		break;
					//	}
					//	query_pos++;
					//}
					stats_ucast_pkt->mode = 1;

					call TimerStatsMeasurement_ReUcastSimple.startOneShot(WaitingTime);
					startDelay = call TimerStatsMeasurement_ReUcastSimple.getNow();
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

						if (TimeToMeasure[start] <= TimeToMeasure[minPeriod] && TimeToMeasure[start] != 0) {
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
	}

/* ------------------------------------------- TimerQueryFired => Query_Lifetime END ------------------------------------------------- */ 
	event void TimerQueryFired.fired() {
		dbg("QueryC", "The query_%hu expired! @ %s", sim_time_string());

		/*Disable the expired query*/
		number_Of_queries--;
		AQQ[HoldTimer].state = 0; 

		/* Remove every child node for that query */
		start = 0;
		while(start < LAST_SENDERS) {
			if (AQQ[HoldTimer].source_id == Children_Nodes[start].source_id && AQQ[HoldTimer].sequence_number == Children_Nodes[start].sequence_number) {
				Children_Nodes[start].state = 0;
			}
			start++;
		}

		if (number_Of_queries > 0) {
			expiredQuery = HoldTimer;
			minQuery = 0;
			query_pos = 0;
			while (query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].state == 1) {
					AQQ[query_pos].query_lifetime = AQQ[query_pos].query_lifetime - AQQ[expiredQuery].query_lifetime;
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

/* ---------------------------------------- TimerSimpleMeasurementUcast => Re-UNICAST MEASUREMENTS --------------------------------------------- */
	event void TimerSimpleMeasurementUcast.fired() {
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

/* ---------------------------------------- TimerStatsMeasurement_ReUcastSimple => UNICAST MEASUREMENTS --------------------------------------------- */
	event void TimerStatsMeasurement_ReUcastSimple.fired() {
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
				stats_ucast_pkt = (stats_sampling_msg_t*) (call SamplingAMPacket.getPayload(&StatsSamplingPacketBuffer[stats_sampling_send], sizeof (stats_sampling_msg_t)));
				if (stats_ucast_pkt == NULL) {
					return;
				}

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

		/** If i receive a SIMPLE sampling message */
		if (len == sizeof(sampling_msg_t)) {
			r_sampling_pkt = (sampling_msg_t*) payload;

			/** If i receive a msg and i am the MIDDLE node then
			  * i will re-unicast the msg to my father 
			  */
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
				
				call TimerSimpleMeasurementUcast.startOneShot(TOS_NODE_ID * 20); // Re-Unicast the received sampling packet - TOS_NODE_ID * 20
			}
			else {  /* if i am the one who send the query (TOS_NODE_ID == destination_id )then call TimerSendPCSerial to print the values*/
				source_id = r_sampling_pkt->source_id;
				s_data_id =  r_sampling_pkt->data_id;
				forwarder_id = r_sampling_pkt->forwarder_id;
				sensor_data = r_sampling_pkt->sensor_data;
				destination_id = r_sampling_pkt->destination_id;
				sequence_number = r_sampling_pkt->sequence_number;
				//mode = 0;

				call TimerSendPCSerial.startOneShot(20);
			}
		} 
		else if (len == sizeof(stats_sampling_msg_t)) {				/** ELSE if i receive a STATS sampling message */

			r_stats_sampling_pkt = (stats_sampling_msg_t*) payload;

			if (min > r_stats_sampling_pkt->min) {
				min = r_stats_sampling_pkt->min;
			}

			if (max < r_stats_sampling_pkt->max) {
				max = r_stats_sampling_pkt->max;
			}

			/** In order to find the hops distance from the query originator
			  * search AQQ[] in order to find the query originator and the 
			  *	the sequence number. IF SUCCESS then get the correct hops 
			  *	distance in order to find the divideNumber. Alongside i will
			  * find my Father node in order to forward the msg.
			  */
			query_pos = 0;
			while (AQQ[query_pos].source_id != r_stats_sampling_pkt->destination_id && AQQ[query_pos].sequence_number != r_stats_sampling_pkt->sequence_number && query_pos < NUMBER_OF_QUERIES) {
				query_pos++;
			}

			/** SUCCESS - find the N nodes from hops */
			if (query_pos < NUMBER_OF_QUERIES) {
				divideNumber = r_stats_sampling_pkt->hops - AQQ[query_pos].hops;
				average = (max - min) / divideNumber+1;

				/** Save the father node */
				sendTofather = AQQ[query_pos].forwarder_id;
			}

			/** Calculate again the Waiting Time in order to forward the data from all the network. */

			/** Search for that query in my child list, and calculate the wating_time for every child */  
			//start = 0;
			//while (start < LAST_SENDERS) {		/* if the node that send that query msg is in my child list */ 
			//	if (r_stats_sampling_pkt->forwarder_id == Children_Nodes[start].node_id && r_stats_sampling_pkt->destination_id == Children_Nodes[start].source_id && r_stats_sampling_pkt->sequence_number == Children_Nodes[start].sequence_number) {
			//		Children_Nodes[start].waiting_time = divideNumber * OFFSET; //r_stats_sampling_pkt->sum_contributed_ids * OFFSET;
			//		break;
			//	}
			//	start++;
			//}

			// an auto to paidi den to exw sthn lista mou ??

			/** Re-calculate the TOTAL WaitingTime by adding the time that i should wait for every child that belongs in that query. */
			//start =0;
			//WaitingTime = OFFSET; // 0;
			//while (start < LAST_SENDERS) {
			//	if (Children_Nodes[start].state == 1 && Children_Nodes[start].source_id == r_stats_sampling_pkt->destination_id && r_stats_sampling_pkt->sequence_number == Children_Nodes[start].sequence_number){
			//		WaitingTime += Children_Nodes[start].waiting_time;	
			//	}
			//	start++;
			//}		

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
				query_pos = 0;
				while (query_pos < LAST_SENDERS) {
					if (r_stats_sampling_pkt->contributed_ids[query_pos] == 0) {
						stats_ucast_pkt->contributed_ids[query_pos] = TOS_NODE_ID;
						break;
					}
					query_pos++;
				}
				stats_ucast_pkt->mode = 1;

				dtDelay = call TimerStatsMeasurement_ReUcastSimple.getNow();
				WaitingTime = dtDelay - startDelay; 

			}
			else { 			/*If ORIGINATOR NODE, then send to serial*/

				source_id = r_stats_sampling_pkt->source_id;
				s_data_id =  r_stats_sampling_pkt->data_id;
				forwarder_id = r_stats_sampling_pkt->forwarder_id;
				destination_id = r_stats_sampling_pkt->destination_id;
				sequence_number = r_stats_sampling_pkt->sequence_number;

				memcpy(ContributedNodes, r_stats_sampling_pkt->contributed_ids, LAST_SENDERS * sizeof(nx_uint8_t));

				dtDelay = call TimerSendPCSerial.getNow();
				WaitingTime = dtDelay - startDelay;
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

			/** If reached the end of the array,means that it is the  
			  * first time receving a query message from that source_id
			  */
			if (query_pos == LAST_SENDERS) { 
				next = next%LAST_SENDERS;
				//QuerySendersHistory[next].source_id = 0;
				QuerySendersHistory[next].sequence_number = 0;
				QuerySendersHistory[next].source_id = r_pkt->source_id;
				query_pos = next;
			}

			/** I found that the source_id and now i check the 
			  * sequence number to define if it is a unique msg
			  */
			if (r_pkt->sequence_number > QuerySendersHistory[query_pos].sequence_number &&  query_pos < LAST_SENDERS) { //************
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
						AQQ[query_pos].hops = r_pkt->hops + 1;
						AQQ[query_pos].sampling_period = r_pkt->sampling_period;
						AQQ[query_pos].query_lifetime = r_pkt->query_lifetime;
						AQQ[query_pos].propagation_mode = r_pkt->propagation_mode;
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
					bcast_pkt->hops = AQQ[sendQuery].hops;
					bcast_pkt->sampling_period = AQQ[sendQuery].sampling_period;
					bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
					bcast_pkt->propagation_mode = AQQ[sendQuery].propagation_mode;
				}	
			} /** If i have seen that msg before, i try to find if this msg belongs to a child node */
			else if (r_pkt->sequence_number == QuerySendersHistory[query_pos].sequence_number && query_pos < NUMBER_OF_QUERIES) {

				//query_pos = 0;
				//while(/*AQQ[query_pos].state == 1 &&*/ query_pos < NUMBER_OF_QUERIES) {
				//	if (r_pkt->source_id == AQQ[query_pos].source_id && r_pkt->hops < AQQ[query_pos].hops) {
				//		AQQ[query_pos].forwarder_id = r_pkt->forwarder_id;
				//		AQQ[query_pos].hops = r_pkt->hops+1;
				//	}
				//	query_pos++;
				//}
				
				/* Find if that query is active on my system. */
				start = 0;
				while (start < NUMBER_OF_QUERIES) {
					if (AQQ[start].source_id == r_pkt->source_id && AQQ[start].sequence_number == r_pkt->sequence_number){
						WaitingTime = AQQ[start].sampling_period / 2;
						break;
					}
					start++;
				}

				//if (start < NUMBER_OF_QUERIES && r_pkt->hops == AQQ[start].hops+1) {  /* if my distance (hops) + 1 == node distance (hops) -> then that node is my child */
				//	start = 0;
				//	while (Children_Nodes[start].state == 1 && start < LAST_SENDERS){
				//		start++;
				//	}
//
//				//	/* if start counter is smaller than the size LAST_SENDERS then we found an empty seat in our Children_Nodes[] array. */
//				//	if (start < LAST_SENDERS) {  
//				//		Children_Nodes[start].node_id = r_pkt->forwarder_id; 			/* my childs id*/
//				//		Children_Nodes[start].source_id = r_pkt->source_id;				/* the query source id */
//				//		Children_Nodes[start].sequence_number = r_pkt->sequence_number;	/* the query sequence number */
//				//		Children_Nodes[start].state = 1;  								/* active child for that query */
//				//		Children_Nodes[start].waiting_time = 200;//r_pkt->forwarder_id * OFFSET;			/* the time offset id * 20  */
//				//	}
//
//				//	/** Every time i receive a query broadcast, i calculate the 
//				//	  * waiting time. The waiting time for the first iteration 
//				//	  * independs on the number of my children nodes. I have to 
//				//	  * see what children do i have for that query.
//				//	  */
//				//	start =0;
//				//	WaitingTime = OFFSET; 				/* find if i have children in my list for that query msg, and calculate the WaitingTime */
//				//	while (start < LAST_SENDERS) {  
//				//		if (Children_Nodes[start].state == 1 && Children_Nodes[start].source_id == r_pkt->source_id && Children_Nodes[start].sequence_number == r_pkt->sequence_number){
//				//			WaitingTime += Children_Nodes[start].waiting_time;	
//				//		}
//				//		start++;
//				//	}
				//}
			}
		} 
		return msg;
	}

/* -------------------------------------------- QUERY RECEIVE SERIAL MESSAGE ------------------------------------------------------ */
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
				AQQ[query_pos].hops = 0;
				AQQ[query_pos].sampling_period = s_pkt->sampling_period;
				AQQ[query_pos].query_lifetime = s_pkt->query_lifetime;
				AQQ[query_pos].propagation_mode = s_pkt->propagation_mode;
				AQQ[query_pos].state = 1;

				sendQuery = query_pos;

				post QueryScheduling();

				TimeToMeasure[sendQuery] = AQQ[sendQuery].sampling_period;

				post MeasurementScheduling();

				// prepare to re-Broadcast
				save = save%SIZE;
				bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
				if (bcast_pkt == NULL) {
					return;
				}
				save++;

				bcast_pkt->source_id = AQQ[sendQuery].source_id;
				bcast_pkt->sequence_number = AQQ[sendQuery].sequence_number;
				bcast_pkt->forwarder_id = AQQ[sendQuery].forwarder_id;		//TOS_NODE_ID;
				bcast_pkt->hops = 0;//AQQ[sendQuery].hops;
				bcast_pkt->sampling_period = AQQ[sendQuery].sampling_period;
				bcast_pkt->query_lifetime = AQQ[sendQuery].query_lifetime;
				bcast_pkt->propagation_mode = AQQ[sendQuery].propagation_mode;
			}	
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
		}		
	}

/* ----------------------------------------------------- SERIAL DONE --------------------------------------------------------- */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;
		}
	}
/* ---------------------------------------------------------------------------------------------------------------------------- */	
}