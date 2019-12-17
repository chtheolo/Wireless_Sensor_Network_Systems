#include <string.h>
#include "Timer.h"

#include "QueryRadioFlooding.h"
#include "QueryPacket.h"
#include "SamplingPacket.h"

#define NUMBER_OF_MSGS 20
#define SIZE 10
#define NEIGHBOR_SIZE 10
#define mpos 5

module QueryPropagationC @safe()
{
	uses interface Boot;
	uses interface Leds;
	uses interface Timer<TMilli> as Timer0;
	uses interface Timer<TMilli> as Timer1;
	uses interface Timer<TMilli> as Timer2;
	uses interface Timer<TMilli> as Timer3;

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
	sampling_msg_t *r_sampling_pkt, *ucast_pkt;
	query_msg_t* s_pkt;

	message_t pkt, serial_pkt/*, query*/;
	
/* ----------------- msg payload -------------------- */ 
	//uint16_t source_id ;
	//uint16_t seq_num = 0;
	//uint16_t forwarder_id;
	//uint16_t counter = 0;

/* --------------- serial query payload -------------- */
	uint16_t query_id;
	//uint16_t sampling_period;
	uint16_t query_lifetime;
	//uint16_t propagation_mode;
	
/* --------------- HELPING VARIABLES ----------------- */

/*  8-bit  */
	uint8_t send,save;
	uint8_t number_Of_queries;

/*  16-bit  */
	uint16_t t0,dt;
	uint16_t start;
	uint16_t data_id;
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
	uint16_t timer1_call;
	uint16_t timer4_call;
	uint16_t timer5_call;

/*  bool  */	
	bool busy = FALSE;
	bool serial_busy = FALSE;

/* ----------------------- ARRAYS -------------------- */	
	uint16_t StateMessages[NEIGHBOR_SIZE];
	uint16_t ActiveQueryQ[3][8];
	uint16_t TimeToMeasure[3];
	message_t PacketBuffer[SIZE], SamplingPacketBuffer[SIZE];

	
/* %% ------------------------------------------------------ TASKS --------------------------------------------------- %% */
	
	task void init_StateMessages() {
		for (start=0; start < NEIGHBOR_SIZE; start++) {
			StateMessages[start] = 0;
		}
	}

	task void init_ActiveQueryQ() {
		for (start=0; start < 3; start++) {
			ActiveQueryQ[start][7] = 0;
		}
	}

/* -------------------------------------------------- Query Scheduling --------------------------------------------------- */
	task void QueryScheduling() {

/*__________check if i am alone or other queries also running_________ */
		if (call Timer3.isRunning() == TRUE) {
			checkTimer = call Timer3.getNow();
			runningTime = checkTimer - timerStartAt;
			dt = ActiveQueryQ[HoldTimer][5] - runningTime; //remaining_time to expire.

			if (dt > ActiveQueryQ[query_pos][5]) {
				HoldTimer = query_pos;
				call Timer3.startOneShot(ActiveQueryQ[HoldTimer][5]);
				timerStartAt = call Timer3.getNow();
				curQuery = HoldTimer;
			}
			else {
				timerStartAt = call Timer3.getNow();
				curQuery = sendQuery;
			}

			query_pos = 0;
			while(query_pos < 3) {
				if (ActiveQueryQ[query_pos][7]==1 && query_pos != curQuery) {
					ActiveQueryQ[query_pos][5] = ActiveQueryQ[query_pos][5] - runningTime; //remaining_timer to expire
				}
				query_pos++;
			}
		}
		else {
			HoldTimer = query_pos;
			call Timer3.startOneShot(ActiveQueryQ[HoldTimer][5]); //end query lifetime when timer3 fire
			call Leds.led0On();
			timerStartAt = call Timer3.getNow();
		}
		/* __________________________________________________ */

		if (call Timer0.isRunning() == TRUE) {
			t0 = call Timer0.gett0();
			dt = call Timer0.getdt();
			call Timer0.startOneShot(t0 + dt);
		}
		else {
			call Timer0.startOneShot(TOS_NODE_ID * 50);
			//post MeasurementScheduling();
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
				curQuery = Hold_Sampling_Timer;
			}
			else {
				time4MeasurementStartAt = call Timer1.getNow();
				curQuery = sendQuery;
			}

			start=0;
			while( start < 3) {
				if (ActiveQueryQ[start][7]==1 && start != curQuery) {
					TimeToMeasure[start] = TimeToMeasure[start] - runningTime; //remaining_timer to expire
				}
				start++;
			}
		}
		else {
			Hold_Sampling_Timer = sendQuery;
			//TimeToMeasure[Hold_Sampling_Timer] = ActiveQueryQ[sendQuery][4];
			call Timer1.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
			time4MeasurementStartAt = call Timer1.getNow();
		}
	}

	task void NextSampling() {
		if (number_Of_queries > 0) {
			start = 0;
			minPeriod = 0;
			expiredQuery = Hold_Sampling_Timer;
			while(start < 3) {
				if (ActiveQueryQ[start][7] == 1) {
					TimeToMeasure[start] -= TimeToMeasure[expiredQuery];
					if (TimeToMeasure[start] <= TimeToMeasure[minPeriod] && TimeToMeasure[start] != 0) {
						minPeriod = start;
					}
				}
				else {
					minPeriod++; // if in first positions there is no active query,then move on and minPeriod moves on too
				}
				start++;
			}
			if (ActiveQueryQ[expiredQuery][7] == 1) {
				TimeToMeasure[expiredQuery] = ActiveQueryQ[expiredQuery][4]; // update the TimeToMeasure
			}

			call Timer1.startOneShot(TimeToMeasure[minPeriod]);
			time4MeasurementStartAt = call Timer1.getNow();
		}
	}


