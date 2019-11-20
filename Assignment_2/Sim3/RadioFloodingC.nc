#include "Timer.h"

#include "RadioFlooding.h"
#include "SerialPacket.h"

#define NUMBER_OF_MSGS 30
#define SIZE 10
#define NEIGHBOR_SIZE 10
#define mpos 5

module RadioFloodingC @safe()
{
	uses interface Boot;
	uses interface Leds;
	uses interface Timer<TMilli> as Timer0;
	uses interface Timer<TMilli> as Timer1;
	uses interface Timer<TMilli> as Timer2;
	//uses interface Timer<TMilli> as Timer3;
 
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
	flooding_msg_t* r_pkt;
	flooding_msg_t* bcast_pkt;
	serial_msg_t* s_pkt;
	message_t pkt;
	message_t serial_pkt;
	
/* ----------------- msg payload -------------------- */ 
	uint16_t source_id ;
	uint16_t seq_num = 0;
	//uint16_t forwarder_id;
	uint16_t counter = 0;
	
/* ---------------HELPING VARIABLES ----------------- */


/* ............. 8-bit .............. */
	uint8_t i;
	uint8_t k;
	uint8_t leds;
	uint8_t send,save;

/* ............ 16-bit .............. */
	uint16_t last_pos=0;
	uint16_t start;
	uint16_t neighbor_id;
	uint16_t startTime;
	uint16_t t0,dt;

/* .............. bool .............. */	
	bool busy = FALSE;
	bool serial_busy = FALSE;


/* ----------------------- ARRAYS -------------------- */	
	uint16_t StateMessages[SIZE];
	message_t PacketBuffer[SIZE];
	//uint16_t NeighborsArray[NEIGHBOR_SIZE][2];


	
/* ------------------------------------------------- TASKS ---------------------------------------------------- */
	
	task void init_StateMessages() {
		for (start=0; start < NEIGHBOR_SIZE; start++) {
			StateMessages[start] = 0;
		}
	}


/* ------------------------------------------------- BOOTED --------------------------------------------------- */		
	event void Boot.booted() {
		i=0;
		send=0;
		save=0;
		source_id=0;

		call Leds.led0Off();
		call Leds.led1Off();
		call Leds.led2Off();

		post init_StateMessages();

		call RadioAMControl.start();
		call SerialAMControl.start();

		if (TOS_NODE_ID == 1) {
			call Timer0.startPeriodic(TOS_NODE_ID*250);
			//call Timer2.startPeriodic(TOS_NODE_ID*50);
		}
	}
	
/* ------------------------------------------------- RADIO CONTROL ------------------------------------------------ */	
	event void RadioAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "RADIO_CONTROL = OK %s.\n", sim_time_string());
		}
		else {
			call RadioAMControl.start();
		}
	}
	
	event void RadioAMControl.stopDone(error_t err) { /* do nothing */ }

/* ------------------------------------------------- SERIAL CONTROL ------------------------------------------------ */
	event void SerialAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "SERIAL_CONTROL = OK %s.\n", sim_time_string());
		}
		else {
			call SerialAMControl.start();
		}
	}
	
	event void SerialAMControl.stopDone(error_t err) { /* do nothing */ }

/* -------------------------------------------- Timer0 =>  SOURCE  BROADCAST --------------------------------------------------- */ 	
	event void Timer0.fired() {
		StateMessages[TOS_NODE_ID]++;
		counter++;
		
		if(StateMessages[TOS_NODE_ID] == 5) {
			call Timer0.stop();
		}

		dbg("BroadcastingC", "New Attempt for BROADCASTING  counter = %hu with seq_num = %hu @ %s.\n\n", counter, StateMessages[TOS_NODE_ID], sim_time_string());
		
		if (save < SIZE) {
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}	
		}
		else {
			save=0;
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
		}
		save++;

		bcast_pkt->source_id = TOS_NODE_ID;
		bcast_pkt->seq_num = StateMessages[TOS_NODE_ID];
		bcast_pkt->forwarder_id = TOS_NODE_ID;
		bcast_pkt->counter = counter;
		
		if (!busy) {
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			dbg("BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->counter);
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt , sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "START BROADCASTING ... %s.\n\n", sim_time_string());
				startTime = call Timer2.getNow();
				call Timer2.startOneShot(10);
				
				call Leds.led0Toggle(); // red
				dbg("BlinkC", "Led 0 Toggle @%s\n", sim_time_string());
				busy = TRUE;
				send++;
			}
		}
	}

