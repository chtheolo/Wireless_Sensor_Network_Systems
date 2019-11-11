#include "Timer.h"

#include "RadioFlooding.h"

#define SIZE 200
#define SIZER 10

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
	
//	uses interface Queue<message_t *> as BroadcastQueue;
//	uses interface Pool<message_t> as BroadcastPool;
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
	uint16_t RoutingArray[SIZER];
	//uint8_t maxS;
	
	message_t PacketBuffer[SIZE];
	//message_t* p_pktbuffer;
	uint8_t send,save;
	
	
	message_t pkt;
	bool busy = FALSE;
	
	task void init_RoutingTable() {
		uint16_t start;
		for (start=0; start < 5 && i<SIZER; start++) {
			RoutingArray[i] = 0;
			i++;
		}
		if (i<SIZER) {
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
		
	/*								***								*/
	
	event void Boot.booted() {
		post init_RoutingTable();
		call AMControl.start();
		
		send=0;
		save=0;
		
		if (TOS_NODE_ID == 1) {
			call Timer0.startPeriodic(200 + TOS_NODE_ID *100);
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
		counter++;
		seq_num++;
		dbg("BroadcastingC", "New Attempt for BROADCASTING  counter = %hu with seq_num = %hu %s.\n", counter, seq_num, sim_time_string());
		
		if (save < SIZE) {
		
			//dbg("BroadcastingC", "Save = %hu and busy = %hu %s \n", save, busy, sim_time_string());
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
		
		bcast_pkt->sender_id = TOS_NODE_ID;
		bcast_pkt->counter = counter;
		bcast_pkt->seq_num = seq_num;
		
		if (!busy) {
			
			dbg("BroadcastingC", "sender_id=%hu, counter=%hu ,seq_num=%hu .\n", bcast_pkt->sender_id, bcast_pkt->counter, bcast_pkt->seq_num);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &PacketBuffer[send], sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "START BROADCASTING ... %s.\n\n", sim_time_string());
				busy = TRUE;
			
			}
		}
	}
	
	event void Timer1.fired() {
		//dbg("Re-BroadcastingC", "Timer for Re-BROADCASTING %s.\n", sim_time_string());
		if (!busy) {
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[send], sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			
			dbg("Re-BroadcastingC", "sender_id=%hu, counter=%hu ,seq_num=%hu .\n", bcast_pkt->sender_id, bcast_pkt->counter, bcast_pkt->seq_num);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &PacketBuffer[send], sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start Re-BROADCASTING ... %s.\n\n", sim_time_string());
				busy = TRUE;
				
			}
		}
	}
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		//dbg("ReceiveC", "RECEIVE RADIO_MSG %s.\n", sim_time_string());
		
		if (len == sizeof (flooding_msg_t)) {
			
			r_pkt = (flooding_msg_t*) payload;			
			dbg("ReceiveC", "RECEIVE a msg from node[%hu] with seq_num = %hu %s.\n", r_pkt->sender_id, r_pkt->seq_num ,sim_time_string());
		
			neighbor_id = r_pkt->sender_id;
			post RoutingTable();
			
			//post PrintRoutingTable();
			
			if (r_pkt->seq_num > seq_num) {
				
				dbg("ReceiveC", "This is a NEW MESSAGE with seq_num = %hu .\n\n", r_pkt->seq_num);
				
				if (save < SIZE) {
					bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
				
					save++;
				}
				else {
					save=0;
					bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[save], sizeof (flooding_msg_t) ));
					save++;					
				}
				
				bcast_pkt->sender_id = TOS_NODE_ID;
				bcast_pkt->counter = r_pkt->counter;
				bcast_pkt->seq_num = r_pkt->seq_num;
				
				//keep the new seq_num
				seq_num = r_pkt->seq_num;
				
				call Timer1.startOneShot(200 + TOS_NODE_ID *100);
			}
		}
		return msg;
	}
	
	event void AMSend.sendDone(message_t* msg, error_t err) {
		if (&PacketBuffer[send] == msg) {
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