/* --------------------------------------------------------- BOOTED -------------------------------------------------------- */		
	event void Boot.booted() {
		//i=0;
		send=0;
		save=0;
		data_id=0;
		query_id=0;
		query_pos=0;
		//source_id=0;
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

/* -------------------------------------------- Timer0 =>  SOURCE  BROADCAST ------------------------------------------------- */ 	
	event void Timer0.fired() {
		//dbg("BroadcastingC", "New Attempt for BROADCASTING  counter = %hu with seq_num = %hu @ %s.\n\n", counter, StateMessages[TOS_NODE_ID], sim_time_string());
		
		StateMessages[TOS_NODE_ID] = query_id;
		
		if (!busy) {
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			//dbg("BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->counter);
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){
				//call Timer2.startOneShot(10);
				busy = TRUE;
				call Leds.led1On();
				//dbg("BroadcastingC", "START BROADCASTING ... %s.\n\n", sim_time_string());
			}
		}
	}

/* -------------------------------------- Timer1 =>  START READING VALUES FROM SENSOR ---------------------------------------- */ 	
	event void Timer1.fired() {
		call Read.read(); /* initiate read op */
		if (ActiveQueryQ[Hold_Sampling_Timer][7] == 0) {
			call Timer1.stop();
		}
	}


/* ---------------------------------------------- READ VALUES DONE, SO SEND ----------------------------------------------- */
	event void Read.readDone(error_t result, uint16_t data) {
		if(result == SUCCESS){
			if (!busy) {

				ucast_pkt = (sampling_msg_t*) (call SamplingAMPacket.getPayload(&pkt/*PacketBuffer[send]*/, sizeof (sampling_msg_t)));
				if (ucast_pkt == NULL) {
					return;
				}
				//memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

				ucast_pkt->source_id = TOS_NODE_ID;
				ucast_pkt->forwarder_id = TOS_NODE_ID;
				ucast_pkt->data_id = data_id;
				ucast_pkt->sensor_data = data;
				
				data_id++;
				if (number_Of_queries > 0) {
					expiredQuery = Hold_Sampling_Timer;
					runningTime = TimeToMeasure[expiredQuery];
					minPeriod = 0;
					start = 0;
					while(start < 3) {
						if (ActiveQueryQ[start][7] == 1) {
							if (start == expiredQuery) {
								TimeToMeasure[start] = ActiveQueryQ[start][4]; // if finished, initialize again the sampling period
							}
							else {
								TimeToMeasure[start] -= runningTime;
							}
							if (TimeToMeasure[start] <= TimeToMeasure[minPeriod] /*&& TimeToMeasure[start] != 0*/) {
								Hold_Sampling_Timer = start;
							}
						}
						else {
							minPeriod++; // if in first positions there is no active query,then move on and minPeriod moves on too
						}
						start++;
					}
					//if (ActiveQueryQ[expiredQuery][7] == 1) {
					//	TimeToMeasure[expiredQuery] = ActiveQueryQ[expiredQuery][4]; // update the TimeToMeasure
					//}

					call Timer1.startOneShot(TimeToMeasure[Hold_Sampling_Timer]);
					time4MeasurementStartAt = call Timer1.getNow();
				}

				//post NextSampling();

				if (call SamplingRadioAMSend.send(ActiveQueryQ[expiredQuery][2], &pkt, sizeof (sampling_msg_t)) == SUCCESS){
					busy = TRUE;
					call Leds.led2On();
				}
			}
		}

	}

