#include <string.h>
#include "Timer.h"

#include "QueryRadioFlooding.h"
#include "QueryPacket.h"
#include "SamplingPacket.h"
#include "ActiveQueryQueue.h"
#include "SendersHistory.h"

#define NUMBER_OF_MSGS 20
#define SIZE 10
#define NUMBER_OF_QUERIES 3
#define LAST_SENDERS 5


// ftia3e ena pianaka ston opoio na vlepeis apo poiouw perase to paketo 

module QueryPropagationC @safe()
{
	uses interface Boot;
	uses interface Leds;
	uses interface Timer<TMilli> as Timer0;
	uses interface Timer<TMilli> as Timer1;
	uses interface Timer<TMilli> as Timer2;
	uses interface Timer<TMilli> as Timer3;
	uses interface Timer<TMilli> as Timer4;
	uses interface Timer<TMilli> as Timer5;

	uses interface Read<uint16_t>;

	uses interface Packet as SamplingAMPacket;
	uses interface AMSend as SamplingRadioAMSend;
	uses interface Receive as SamplingRadioReceive;
 
	uses interface Packet;
	//uses interface AMPacket;
	uses interface AMSend as RadioAMSend;
	uses interface Receive as RadioReceive;
	uses interface SplitControl as RadioAMControl;

	//uses interface SamplingAMPacket;
	//uses interface AMSend as SamplingAMSend;

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
	query_msg_t* s_pkt;

	message_t pkt, serial_pkt;

/* --------------- serial query payload -------------- */
	uint16_t sequence_number;
	//uint16_t sampling_period;
	uint16_t query_lifetime;
	//uint16_t propagation_mode;
	
/* --------------- HELPING VARIABLES ----------------- */

/*  8-bit  */
	uint8_t send,save;
	uint8_t sampling_send, sampling_save;
	uint8_t number_Of_queries;
	uint8_t next;

/*  16-bit  */
	uint16_t t0,dt;
	uint16_t start;
	uint16_t HoldTimer;
	uint16_t query_pos;
	uint16_t minQuery;
	uint16_t expiredQuery;
	uint16_t sendQuery;
	uint16_t curQuery;
	uint16_t runningTime;
	uint16_t checkTimer;
	uint16_t timerStartAt;
	uint16_t time4MeasurementStartAt;
	uint16_t Hold_Sampling_Timer;
	uint16_t minPeriod;
	uint16_t sendTofather;
	uint16_t sensor_data;
	uint16_t source_id;
	uint16_t sequence_number;
	uint16_t data_id;
	uint16_t s_data_id;
	uint16_t forwarder_id;
	uint16_t destination_id;

/*  bool  */	
	bool busy = FALSE;
	bool unicast_busy = FALSE;
	bool serial_busy = FALSE;

/* ----------------------- ARRAYS -------------------- */	
	uint16_t TimeToMeasure[3];
	message_t PacketBuffer[SIZE], SamplingPacketBuffer[SIZE];
	ActiveQueryQueue_t AQQ[NUMBER_OF_QUERIES];
	SendersHistory_t QuerySendersHistory[LAST_SENDERS];

	
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

/* -------------------------------------------------- Query Scheduling --------------------------------------------------- */
	task void QueryScheduling() {
		/* check if i am alone or other queries also running */
		if (call Timer3.isRunning() == TRUE) {
			checkTimer = call Timer3.getNow();
			runningTime = checkTimer - timerStartAt;
			dt = AQQ[HoldTimer].query_lifetime - runningTime; //remaining_time to expire.

			if (dt > AQQ[sendQuery].query_lifetime) {
				HoldTimer = sendQuery; //query_pos;
				call Timer3.startOneShot(AQQ[HoldTimer].query_lifetime);
				timerStartAt = call Timer3.getNow();
				//curQuery = HoldTimer;
			}
			else {
				timerStartAt = call Timer3.getNow();
				//curQuery = sendQuery;
			}

			query_pos = 0;
			while(query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].state == 1 && query_pos != sendQuery /*curQuery*/) {
					AQQ[query_pos].query_lifetime = AQQ[query_pos].query_lifetime - runningTime; //remaining_timer to expire
				}
				query_pos++;
			}
		}
		else {
			HoldTimer = sendQuery; //query_pos;
			call Timer3.startOneShot(AQQ[HoldTimer].query_lifetime); //end query lifetime when timer3 fire
			timerStartAt = call Timer3.getNow();
			call Leds.led0On();
		}
		/* __________________________________________________ */

		if (call Timer0.isRunning() == TRUE) {
			t0 = call Timer0.gett0();
			dt = call Timer0.getdt();
			call Timer0.startOneShot(t0 + dt);
		}
		else {
			call Timer0.startOneShot(TOS_NODE_ID * 50);
		}

	}