/* -------------------------------------------- Timer1 =>  Re-BROADCAST --------------------------------------------------- */ 	
	event void Timer1.fired() {
		if (!busy) {
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[send], sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			dbg("Re-BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->counter);
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (flooding_msg_t)) == SUCCESS){

				dbg("BroadcastingC", "START Re-BROADCASTING ... %s.\n\n", sim_time_string());

				//call Leds.led2Toggle(); // blue
				//dbg("BlinkC", "Led 2 Toggle @%s\n", sim_time_string());
				busy = TRUE;
				send++;
			}
		}
	}

/* ----------------------------------------- Timer2 => SERIAL SEND : MOTE -> PC ----------------------------------------- */ 
	event void Timer2.fired() {
		if (!serial_busy) {

			dbg("BroadcastingC", "Enter to serial\n\n ");

			s_pkt = (serial_msg_t*) (call SerialPacket.getPayload(&serial_pkt, sizeof (serial_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			//s_pkt->data = startTime;
			s_pkt->data = counter;

			dbg("BroadcastingC", "The counter = %hu \n\n", s_pkt->data);

			if (call SerialAMSend.send(AM_BROADCAST_ADDR, &serial_pkt, sizeof (serial_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start sending serial packet\n\n ");
				serial_busy = TRUE;
			}
		}
	}
	
/* -------------------------------------------- RADIO RECEIVE MESSAGES ------------------------------------------------- */
	event message_t* RadioReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (flooding_msg_t)) {
			r_pkt = (flooding_msg_t*) payload;

			dbg("ReceiveC", "RECEIVE MESSAGE : source_id = %hu , seq_num = %hu, forwarder_id = %hu, counter = %hu @ %s.\n", r_pkt->source_id, r_pkt->seq_num, r_pkt->forwarder_id, r_pkt->counter, sim_time_string());

			if (r_pkt->seq_num > StateMessages[r_pkt->source_id]) {
				StateMessages[r_pkt->source_id] = r_pkt->seq_num;

				dbg("ReceiveC", "NEW MESSAGE \n");

				call Leds.led2Toggle(); // blue
				dbg("BlinkC", "Led 2 Toggle @%s\n", sim_time_string());

				if (save < SIZE) {
					bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
					save++;
				}
				else {
					save=0;
					bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
					save++;					
				}

				bcast_pkt->source_id = r_pkt->source_id;
				bcast_pkt->seq_num = r_pkt->seq_num;
				bcast_pkt->forwarder_id = TOS_NODE_ID;
				bcast_pkt->counter = r_pkt->counter;

				//array gia na vazw to xrono remaining toy kathe minimatos ,gia na kalw ton timer me auton ton xrono
				
				if (call Timer1.isRunning() == TRUE) {
					t0 = call Timer1.gett0();
					dt = call Timer1.getdt();
					call Timer1.startOneShot(t0 + dt);
				}
				else {
					call Timer1.startOneShot(TOS_NODE_ID * 50);
				}		
			}
		}
		return msg;
	}

/* -------------------------------------------- RECEIVE SERIAL MESSAGE ------------------------------------------------------ */
	event message_t* SerialReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (serial_msg_t)) {
			s_pkt = (serial_msg_t*) payload;
			source_id = TOS_NODE_ID;

			call Timer0.startPeriodic(s_pkt->data);
			call Timer2.startOneShot(100);
		}
		return msg;
	}
	
/* ------------------------------------------- RADIO DONE + SERIAL DONE ----------------------------------------------------- */
	event void RadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;
			startTime = call Timer2.getNow();
			
			//endTime = call Timer3.getNow();

			if(source_id != TOS_NODE_ID){
				if (send < SIZE && save > send) {
				call Timer1.startOneShot(TOS_NODE_ID*50);	
				//send++;
				}
				else {
					send = 0;
				}
			}
		}		
	}

/* .......................................................................................................................... */
	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&serial_pkt == msg) {
			serial_busy = FALSE;

			dbg("BroadcastingC", "Finish serial\n\n ");
			
		}
	}
/* -------------------------------------------------------------------------------------------------------------------------- */	
}
