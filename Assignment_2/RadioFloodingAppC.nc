#include "RadioFlooding.h"
#include "SerialFlooding.h"

configuration RadioFloodingAppC
{
}
implementation
{
  components MainC, LedsC;
  components new TimerMilliC() as Timer0;
  components new TimerMilliC() as Timer1;

//  components new  HamamatsuS1087ParC() as Sensor;
	components new AlternateSensorC(10,100,1) as Sensor;
	
	components RadioFloodingC as App;
	
	components SerialActiveMessageC as Serial;
	components new SerialAMReceiverC(AM_SERIAL_FLOODING_MSG) as SerialReceiver;
	components new SerialAMSenderC(AM_SERIAL_FLOODING_MSG) as SerialSender;
	
	components ActiveMessageC as Radio;	
	components new AMReceiverC(AM_FLOODING_MSG) as RadioReceiver;
	components new AMSenderC(AM_FLOODING_MSG) as RadioSender;

  App -> MainC.Boot;

  App.Timer0 -> Timer0;
  App.Timer1 -> Timer1;
  App.Leds -> LedsC;
  App.Read -> Sensor;
	
	App.RadioAMReceive -> RadioReceiver;
	App.RadioPacket -> RadioSender;
	App.RadioAMPacket -> RadioSender;
	App.RadioAMSend -> RadioSender;
	App.RadioAMControl -> Radio;
	
	App.SerialAMReceive -> SerialReceiver;
	App.SerialPacket -> SerialSender;
	App.SerialAMPacket -> SerialSender;
	App.SerialAMSend -> SerialSender;
	App.SerialAMControl -> Serial;
}

