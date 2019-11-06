#include "Timer.h"

#include "RadioFlooding.h"
#include "SerialFlooding.h"

module RadioFloodingC @safe()
{
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;
  uses interface Timer<TMilli> as	Timer1;

	uses interface Packet as SerialPacket;
	uses interface AMPacket as SerialAMPacket;
	uses interface AMSend as SerialAMSend;
	uses interface Receive as SerialAMReceive;
	uses interface SplitControl as SerialAMControl;
	
	uses interface Packet as RadioPacket;
	uses interface AMPacket as RadioAMPacket;
	uses interface AMSend as RadioAMSend;
	uses interface Receive as RadioAMReceive;
	uses interface SplitControl as RadioAMControl;
  uses interface Read<uint16_t>;
}
implementation
{
  uint16_t d;
  uint8_t On_Off;
	bool busy = FALSE;
	message_t pkt,pkt2;  
	uint16_t period=1000;
	uint16_t seq_num = 0;
	
	uint16_t r_source_id;
	uint16_t r_sender_id;
	uint16_t r_data;
	uint16_t r_seq_num=0;
			
/*
* Tasks
*/
 
  task void checkThresshold() {
		dbg("BlinkC", "d = %hu.\n", d);
    if(d > 40 && On_Off == 1) {
      On_Off = 0;
      dbg("BlinkC", "Led is off @ %s.\n", sim_time_string());
      call Leds.led0Off();
    }
    else if (d < 40 && On_Off == 0){
      On_Off = 1;
      dbg("BlinkC", "Led is on @ %s.\n", sim_time_string());
      call Leds.led0On();
    }
  }
	
	
/*
**
*/

  event void Boot.booted() {
		call SerialAMControl.start();
		call RadioAMControl.start();
  }

	event void SerialAMControl.startDone(error_t err) {
		if (err != SUCCESS) {
			call SerialAMControl.start();
		}
	}
	
	event void RadioAMControl.startDone(error_t err) {
		if (err != SUCCESS) {
			call RadioAMControl.start();
		}
	}


	event void SerialAMControl.stopDone(error_t err) { }
	
	event void RadioAMControl.stopDone(error_t err) { }


  event void Timer0.fired() {
    dbg("BlinkC", "Timer0 fired @ %s.\n", sim_time_string());
    call Read.read(); /* initiate read op */
  }

  event void Read.readDone(error_t result, uint16_t data) {
    /* get result or error of read op */
    if(result == SUCCESS){
	    dbg("BlinkC", "Success readDone sensor %s.\n",sim_time_string());
      d = data;
			if (!busy) {
				radio_flooding_msg_t* r_pkt = (radio_flooding_msg_t*) (call RadioPacket.getPayload( &pkt, sizeof (radio_flooding_msg_t) ));
				if (r_pkt == NULL) {
					return;
				}
				seq_num++;
				r_pkt->source_id = TOS_NODE_ID;
				r_pkt->sender_id = TOS_NODE_ID;
				r_pkt->data = d;
				r_pkt->seq_num = seq_num;
				if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (radio_flooding_msg_t)) == SUCCESS){
					dbg("BlinkC", "Reading & Sending a packet %s.\n", sim_time_string());
					busy = TRUE;
				}
			}
      post checkThresshold();
		}
  }
  
  event void Timer1.fired() {
  	dbg("BLinkC", "Timer1 fired @ %s.\n", sim_time_string());
  	if (!busy) {
  		radio_flooding_msg_t* bcast_pkt = (radio_flooding_msg_t*) (call RadioPacket.getPayload( &pkt, sizeof (radio_flooding_msg_t) ));
			if (bcast_pkt == NULL	) {
				return;
			}
			
			bcast_pkt->source_id = r_source_id;
			bcast_pkt->sender_id = r_sender_id;
			bcast_pkt->data = r_data;
			bcast_pkt->seq_num = r_seq_num;
			
			if (call RadioAMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (radio_flooding_msg_t)) == SUCCESS){
				dbg("BlinkC", "Brodcasting a new packet %s.\n", sim_time_string());
				busy = TRUE;
			}	
  	}
  }

	event message_t* RadioAMReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (radio_flooding_msg_t)) {
			radio_flooding_msg_t* r_pkt = (radio_flooding_msg_t*) payload;			
			dbg("BlinkC", "Receve a new radio_packet %s.\n", sim_time_string());
		
			if (r_pkt->seq_num > r_seq_num) {
				r_source_id = r_pkt->source_id;
				r_sender_id = r_pkt->sender_id;
				r_data = r_pkt->data;
				r_seq_num = r_pkt->seq_num;

				call Timer1.startOneShot(1000);
			}
		}
		return msg;
	}
	
	event message_t* SerialAMReceive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof(serial_flooding_msg_t)) {
			serial_flooding_msg_t* r_pkt = (serial_flooding_msg_t*) payload;
			dbg("BlinkC", "Receive a serial msg %s.\n", sim_time_string());
			period = 1000;
			call Timer0.startPeriodic(period); 
			dbg("BlinkC", "Period = %hu.\n", r_pkt->period);
		}
		return msg;
	}


	event void SerialAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;
		}
	}
	
	event void RadioAMSend.sendDone(message_t* msg, error_t err) {
		if (&pkt == msg) {
			busy = FALSE;
		}
	}

}