/* ----------------------------------------- Timer2 => SERIAL SEND : MOTE -> PC -------------------------------------------- */ 
	event void Timer2.fired() {
		if (!serial_busy) {

			dbg("BroadcastingC", "Enter to serial\n\n ");

			s_pkt = (query_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (query_msg_t) ));
			if (s_pkt == NULL) {
				return;
			}
			
			s_pkt->sampling_period = ActiveQueryQ[sendQuery][4]; 	//sampling_period;
			s_pkt->query_lifetime =call Timer3.getNow();        	// query_lifetime;
			s_pkt->propagation_mode = ActiveQueryQ[sendQuery][6];	//propagation_mode;

			dbg("BroadcastingC", "The query_lifetime = %hu \n\n", s_pkt->query_lifetime);

			if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (query_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start sending serial packet\n\n ");
				serial_busy = TRUE;
			}
		}
	}

/* ------------------------------------------- Timer3 => Query_Lifetime END ------------------------------------------------- */ 
	event void Timer3.fired() {
		dbg("QueryC", "The query_%hu expired! @ %s", sim_time_string());

		//remove the expired query
		number_Of_queries--;
		ActiveQueryQ[HoldTimer][7] = 0; // 5

		if (number_Of_queries > 0) {
			expiredQuery = HoldTimer;
			minQuery = 0;
			query_pos = 0;
			while (query_pos < 3) {
				if (ActiveQueryQ[query_pos][7] == 1) {
					ActiveQueryQ[query_pos][5] = ActiveQueryQ[query_pos][5] - ActiveQueryQ[expiredQuery][5];
					if (ActiveQueryQ[query_pos][5] <= ActiveQueryQ[minQuery][5] && ActiveQueryQ[query_pos][5] != 0) {
						HoldTimer = query_pos;
					}
				}
				else {
					minQuery++;
				}
				query_pos++;
			}			
			call Timer3.startOneShot(ActiveQueryQ[HoldTimer][5]);
			timerStartAt = call Timer3.getNow();
		}
		else {
			call Leds.led0Off();
			//call Timer2.stop();
		}
	}
/* ----------------------------------------- SAMPLING RADIO RECEIVE MESSAGES ------------------------------------------------ */
	event message_t* SamplingRadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(sampling_msg_t)) {
			//call Leds.led2Toggle();
			r_sampling_pkt = (sampling_msg_t*) payload;
			if (r_sampling_pkt->source_id != TOS_NODE_ID) {
				dbg("ReceiveC", "Do nothing!\n");
			}
		}
		return msg;
	}

/* ------------------------------------------- QUERY RADIO RECEIVE MESSAGES ------------------------------------------------- */
	event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(query_flooding_msg_t)) {
			r_pkt = (query_flooding_msg_t*) payload;

			//dbg("ReceiveC", "RECEIVE MESSAGE : source_id = %hu, forwarder_id = %hu @ %s.\n", r_pkt->source_id, r_pkt->forwarder_id, sim_time_string());

			if (r_pkt->query_id > StateMessages[r_pkt->source_id]) {
				StateMessages[r_pkt->source_id] = r_pkt->query_id;

				if (number_Of_queries < 3) {
					//call Leds.led1On();
					number_Of_queries++;

					dbg("ReceiveC", "NEW QUERY \n");

					query_pos = 0;
					while(ActiveQueryQ[query_pos][7] == 1 && query_pos < 3) {
						query_pos++;
					}
					sendQuery = query_pos;

					ActiveQueryQ[query_pos][0] = r_pkt->source_id;
					ActiveQueryQ[query_pos][1] = r_pkt->query_id;
					ActiveQueryQ[query_pos][2] = r_pkt->forwarder_id;
					ActiveQueryQ[query_pos][3] = r_pkt->hops+1;
					ActiveQueryQ[query_pos][4] = r_pkt->sampling_period;  // 2
					ActiveQueryQ[query_pos][5] = r_pkt->query_lifetime; // 3 
					ActiveQueryQ[query_pos][6] = r_pkt->propagation_mode; //4
					ActiveQueryQ[query_pos][7] = 1; // 5

					post QueryScheduling();

					save = save%SIZE;
					bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
					if (bcast_pkt == NULL) {
						return;
					}
					save++;

					bcast_pkt->source_id = ActiveQueryQ[query_pos][0];	   		//r_pkt->source_id;
					bcast_pkt->query_id = ActiveQueryQ[query_pos][1];         	//r_pkt->query_id;
					bcast_pkt->forwarder_id = TOS_NODE_ID;
					bcast_pkt->hops = ActiveQueryQ[query_pos][3];				//hops
					bcast_pkt->sampling_period = ActiveQueryQ[query_pos][4]; 	//r_pkt->sampling_period;
					bcast_pkt->query_lifetime = ActiveQueryQ[query_pos][5];		//r_pkt->query_lifetime;
					bcast_pkt->propagation_mode = ActiveQueryQ[query_pos][6];	//r_pkt->propagation_mode;

					
					TimeToMeasure[query_pos] = ActiveQueryQ[query_pos][4];

					timer1_call = sendQuery;
					//if (call Timer1.isRunning() != TRUE) {
					//	timer1_call = sendQuery;
					//	call Timer1.startPeriodic(ActiveQueryQ[sendQuery][4]);
					//}
					//else if (call Timer4.isRunning() != TRUE) {
					//	timer4_call = sendQuery;
					//	call Timer4.startPeriodic(ActiveQueryQ[sendQuery][4]);
					//}
					//else if (call Timer5.isRunning() != TRUE) {
					//	timer5_call = sendQuery;
					//	call Timer5.startPeriodic(ActiveQueryQ[sendQuery][4]);
					//}
					post MeasurementScheduling();

				}	
				//dbg("BlinkC", "Led 2 Toggle @%s\n", sim_time_string());
			}
			else {
				query_pos = 0;
				r_pkt->hops++;
				while(ActiveQueryQ[query_pos][7] == 1 && query_pos < 3) {
					if (r_pkt->forwarder_id == ActiveQueryQ[query_pos][2] && r_pkt->hops < ActiveQueryQ[query_pos][3]) {
						ActiveQueryQ[query_pos][2] = r_pkt->forwarder_id;
						ActiveQueryQ[query_pos][3] = r_pkt->hops;
					}
					query_pos++;
				}
			}
		}
		return msg;
	}

