#include "RadioMsg.h"


configuration RadioFloodingAppC
{
}
implementation
{
  components MainC, LedsC;
  components new TimerMilliC() as Timer0;
  components new TimerMilliC() as Timer1;
  //components new  HamamatsuS1087ParC() as Sensor;
	components new AlternateSensorC(10,100,1) as Sensor;
	components ActiveMessageC;
	components RadioFloodingC as App;
	components new AMReceiverC(AM_BLINKTORADIO);
	components new AMSenderC(AM_BLINKTORADIO);

  App -> MainC.Boot;

  App.Timer0 -> Timer0;
  App.Timer1 -> Timer1;
  App.Leds -> LedsC;
  App.Read -> Sensor;
	App.Receive -> AMReceiverC;
	App.Packet -> AMSenderC;
	App.AMPacket -> AMSenderC;
	App.AMSend -> AMSenderC;
	App.AMControl -> ActiveMessageC;
}

