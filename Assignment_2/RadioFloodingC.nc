#include "Timer.h"

#include "RadioMsg.h"
#include "SerialMsg.h"

module RadioFloodingC @safe()
{
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer0;
  uses interface Timer<TMilli> as	Timer1; 
	uses interface Packet;
	uses interface AMPacket;
	uses interface AMSend;
	uses interface Receive;
	uses interface SplitControl as AMControl;
  uses interface Read<uint16_t>;
}
implementation
{
  uint16_t d;
  uint8_t On_Off;
	bool busy = FALSE;
	message_t pkt;  
	//uint16_t period;
	uint16_t id = 0;
	bool source_broadcast = FALSE;
			
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
		call AMControl.start();
  }

	event void AMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			call Timer.startPeriodic(1000);
      dbg("BlinkC", "Radio Control SUCCESS @ %s.\n", sim_time_string());
		}
		else {
			call AMControl.start();
		}
	}


	event void AMControl.stopDone(error_t err) { }


  event void Timer0.fired() {
    dbg("BlinkC", "Timer fired @ %s.\n", sim_time_string());
    call Read.read(); /* initiate read op */
  }

  event void Read.readDone(error_t result, uint16_t data) {
    /* get result or error of read op */
    if(result == SUCCESS){
	    dbg("BlinkC", "Success readDone sensor %s.\n",sim_time_string());
      d = data;
			if (!busy) {
				RadioMsg* r_pkt = (RadioMsg*) (call Packet.getPayload( &pkt, sizeof (RadioMsg) ));
				if (r_pkt == NULL	) {
					return;
				}
				id++;
				r_pkt->id = id;
				r_pkt->data = d;
				r_pkt->type = 1;
				if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (RadioMsg)) == SUCCESS){
					dbg("BlinkC", "Reading & Sending a packet %s.\n", sim_time_string());
					busy = TRUE;
				}
			}
      post checkThresshold();
		}
  }

	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (RadioMsg)) {
			RadioMsg* r_pkt = (RadioMsg*) payload;
			if (r_pkt->type == 0) { 
				call Timer0.startOneShot();
				dbg("BlinkC", "Start Flooding %s.\n", sim_time_string());
			}
			else if (r_pkt->type == 1 && r_pkt->id > id) {
				if (!busy) {
				RadioMsg* bcast_pkt = (RadioMsg*) (call Packet.getPayload( &pkt, sizeof (RadioMsg) ));
				if (bcast_pkt == NULL	) {
					return;
				}
				bcast_pkt-> id = r_pkt->id;
				bcast_pkt-> data = r_pkt->data;
				bcast_pkt-> type = r_pkt->type;
				if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (RadioMsg)) == SUCCESS){
					dbg("BlinkC", "Brodcasting a new packet %s.\n", sim_time_string());
					busy = TRUE;
				}
				id = r_pkt->id;
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
