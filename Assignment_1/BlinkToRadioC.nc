#include "Timer.h"

#include "BlinkToRadio.h"

module BlinkToRadioC @safe()
{
  uses interface Boot;
  uses interface Leds;
  uses interface Timer<TMilli> as Timer;
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
	uint16_t period;

/*
* Tasks
*/
 
  task void checkThresshold() {
		dbg("BlinkC", "d = %hu.\n", d);
    if(d > 40 && On_Off == 1) {
      On_Off = 0;
      dbg("BlinkC", "Led is on @ %s.\n", sim_time_string());
      call Leds.led0Off();
    }
    else if (d < 40 && On_Off == 0){
      On_Off = 1;
      dbg("BlinkC", "Led is off @ %s.\n", sim_time_string());
      call Leds.led0On();
    }
		dbg("BlinkC", "AMControl.start() %s.\n", sim_time_string());
		//call AMControl.start();
  }

/*
**
*/

  event void Boot.booted() {
		period = 1000;
		//call Timer.startPeriodic(period);
		call AMControl.start();
  }

	event void AMControl.startDone(error_t err) {
		if (err == SUCCESS) {
			call Timer.startPeriodic(1000);
      dbg("BlinkC", "Success read @ %s.\n", sim_time_string());
		}
		else {
			call AMControl.start();
		}
	}


	event void AMControl.stopDone(error_t err) { }


  event void Timer.fired() {
    dbg("BlinkC", "Timer fired @ %s.\n", sim_time_string());
    call Read.read(); /* initiate read op */
  }

  event void Read.readDone(error_t result, uint16_t data) {
    /* get result or error of read op */
    if(result == SUCCESS){
      d = data;
			if (!busy) {
				BlinkToRadioMsg* btrpkt = (BlinkToRadioMsg*) (call Packet.getPayload( &pkt, sizeof (BlinkToRadioMsg)));
				if (btrpkt == NULL) {
					return;
				}
				btrpkt-> data = d;
				if (call AMSend.send(AM_BROADCAST_ADDR, &pkt, sizeof (BlinkToRadioMsg)) == SUCCESS){
					busy = TRUE;
				}
			}
			dbg("BlinkC", "Success readDone sensor %s.\n",sim_time_string());
      post checkThresshold();
		}
  }

	event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
		if (len == sizeof (BlinkToRadioMsg)) {
			BlinkToRadioMsg* btrpkt = (BlinkToRadioMsg*) payload;
			if (btrpkt->data != period) {
				call Timer.startPeriodic(btrpkt->data); 
				dbg("BlinkC", "Led1 toggle %s.\n", sim_time_string());
				//call Leds.led2Toggle();
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
