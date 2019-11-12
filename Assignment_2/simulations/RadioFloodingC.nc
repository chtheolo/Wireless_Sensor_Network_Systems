#include "Timer.h"

#include "RadioFlooding.h"

#define SIZE 30
#define SIZER 10
#define mpos 5

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
	uint16_t k;
	uint16_t RoutingArray[SIZER];
	
	message_t PacketBuffer[SIZE];
	uint8_t send,save;
	
	uint8_t transmissions;
	uint8_t receivedMsgs;
	uint8_t newMessageReceived;
	
	uint8_t StartTime;
	uint8_t EndTime;
	uint8_t diffTime;
	
	uint16_t start;
	
	
	message_t pkt;
	bool busy = FALSE;
	
	uint8_t FireBroadcasting[mpos];
	
	task void init_RoutingTable() {
		
		for (start=0; start < 5 && i<SIZER; start++) {
			RoutingArray[i] = 0;
			i++;
		}
		if (i<SIZER) {
			post init_RoutingTable();
		}
	}
	
	task void init_FireBroadcasting() {
		for(start=0; start<mpos; start++) {
			FireBroadcasting[start] = start * 200;
		}
	}
	
	/*task void RoutingTable() {
		//uint16_t k=0;
		while (RoutingArray[k] != neighbor_id && RoutingArray[k] != 0 && k < SIZER) {
			k++;
		}
		if (RoutingArray[k] == neighbor_id) {
			dbg("RoutingTableC", "Neihgbor already exists in RoutingTable\n");
		}
		else if (RoutingArray[k] == 0) {
			RoutingArray[k] = neighbor_id;
		}
		else {
			dbg("RoutingTableC", "No more positions in RoutingTable\n");
		}
		/*if (k == last_pos){
			RoutingArray[last_pos] = neighbor_id;
			
			last_pos++;
		}
		else if (k < last_pos) {
			dbg("RoutingTableC", "Neihgbor already exists in RoutingTable\n");
		}
	}*/
	
	task void PrintRoutingTable() {
		uint8_t j;
	
		for(j=0; j<last_pos; j++) {
			dbg("RoutingTableC", "Node[%hu] : Route[%hu] = Node[%hu] .\n", TOS_NODE_ID, j, RoutingArray[j]);
		}
	}
	
//	task void ReceiveLeds() {
//		call Leds.led2Toggle();
//	}
//	
//	task void BroadcastLeds() {
//		call Leds.led0Toggle();
//	}
//	
//	task void ReBroadcast() {
//		call Leds.led1Toggle();
//	}
		
	/*								***								*/
	
	event void Boot.booted() {
		
		post init_RoutingTable();
		post init_FireBroadcasting();
		call AMControl.start();
		
		//call Leds.led0On();
		
		send=0;
		save=0;
		
		if (TOS_NODE_ID == 1) {
			call Timer0.startPeriodic(TOS_NODE_ID *100 + 500);
		}
		transmissions = 0;
		receivedMsgs = 0;
		newMessageReceived=0;
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
		bcast_pkt->hops = 0;
		
		if (!busy) {
			
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));
			dbg("BroadcastingC", "sender_id=%hu, counter=%hu ,seq_num=%hu .\n", bcast_pkt->sender_id, bcast_pkt->counter, bcast_pkt->seq_num);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &pkt /*&PacketBuffer[send]*/, sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "START BROADCASTING ... %s.\n\n", sim_time_string());
				//post BroadcastLeds();
				call Leds.led0Toggle();
				busy = TRUE;
				transmissions++;
				if (seq_num == 1 ) {
					StartTime = sim_time_string();
				}
			
			}
		}
	}
	
	event void Timer1.fired() {
		call Leds.led1Toggle();
		//dbg("Re-BroadcastingC", "Timer for Re-BROADCASTING %s.\n", sim_time_string());
		if (!busy) {
			bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&PacketBuffer[send], sizeof (flooding_msg_t) ));
			if (bcast_pkt == NULL) {
				return;
			}
			
			memcpy(&pkt, &PacketBuffer[send], sizeof(message_t));
			dbg("Re-BroadcastingC", "sender_id=%hu, counter=%hu ,seq_num=%hu hops= %hu .\n", bcast_pkt->sender_id, bcast_pkt->counter, bcast_pkt->seq_num, bcast_pkt->hops);
			
			if (call AMSend.send(AM_BROADCAST_ADDR, &pkt/*PacketBuffer[send]*/, sizeof (flooding_msg_t)) == SUCCESS){
				dbg("BroadcastingC", "Start Re-BROADCASTING ... %s.\n\n", sim_time_string());
				//post ReBroadcast();
				//call Leds.led2Toggle();
				busy = TRUE;
				transmissions++;
				
			}
		}
	}
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		//dbg("ReceiveC", "RECEIVE RADIO_MSG %s.\n", sim_time_string());
		
		if (len == sizeof (flooding_msg_t)) {
			receivedMsgs++;
			r_pkt = (flooding_msg_t*) payload;

						
			dbg("ReceiveC", "RECEIVE a msg from node[%hu] with seq_num = %hu %s.\n", r_pkt->sender_id, r_pkt->seq_num ,sim_time_string());
		
			
			//post RoutingTable();
			k=0;
			while (RoutingArray[k] != r_pkt->sender_id  && RoutingArray[k] != 0 && k < SIZER) {
				k++;
			}
			if (RoutingArray[k] == r_pkt->sender_id) {
				dbg("RoutingTableC", "Neihgbor already exists in RoutingTable\n");
			}
			else if (RoutingArray[k] == 0) {
				RoutingArray[k] = r_pkt->sender_id;
			}
			else {
				dbg("RoutingTableC", "No more positions in RoutingTable\n");
			}
			
			//post PrintRoutingTable();
			
			if (r_pkt->seq_num > seq_num) {
			
				if (r_pkt->hops == 8) {
					EndTime = sim_time_string();
					diffTime = EndTime - StartTime;
					dbg("TimeC", "\n\nThe diffTime is : %hu \n\n", diffTime);
				}
				newMessageReceived++;
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
				bcast_pkt->hops = r_pkt->hops +1;
				
				//keep the new seq_num
				seq_num = r_pkt->seq_num;
				
				//post ReceiveLeds();
				
				start = TOS_NODE_ID % mpos;
				call Timer1.startOneShot(FireBroadcasting[start]);
			}
		}
		return msg;
	}
	
	event void AMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt/*PacketBuffer[send]*/ == msg) {
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



