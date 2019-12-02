#include <string.h>

#include "Timer.h"

#include "QueryRadioFlooding.h"
#include "QueryPacket.h"

#define NUMBER_OF_MSGS 30
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
	query_flooding_msg_t* r_pkt;
	query_flooding_msg_t* bcast_pkt;

	query_msg_t* s_pkt;
	message_t pkt, serial_pkt, query;
	
/* ----------------- msg payload -------------------- */ 
	uint16_t source_id ;
	uint16_t seq_num = 0;
	//uint16_t forwarder_id;
	uint16_t counter = 0;

/* --------------- serial query payload -------------- */
	uint16_t query_id;
	uint16_t sampling_period;
	uint16_t query_lifetime;
	uint16_t propagation_mode;
	
/* --------------- HELPING VARIABLES ----------------- */

/*  8-bit  */
	uint8_t i;
	uint8_t k;
	uint8_t HoldTimer;
	uint8_t send,save;
	uint8_t number_Of_queries;

/*  16-bit  */
	uint16_t t0,dt;
	uint16_t start;
	//uint16_t arrivedTime;
	uint16_t query_pos;
	uint16_t sendQuery;
	uint16_t neighbor_id;
	uint16_t runningTime;
	uint16_t checkTimer;
	uint16_t timerStartAt;

/*  bool  */	
	bool busy = FALSE;
	bool serial_busy = FALSE;


/* ----------------------- ARRAYS -------------------- */	
	uint16_t StateMessages[SIZE];
	uint16_t ActiveQueryQ[3][6];
	message_t PacketBuffer[SIZE];
	//uint16_t NeighborsArray[NEIGHBOR_SIZE][2];

	
/* --------------------------------------------------------- TASKS --------------------------------------------------------- */
	
	task void init_StateMessages() {
		for (start=0; start < SIZE; start++) {
			StateMessages[start] = 0;
		}
	}

	task void init_ActiveQueryQ() {
		for (start=0; start < 3; start++) {
			ActiveQueryQ[start][5] = 0;
		}
	}

/* --------------------------------------------------------- BOOTED -------------------------------------------------------- */		
	event void Boot.booted() {
		i=0;
		send=0;
		save=0;
		query_id=0;
		query_pos=0;
		source_id=0;
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
		StateMessages[TOS_NODE_ID] = query_id;
		//call Leds.led1On();
		
		/*if(StateMessages[TOS_NODE_ID] == 5) {
			call Timer0.stop();
		}*/

		//dbg("BroadcastingC", "New Attempt for BROADCASTING  counter = %hu with seq_num = %hu @ %s.\n\n", counter, StateMessages[TOS_NODE_ID], sim_time_string());
		
		save = save%SIZE;
		bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
		if (bcast_pkt == NULL) {
			return;
		}
		save++;

		bcast_pkt->source_id = ActiveQueryQ[sendQuery][0];		  //TOS_NODE_ID;
		bcast_pkt->query_id = ActiveQueryQ[sendQuery][1];		  //query_id;
		bcast_pkt->forwarder_id = TOS_NODE_ID;
		bcast_pkt->sampling_period = ActiveQueryQ[sendQuery][2];  //sampling_period;
		bcast_pkt->query_lifetime = query_lifetime;	  			  //query_lifetime;
		bcast_pkt->propagation_mode = ActiveQueryQ[sendQuery][4]; //propagation_mode;
		
		if (!busy) {
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			//dbg("BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->counter);
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){
				//call Timer2.startOneShot(10);
				busy = TRUE;
				call Leds.led2On();
				//dbg("BroadcastingC", "START BROADCASTING ... %s.\n\n", sim_time_string());
			}
		}
	}

