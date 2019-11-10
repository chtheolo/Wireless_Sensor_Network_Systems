#include "Timer.h"

#include "RadioFlooding.h"

#define SIZE 60

module RadioFloodingC @safe()
{
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;
  uses interface Timer<TMilli> as Timer1;
 
	uses interface Packet;
	uses interface AMPacket;
	uses interface AMSend;
	uses interface Receive;
	uses interface SplitControl as AMControl;
  //uses interface Read<uint16_t>;
}
implementation
{
	flooding_msg_t* r_pkt;
	flooding_msg_t* bcast_pkt;
	uint16_t counter = 0;
	uint16_t seq_num = 0;
	uint16_t neighbor_id;
	uint16_t i=0;
	uint16_t last_pos=0;
	uint16_t RoutingArray[SIZE];
	uint16_t PacketBuffer[SIZE];
	
	message_t pkt;
	bool busy = FALSE;
	
	task void init_RoutingTable() {
		uint16_t start;
		for (start=0; start < 20 && i<SIZE; start++) {
			RoutingArray[i] = 0;
			i++;
		}
		if (i<SIZE) {
			post init_RoutingTable();
		}
	}
	
	task void RoutingTable() {
		uint16_t k=0;
		while (RoutingArray[k] != neighbor_id && RoutingArray[k] != 0) {
			k++;
		}
		if (k == last_pos){
			RoutingArray[last_pos] = neighbor_id;//neighbor_id;
			last_pos++;
		}
		else if (k < last_pos) {
			dbg("RoutingTableC", "Neihgbor already exists in RoutingTable\n");
		}
	}
	
	task void PrintRoutingTable() {
		uint8_t j;
	
		for(j=0; j<last_pos; j++) {
			dbg("RoutingTableC", "Node[%hu] : Route[%hu] = Node[%hu] .\n", TOS_NODE_ID, j, RoutingArray[j]);
		}
	}
	
	event void Boot.booted() {
		post init_RoutingTable();
		call AMControl.start();
		if (TOS_NODE_ID == 1) {
			call Timer0.startOneShot(200 + TOS_NODE_ID *100);
		}
	}
	
	event void AMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			dbg("RadioC", "Radio Control => OK %s.\n", sim_time_string());
		}
		else {
			call AMControl.start();
		}
	}
	
	event void AMControl.stopDone(error_t err) { }
	
	event void Timer0.fired() {
		//dbg("BroadcastingC", "Timer for BROADCASTING %s.\n", sim_time_string());
		if (!busy) {
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&pkt, sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			
			counter++;
			seq_num++;
			bcast_pkt->sender_id = TOS_NODE_ID;
			bcast_pkt->counter = counter;
			bcast_pkt->seq_num = seq_num;
			
			dbg("BroadcastingC", "sender_id=%hu, counter=%hu ,seq_num=%hu .\n", bcast_pkt->sender_id, bcast_pkt->counter, bcast_pkt->seq_num);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start Broadcasting ... %s.\n", sim_time_string());
				busy = TRUE;
			}
		}
	}
	
	event void Timer1.fired() {
		//dbg("Re-BroadcastingC", "Timer for Re-BROADCASTING %s.\n", sim_time_string());
		if (!busy) {
			flooding_msg_t* bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&pkt, sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			
			bcast_pkt->sender_id = TOS_NODE_ID;
			bcast_pkt->counter = counter;
			bcast_pkt->seq_num = seq_num;
			
			dbg("Re-BroadcastingC", "sender_id=%hu, counter=%hu ,seq_num=%hu .\n", bcast_pkt->sender_id, bcast_pkt->counter, bcast_pkt->seq_num);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start Re-BROADCASTING ... %s.\n", sim_time_string());
				busy = TRUE;
			}
		}
	}
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		//dbg("ReceiveC", "RECEIVE RADIO_MSG %s.\n", sim_time_string());
		if (len == sizeof (flooding_msg_t)) {
			r_pkt = (flooding_msg_t*) payload;			
			dbg("ReceiveC", "RECEIVE a msg from node[%hu] %s.\n", r_pkt->sender_id ,sim_time_string());
		
			neighbor_id = r_pkt->sender_id;
			post RoutingTable();
			//post PrintRoutingTable();
			if (r_pkt->seq_num > seq_num) {
				//dbg("ReceiveC", "r_pkt->sender_id = %hu .\n", r_pkt->sender_id);
				dbg("ReceiveC", "New MESSAGE = %hu .\n", r_pkt->seq_num);
				counter = r_pkt->counter;
				seq_num = r_pkt->seq_num;
				call Timer1.startOneShot(200 + TOS_NODE_ID *100);
			}
		}
		return msg;
	}
	
	event void AMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;
		}	
	}
	
	

}