/* ----------------------------------------------- Measurement Scheduling -------------------------------------------------- */
	task void MeasurementScheduling() {
		if (call Timer1.isRunning() == TRUE) {
			checkTimer = call Timer1.getNow();
			runningTime = checkTimer - time4MeasurementStartAt;
			dt = TimeToMeasure[Hold_Sampling_Timer] - runningTime;
			
			if (dt > TimeToMeasure[sendQuery]) {
				Hold_Sampling_Timer = sendQuery;
				call Timer1.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
				time4MeasurementStartAt = call Timer1.getNow();
				//curQuery = Hold_Sampling_Timer;
			}
			else {
				time4MeasurementStartAt = call Timer1.getNow();
				//curQuery = sendQuery;
			}

			query_pos = 0; //start=0;
			while( query_pos < NUMBER_OF_QUERIES) {
				if (AQQ[query_pos].state == 1 && query_pos != sendQuery /*curQuery*/) {
					TimeToMeasure[query_pos] = TimeToMeasure[query_pos] - runningTime; 		 //remaining_timer to expire
				}
				query_pos++;
			}
		}
		else {
			Hold_Sampling_Timer = sendQuery;
			call Timer1.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
			time4MeasurementStartAt = call Timer1.getNow();
		}
	}


/* --------------------------------------------------------- BOOTED -------------------------------------------------------- */		
	event void Boot.booted() {
		
		send=0;
		save=0;
		next=0;
		data_id=0;
		query_pos=0;
		sequence_number=0;
		sampling_save = 0;
		sampling_send = 0;
		number_Of_queries=0;

		call Leds.led0Off();
		call Leds.led1Off();
		call Leds.led2Off();

		post init_StateMessages();
		post init_ActiveQueryQ();

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

/* -------------------------------------------- Timer0 =>  SOURCE QUERY BROADCAST ------------------------------------------------- */ 	
	event void Timer0.fired() {
		//dbg("BroadcastingC", "New Attempt for BROADCASTING  counter = %hu with seq_num = %hu @ %s.\n\n", counter, StateMessages[TOS_NODE_ID], sim_time_string());

		// if i am the query message source then save that info to SH
		if (TOS_NODE_ID == bcast_pkt->source_id) {
			next = next%LAST_SENDERS;
			QuerySendersHistory[next].source_id = TOS_NODE_ID;
			QuerySendersHistory[next].sequence_number = bcast_pkt->sequence_number;
			next++;
		}

		if (!busy) {
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			//dbg("BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->counter);
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){
				busy = TRUE;
				call Leds.led1On();
				//dbg("BroadcastingC", "START QUERY BROADCASTING ... %s.\n\n", sim_time_string());
			}
		}
	}

/* -------------------------------------- Timer1 =>  START READING VALUES FROM SENSOR ---------------------------------------- */ 	
	event void Timer1.fired() {
		call Read.read(); /* initiate read op */
		if (AQQ[Hold_Sampling_Timer].state == 0) {
			call Timer1.stop();
		}
	}

/* ---------------------------------------------- READ VALUES DONE, SO SEND -------------------------------------------------- */
	event void Read.readDone(error_t result, uint16_t data) {
		if(result == SUCCESS){

			if (TOS_NODE_ID == AQQ[Hold_Sampling_Timer].source_id) { // if i am the query originator
				
				source_id = TOS_NODE_ID;
				s_data_id = data_id;
				forwarder_id = TOS_NODE_ID;
				sensor_data = data;
				destination_id = AQQ[Hold_Sampling_Timer].source_id;
				sequence_number = AQQ[Hold_Sampling_Timer].sequence_number;
				call Timer2.startOneShot(20);
			}
			else {
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

				sendTofather = AQQ[Hold_Sampling_Timer].forwarder_id;	

				call Timer5.startOneShot(TOS_NODE_ID * 45);
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

				call Timer1.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
				time4MeasurementStartAt = call Timer1.getNow();
			}
		}
	}

