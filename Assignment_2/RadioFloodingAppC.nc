#include "RadioFlooding.h"
#include "SerialPacket.h"

configuration RadioFloodingAppC
{
}
implementation
{
	components MainC, LedsC;
	components new TimerMilliC() as Timer0;
	components new TimerMilliC() as Timer1;
	
	components RadioFloodingC as App;
	
	components ActiveMessageC;	
	components new AMReceiverC(AM_FLOODING_MSG);
	components new AMSenderC(AM_FLOODING_MSG);

	components SerialActiveMessageC;
	components new SerialAMReceiverC(AM_SERIAL_MSG);
	components new SerialAMSenderC(AM_SERIAL_MSG);

	App.Boot -> MainC;
	App.Leds -> LedsC;

	App.Timer0 -> Timer0;
	App.Timer1 -> Timer1;

  

	App.SerialReceive->SerialAMReceiverC;
	App.SerialPacket->SerialAMSenderC;
	App.SerialAMPacket -> SerialAMSenderC;
	App.SerialAMSend->SerialAMSenderC;
	App.SerialAMControl->SerialActiveMessageC;
	
	App.Receive -> AMReceiverC;
	App.Packet -> AMSenderC;
	App.AMPacket -> AMSenderC;
	App.AMSend -> AMSenderC;
	App.RadioAMControl -> ActiveMessageC;
}

