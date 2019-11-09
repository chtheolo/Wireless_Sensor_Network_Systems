#include "Timer.h"

#include "RadioFlooding.h"

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
	uint16_t counter = 0;
	uint16_t seq_num = 0;
	
	message_t pkt;
	bool busy = FALSE;
	
	event void Boot.booted() {
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
		dbg("BroadcastingC", "Timer for Broadcasting %s.\n", sim_time_string());
		if (!busy) {
			flooding_msg_t* bcast_pkt = (flooding_msg_t*) (call Packet.getPayload(&pkt, sizeof (flooding_msg_t) ));
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
		dbg("Re-BroadcastingC", "Timer for Re-Broadcasting %s.\n", sim_time_string());
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
				dbg("BroadcastingC", "Start Re-Broadcasting ... %s.\n", sim_time_string());
				busy = TRUE;
			}
		}
	}
	
	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		dbg("ReceiveC", "RECEIVE RADIO_MSG %s.\n", sim_time_string());
		if (len == sizeof (flooding_msg_t)) {
			flooding_msg_t* r_pkt = (flooding_msg_t*) payload;			
//			dbg("BlinkC", "Receve a new radio_packet %s.\n", sim_time_string());
		
			if (r_pkt->seq_num > seq_num) {
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
