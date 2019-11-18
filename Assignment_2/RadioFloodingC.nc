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
	//user interface 
 
	uses interface Packet;
	uses interface AMPacket;
	uses interface AMSend;
	uses interface Receive;
	uses interface SplitControl as RadioAMControl;

	uses interface Packet as SerialPacket;
	uses interface AMPacket as SerialAMPacket;
	uses interface AMSend as SerialAMSend;
	uses interface Receive as SerialReceive;
	uses interface SplitControl as SerialAMControl;

}
implementation
{
	flooding_msg_t* r_pkt;
	flooding_msg_t* bcast_pkt;
	serial_msg_t* s_pkt;
	message_t pkt;
	
	/*msg payload*/ 
	//uint16_t source_id = 0;
	uint16_t seq_num = 0;
	//uint16_t forwarder_id;
	uint16_t bcast_time;
	uint16_t counter = 0;
	
	/*helping variables*/
	uint16_t i;
	uint16_t last_pos=0;
	uint16_t start;
	uint16_t neighbor_id;
	uint16_t standard_bcast;
	uint8_t k;
	uint8_t send,save;
	bool busy = FALSE;

	
	/* Arrays */
	uint16_t NeighborsArray[NEIGHBOR_SIZE][2];
	uint8_t FireBroadcasting[mpos];	
	bool StateMessages[NEIGHBOR_SIZE];

	message_t PacketBuffer[SIZE];

	
	/* Tasks START HERE ! */
	task void init_NeighborsTable() {
		for (start=0; start < 5 && i<NEIGHBOR_SIZE; start++) {
			for (k=0; k<2; k++) {
				NeighborsArray[i][k] = 0;
			}
			i++;
		}
		if (i<NEIGHBOR_SIZE) {
			post init_NeighborsTable();
		}
	}
	
	task void init_StateMessages() {
		for (start=0; start < NEIGHBOR_SIZE; start++) {
			StateMessages[start] = 0;
		}
	}
	
	task void NeighborsTable() {
		k=0;
		while (NeighborsArray[k][0] != neighbor_id && NeighborsArray[k][0] != 0 && k < NEIGHBOR_SIZE) {
			k++;
		}
		if (NeighborsArray[k][0] == neighbor_id) {
			NeighborsArray[k][1] = bcast_time;
			dbg("RoutingTableC", "Neihgbor already exists in NeighborsTable\n");
		}
		else if (NeighborsArray[k][0] == 0) {
			NeighborsArray[k][0] = neighbor_id;
			NeighborsArray[k][1] = bcast_time;
			neighbor_id = 0;
		}
		else if(k > NEIGHBOR_SIZE) {
			dbg("RoutingTableC", "No more positions in NeighborsTable\n");
		}
	}

	/*								***								*/
	
	event void Boot.booted() {
		i=0;
		send=0;
		save=0;
		standard_bcast = 100;

		call RadioAMControl.start();
		call SerialAMControl.start();

		post init_NeighborsTable();
		post init_StateMessages();
		
		//call Leds.led0On();
		
		if (TOS_NODE_ID == 1) {
			call Timer0.startPeriodic(/*TOS_NODE_ID *100 + 500*/standard_bcast);
		}
	}
	
/*				RADIO CONTROL 				*/	
	event void RadioAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "RADIO_CONTROL = OK %s.\n", sim_time_string());
		}
		else {
			call RadioAMControl.start();
		}
	}
	
	event void RadioAMControl.stopDone(error_t err) { }

/*				SERIAL CONTROL 				*/
	event void SerialAMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "RADIO_CONTROL = OK %s.\n", sim_time_string());
		}
		else {
			call SerialAMControl.start();
		}
	}
	
	event void SerialAMControl.stopDone(error_t err) { }

/*		***		*** 	***		***			*/

	
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
		bcast_pkt->bcast_time = /*TOS_NODE_ID*100 +500*/standard_bcast;
		bcast_pkt->counter = counter;
		
		if (!busy) {
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			dbg("BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, bcast_time = %hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->bcast_time, bcast_pkt->counter);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &pkt , sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "START BROADCASTING ... %s.\n\n", sim_time_string());
				//post BroadcastLeds();
				call Leds.led1Toggle();
				busy = TRUE;
			}
		}
	}
	
	event void Timer1.fired() {
		if (!busy) {
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[send], sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));

			dbg("Re-BroadcastingC", "source_id=%hu, seq_num=%hu, forwarder_id=%hu, bcast_time = %hu, counter=%hu.\n", bcast_pkt->source_id, bcast_pkt->seq_num, bcast_pkt->forwarder_id, bcast_pkt->bcast_time, bcast_pkt->counter);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (flooding_msg_t)) == SUCCESS){

				dbg("BroadcastingC", "START Re-BROADCASTING ... %s.\n\n", sim_time_string());

				call Leds.led2Toggle();
				busy = TRUE;
			}
		}
	}
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (flooding_msg_t)) {
			r_pkt = (flooding_msg_t*) payload;

			dbg("ReceiveC", "RECEIVE MESSAGE : source_id = %hu , seq_num = %hu, forwarder_id = %hu, bcast_time = %hu, counter = %hu @ %s.\n", r_pkt->source_id, r_pkt->seq_num, r_pkt->forwarder_id, r_pkt->bcast_time, r_pkt->counter, sim_time_string());

			k=0;
			while (NeighborsArray[k][0] != r_pkt->forwarder_id && NeighborsArray[k][0] != 0 && k < NEIGHBOR_SIZE) {
				k++;
			}
			if (NeighborsArray[k][0] == r_pkt->forwarder_id) {
				NeighborsArray[k][1] = r_pkt->bcast_time;
				dbg("RoutingTableC", "Neihgbor already exists in NeighborsTable\n");
			}
			else if (NeighborsArray[k][0] == 0) {
				NeighborsArray[k][0] = r_pkt->forwarder_id;
				NeighborsArray[k][1] = r_pkt->bcast_time;
				neighbor_id = 0;
			}
			else if(k > NEIGHBOR_SIZE) {
				dbg("RoutingTableC", "No more positions in NeighborsTable\n");
			}


			if (r_pkt->seq_num > StateMessages[r_pkt->source_id]) {
				StateMessages[r_pkt->source_id] = r_pkt->seq_num;

				dbg("ReceiveC", "NEW MESSAGE \n");

				if (save < SIZE) {
					bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
					save++;
				}
				else {
					save=0;
					bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
					save++;					
				}

				if (standard_bcast == r_pkt->bcast_time ) {
					standard_bcast = standard_bcast + 100; 
				}
				bcast_pkt->source_id = r_pkt->source_id;
				bcast_pkt->seq_num = r_pkt->seq_num;
				bcast_pkt->forwarder_id = TOS_NODE_ID;
				bcast_pkt->bcast_time = standard_bcast;
				bcast_pkt->counter = r_pkt->counter;
				
				//post ReceiveLeds();
				
				call Timer1.startOneShot(standard_bcast);
			}
		}
		return msg;
	}

/*				***		RECEIVE SERIAL MESSAGE 		***				*/

	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (serial_msg_t)) {
			s_pkt = (serial_msg_t*) payload;
			if (s_pkt->data != period) {
				call Timer.startPeriodic(s_pkt->data); 
				dbg("BlinkC", "Led1 toggle %s.\n", sim_time_string());
				//call Leds.led2Toggle();
			}
		}
		return msg;
	}
	
	event void AMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;
			if (send < SIZE) {
				send++;
			}
			else {
				send = 0;
			}
		}		
	}
	
}
