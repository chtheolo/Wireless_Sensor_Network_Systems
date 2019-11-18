#include "RadioFlooding.h"

configuration RadioFloodingAppC
{
}
implementation
{
	components MainC, LedsC;
	components new TimerMilliC() as Timer0;
	components new TimerMilliC() as Timer1;

//  components new  HamamatsuS1087ParC() as Sensor;
//	components new AlternateSensorC(10,100,1) as Sensor;
	
	components RadioFloodingC as App;
	
	components ActiveMessageC;	
	components new AMReceiverC(AM_FLOODING_MSG);
	components new AMSenderC(AM_FLOODING_MSG);

	//components new RandomC() as Random;
	
	
//	components new PoolC(message_t, 20) as BroadcastPoolC;
//	components new QueueC(message_t* , 20) as BroadcastQueueC;

	App.Boot -> MainC;

	App.Timer0 -> Timer0;
	App.Timer1 -> Timer1;

	App.Leds -> LedsC;

	//App.Random -> RandomC;
//  App.Read -> Sensor;
	
//	App.BroadcastPool -> BroadcastPoolC;
//	App.BroadcastQueue -> BroadcastQueueC;
	
	App.Receive -> AMReceiverC;
	App.Packet -> AMSenderC;
	App.AMPacket -> AMSenderC;
	App.AMSend -> AMSenderC;
	App.AMControl -> ActiveMessageC;
}