/* ----------------------------------------- Timer2 => SERIAL SEND : MOTE -> PC -------------------------------------------- */ 
	event void Timer2.fired() {
		if (!serial_busy) {

			dbg("BroadcastingC", "Enter to serial\n\n ");

			s_sampling_pkt = (sampling_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (sampling_msg_t) ));
			if (s_sampling_pkt == NULL) {
				return;
			}
			
			
			s_sampling_pkt->source_id = source_id; //r_sampling_pkt->source_id; //ActiveQueryQ[sendQuery][4]; //sampling_period;
			s_sampling_pkt->data_id = s_data_id;
			s_sampling_pkt->forwarder_id = forwarder_id;
			s_sampling_pkt->sensor_data = sensor_data; //r_sampling_pkt->sensor_data;       	// query_lifetime;
			s_sampling_pkt->destination_id = destination_id;
			s_sampling_pkt->sequence_number = sequence_number; //r_sampling_pkt->sequence_number; //ActiveQueryQ[sendQuery][6];	//propagation_mode;
			
			dbg("BroadcastingC", "The query_lifetime = %hu \n\n", s_sampling_pkt->source_id);

			if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (sampling_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start sending serial packet\n\n ");
				serial_busy = TRUE;
			}
		}
	}

/* ------------------------------------------- Timer3 => Query_Lifetime END ------------------------------------------------- */ 
	event void Timer3.fired() {
		dbg("QueryC", "The query_%hu expired! @ %s", sim_time_string());

		//disable the expired query
		number_Of_queries--;
		AQQ[HoldTimer].state = 0; 

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
			call Timer3.startOneShot(AQQ[HoldTimer].query_lifetime);
			timerStartAt = call Timer3.getNow();
		}
		else {
			call Leds.led0Off();
			//call Timer2.stop();
		}
	}

/* ---------------------------------------- Timer4 => Re-UNICAST MEASUREMENTS --------------------------------------------- */
	event void Timer4.fired() {
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

/* ---------------------------------------- Timer5 => UNICAST MEASUREMENTS --------------------------------------------- */
	event void Timer5.fired() {
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

/* ----------------------------------------- SAMPLING RADIO RECEIVE MESSAGES ------------------------------------------------ */
	event message_t* SamplingRadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(sampling_msg_t)) {
			r_sampling_pkt = (sampling_msg_t*) payload;
			if (r_sampling_pkt->destination_id != TOS_NODE_ID) {

				sampling_save = sampling_save%SIZE;
				ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&SamplingPacketBuffer[sampling_save], sizeof (sampling_msg_t)));
				if (ucast_pkt == NULL) {
					return;
				}
				sampling_save++;

				ucast_pkt->source_id = r_sampling_pkt->source_id;
				ucast_pkt->data_id = r_sampling_pkt->data_id;
				ucast_pkt->forwarder_id = TOS_NODE_ID; 					//r_sampling_pkt->forwarder_id; //TOS_NODE_ID
				ucast_pkt->sensor_data = r_sampling_pkt->sensor_data;
				ucast_pkt->destination_id = r_sampling_pkt->destination_id;
				ucast_pkt->sequence_number = r_sampling_pkt->sequence_number;

				query_pos = 0;
				while (AQQ[query_pos].source_id != r_sampling_pkt->destination_id && AQQ[query_pos].sequence_number != r_sampling_pkt->sequence_number && query_pos < NUMBER_OF_QUERIES) {
					query_pos++;
				}
				if (query_pos < NUMBER_OF_QUERIES) {
					sendTofather = AQQ[query_pos].forwarder_id;
				}
				
				call Timer4.startOneShot(TOS_NODE_ID * 20); // Re-Unicast the received sampling packet
			}
			else {  // if i am the one who send the query  TOS_NODE_ID == destination_id then call Timer2 to print the values
				source_id = r_sampling_pkt->source_id;
				s_data_id =  r_sampling_pkt->data_id;
				forwarder_id = r_sampling_pkt->forwarder_id;
				sensor_data = r_sampling_pkt->sensor_data;
				destination_id = r_sampling_pkt->destination_id;
				sequence_number = r_sampling_pkt->sequence_number;
				call Timer2.startOneShot(20);
			}
		}
		return msg;
	}