/* -------------------------------------------- RECEIVE SERIAL MESSAGE ------------------------------------------------------ */
	event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (query_msg_t)) {
			s_pkt = (query_msg_t*) payload;
			
			if (number_Of_queries < 3) {
				number_Of_queries++;

				query_id++;
				query_pos = 0;
				while(ActiveQueryQ[query_pos][7] == 1 && query_pos < 3) {
					query_pos++;
				}
				
				sendQuery = query_pos;
				query_lifetime = s_pkt->query_lifetime;

				ActiveQueryQ[query_pos][0] = TOS_NODE_ID;
				ActiveQueryQ[query_pos][1] = query_id;
				ActiveQueryQ[query_pos][2] = r_pkt->forwarder_id;
				ActiveQueryQ[query_pos][3] = r_pkt->hops+1;
				ActiveQueryQ[query_pos][4] = s_pkt->sampling_period; //2
				ActiveQueryQ[query_pos][5] = s_pkt->query_lifetime; //3
				ActiveQueryQ[query_pos][6] = s_pkt->propagation_mode; //4
				ActiveQueryQ[query_pos][7] = 1; // 5
				//ActiveQueryQ[query_pos][6] = 0; // 6

				post QueryScheduling();

				save = save%SIZE;
				bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
				if (bcast_pkt == NULL) {
					return;
				}
				save++;

				bcast_pkt->source_id = ActiveQueryQ[sendQuery][0];		  //TOS_NODE_ID;
				bcast_pkt->query_id = ActiveQueryQ[sendQuery][1];		  //query_id;
				bcast_pkt->forwarder_id = TOS_NODE_ID;
				bcast_pkt->hops = ActiveQueryQ[query_pos][3];			  //hops;
				bcast_pkt->sampling_period = ActiveQueryQ[sendQuery][4];  //sampling_period;
				bcast_pkt->query_lifetime = ActiveQueryQ[sendQuery][5];	  //query_lifetime;
				bcast_pkt->propagation_mode = ActiveQueryQ[sendQuery][6]; //propagation_mode;
				//bcast_pkt->hops = ActiveQueryQ[query_pos][6];			  //hops;
			}	
			
			//call Timer0.startOneShot(TOS_NODE_ID* 50);
			//call Timer2.startPeriodic(1000);
			call Timer2.startOneShot(1000);
			
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
		}		
	}

	event void SamplingRadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;

			call Leds.led2Off(); // blue
	
			//post NextSampling();

			//dbg("BlinkC", "Led 0 Toggle @%s\n", sim_time_string());
		}		
	}

/* ----------------------------------------------------- SERIAL DONE --------------------------------------------------------- */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;

			//call Leds.led1Off();
			dbg("BroadcastingC", "Finish serial\n\n ");
			
		}
	}
/* ---------------------------------------------------------------------------------------------------------------------------- */	
}