/* -------------------------------------------- Timer1 =>  Re-BROADCAST ---------------------------------------------------- */ 	
	event void Timer1.fired() {
		if (!busy) {
			//call Leds.led1Off();
			bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[send], sizeof (query_flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			dbg("Re-BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->forwarder_id);
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (query_flooding_msg_t)) == SUCCESS){

				dbg("BroadcastingC", "START Re-BROADCASTING ... %s.\n\n", sim_time_string());

				call Leds.led2On(); // blue
				//dbg("BlinkC", "Led 2 Toggle @%s\n", sim_time_string());
				busy = TRUE;
				send++;
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
			
			s_pkt->sampling_period = sampling_period;
			s_pkt->query_lifetime = call Timer3.getNow();// query_lifetime;
			s_pkt->propagation_mode = propagation_mode;

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
		ActiveQueryQ[HoldTimer][5] = 0;

		if (number_Of_queries > 0) {
			query_pos = 0;
			HoldTimer = 0;
			while (query_pos < 3) {
				if (ActiveQueryQ[query_pos][5] == 1 && ActiveQueryQ[query_pos][3] <= ActiveQueryQ[HoldTimer][3]) {
					HoldTimer = query_pos;
				}
				query_pos++;
			}			
			call Timer3.startOneShot(ActiveQueryQ[HoldTimer][3]);
		}
		else {
			call Leds.led0Off();
			call Timer2.stop();
		}
	}
	
/* --------------------------------------------- RADIO RECEIVE MESSAGES ----------------------------------------------------- */
	event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (query_flooding_msg_t)) {
			r_pkt = (query_flooding_msg_t*) payload;
			//call Leds.led1On();

			dbg("ReceiveC", "RECEIVE MESSAGE : source_id = %hu, forwarder_id = %hu @ %s.\n", r_pkt->source_id, r_pkt->forwarder_id, sim_time_string());

			if (r_pkt->query_id > StateMessages[r_pkt->source_id]) {
				StateMessages[r_pkt->source_id] = r_pkt->query_id;

				if (number_Of_queries < 3) {
					call Leds.led1On();
					number_Of_queries++;

					dbg("ReceiveC", "NEW QUERY \n");

					query_pos = 0;
					while(ActiveQueryQ[query_pos][5] == 1 && query_pos < 3) {
						query_pos++;
					}

					ActiveQueryQ[query_pos][0] = r_pkt->source_id;
					ActiveQueryQ[query_pos][1] = r_pkt->query_id;
					ActiveQueryQ[query_pos][2] = r_pkt->sampling_period;
					ActiveQueryQ[query_pos][4] = r_pkt->propagation_mode;
					ActiveQueryQ[query_pos][5] = 1;

					if (call Timer3.isRunning() == TRUE) {
						checkTimer = call Timer3.getNow();
						runningTime = checkTimer - timerStartAt;
						dt = ActiveQueryQ[HoldTimer][3] - timerStartAt;
						if (dt > r_pkt->query_lifetime) {
							call Timer3.startOneShot(r_pkt->query_lifetime);
	
							ActiveQueryQ[HoldTimer][3] = dt - r_pkt->query_lifetime; //save the remaining time of this query
							ActiveQueryQ[query_pos][3] = r_pkt->query_lifetime;
					
							HoldTimer = query_pos;

						}
						else {
							//remaining_time = query_lifetime - dt;
							ActiveQueryQ[query_pos][3] = r_pkt->query_lifetime - dt;			
						}
					}
					else {
						ActiveQueryQ[query_pos][3] = r_pkt->query_lifetime;
						HoldTimer = query_pos;
						
						call Timer3.startOneShot(r_pkt->query_lifetime); //end query lifetime when timer3 fire
						call Leds.led0On();
						timerStartAt = call Timer3.getNow();
					}

					//sendQuery = query_pos;
					if (call Timer1.isRunning() == TRUE) {
						t0 = call Timer1.gett0();
						dt = call Timer1.getdt();
						call Timer1.startOneShot(t0 + dt);
					}
					else {
						call Timer1.startOneShot(TOS_NODE_ID * 50);
					}

					save = save%SIZE;
					bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
					if (bcast_pkt == NULL) {
						return;
					}
					save++;

					bcast_pkt->source_id = r_pkt->source_id;
					bcast_pkt->query_id = r_pkt->query_id;
					bcast_pkt->forwarder_id = r_pkt->forwarder_id;
					bcast_pkt->sampling_period = r_pkt->sampling_period;
					bcast_pkt->query_lifetime = r_pkt->query_lifetime;
					bcast_pkt->propagation_mode = r_pkt->propagation_mode;
				}	
				//dbg("BlinkC", "Led 2 Toggle @%s\n", sim_time_string());
			}
		}
		/*else if (len == sizeof(sampling_msg_t)) {
			save = save%SIZE;
			bcast_pkt = (query_flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (query_flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			save++;
		}*/
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
				while(ActiveQueryQ[query_pos][5] == 1 && query_pos < 3) {
					query_pos++;
				}
				
				ActiveQueryQ[query_pos][0] = TOS_NODE_ID;
				ActiveQueryQ[query_pos][1] = query_id;
				ActiveQueryQ[query_pos][2] = s_pkt->sampling_period;
				ActiveQueryQ[query_pos][4] = s_pkt->propagation_mode;
				ActiveQueryQ[query_pos][5] = 1;

				if (call Timer3.isRunning() == TRUE) {
					checkTimer = call Timer3.getNow();
					runningTime = checkTimer - timerStartAt;
					dt = ActiveQueryQ[HoldTimer][3] - runningTime;
					if (dt > s_pkt->query_lifetime) {
						call Timer3.startOneShot(s_pkt->query_lifetime);

						ActiveQueryQ[HoldTimer][3] = dt - s_pkt->query_lifetime; //save the remaining time of this query
						ActiveQueryQ[query_pos][3] = s_pkt->query_lifetime;
			
						HoldTimer = query_pos;
					}
					else {
						//remaining_time = query_lifetime - dt;
						ActiveQueryQ[query_pos][3] = s_pkt->query_lifetime - dt;			
					}
				}
				else {
					//call Leds.led2On();
					ActiveQueryQ[query_pos][3] = s_pkt->query_lifetime;
					HoldTimer = query_pos;
					
					call Timer3.startOneShot(s_pkt->query_lifetime); //end query lifetime when timer3 fire
					call Leds.led0On();
					timerStartAt = call Timer3.getNow();
				}
			}	
			
			sendQuery = query_pos;
			query_lifetime = s_pkt->query_lifetime;
			call Timer0.startOneShot(TOS_NODE_ID* 50);
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
			call Leds.led2Off(); // red
			send++;

			/*if(source_id != TOS_NODE_ID){
				if (send < SIZE && save > send) {
				call Timer1.startOneShot(TOS_NODE_ID*50);	
				//send++;
				}
				else {
					send = 0;
				}
			}*/
		}		
	}

/* ----------------------------------------------------- SERIAL DONE --------------------------------------------------------- */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;

			call Leds.led1Off();
			dbg("BroadcastingC", "Finish serial\n\n ");
			
		}
	}
/* ---------------------------------------------------------------------------------------------------------------------------- */	
}