/* ------------------------------------------- QUERY RADIO RECEIVE MESSAGES ------------------------------------------------- */
	event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(query_flooding_msg_t)) {
			r_pkt = (query_flooding_msg_t*) payload;

			//dbg("ReceiveC", "RECEIVE MESSAGE : source_id = %hu, forwarder_id = %hu @ %s.\n", r_pkt->source_id, r_pkt->forwarder_id, sim_time_string());

			// Check if i have already taken a query message from this source_id
			query_pos = 0;
			while (QuerySendersHistory[query_pos].source_id != r_pkt->source_id && query_pos < LAST_SENDERS) {
				query_pos++;
			}

			if (query_pos == LAST_SENDERS) {  // if reached the end of the array, means that its the first time receving query message from that source_id
				next = next%LAST_SENDERS;
				QuerySendersHistory[next].source_id = r_pkt->source_id;
				query_pos = next;
				next++;
			}

			if (query_pos < LAST_SENDERS && r_pkt->sequence_number > QuerySendersHistory[query_pos].sequence_number) {
				QuerySendersHistory[query_pos].sequence_number = r_pkt->sequence_number;

				if (number_Of_queries < NUMBER_OF_QUERIES) {
					number_Of_queries++;

					dbg("ReceiveC", "NEW QUERY \n");

					query_pos = 0;
					while(AQQ[query_pos].state == 1 && query_pos < NUMBER_OF_QUERIES) {
						query_pos++;
					}

					AQQ[query_pos].source_id = r_pkt->source_id; 
					AQQ[query_pos].sequence_number = r_pkt->sequence_number;
					AQQ[query_pos].forwarder_id = r_pkt->forwarder_id; // father
					AQQ[query_pos].hops = r_pkt->hops + 1;
					AQQ[query_pos].sampling_period = r_pkt->sampling_period;
					AQQ[query_pos].query_lifetime = r_pkt->query_lifetime;
					AQQ[query_pos].propagation_mode = r_pkt->propagation_mode;
					AQQ[query_pos].state = 1;

					sendQuery = query_pos;

					post QueryScheduling();

					TimeToMeasure[sendQuery] = AQQ[sendQuery].sampling_period; //ActiveQueryQ[query_pos][4];
					
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
				//dbg("BlinkC", "Led 2 Toggle @%s\n", sim_time_string());
			}
			else if (query_pos < NUMBER_OF_QUERIES && r_pkt->sequence_number == QuerySendersHistory[query_pos].sequence_number){
				
				r_pkt->hops++;
				query_pos = 0;
				while(AQQ[query_pos].state == 1 && query_pos < NUMBER_OF_QUERIES) {
					if (r_pkt->source_id == AQQ[query_pos].source_id && r_pkt->hops < AQQ[query_pos].hops) { /*&& r_pkt->sequence_number == AQQ[query_pos].sequence_number*/ //sequence_number and source_id
						AQQ[query_pos].forwarder_id = r_pkt->forwarder_id;
						AQQ[query_pos].hops = r_pkt->hops;
					}
					query_pos++;
				}
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
				bcast_pkt->hops = AQQ[sendQuery].hops;
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

			//dbg("BlinkC", "Led 0 Toggle @%s\n", sim_time_string());
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
			sampling_send++;
			if (sampling_send > SIZE) {
				sampling_send = 0;
			}

			//dbg("BlinkC", "Led 0 Toggle @%s\n", sim_time_string());
		}		
	}

/* ----------------------------------------------------- SERIAL DONE --------------------------------------------------------- */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;
			dbg("BroadcastingC", "Serial message Done\n\n ");
		}
	}
/* ---------------------------------------------------------------------------------------------------------------------------- */	
}