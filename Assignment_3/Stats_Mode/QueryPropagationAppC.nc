#include "QueryRadioFlooding.h"
#include "QueryPacket.h"
#include "SamplingPacket.h"

configuration QueryPropagationAppC
{
}
implementation
{
	components MainC, LedsC;
	components new TimerMilliC() as Timer0;
	components new TimerMilliC() as Timer1;
	components new TimerMilliC() as Timer2;
	components new TimerMilliC() as Timer3;
	components new TimerMilliC() as Timer4;
	components new TimerMilliC() as Timer5;
	
	components new  HamamatsuS1087ParC() as Sensor;
	//components new DemoSensorC() as Sensor;

	components QueryPropagationC as App;
	
	components ActiveMessageC;	
	components new AMReceiverC(AM_QYERY_FLOODING_MSG);
	components new AMSenderC(AM_QYERY_FLOODING_MSG);

// edw prepei na ta onomatisw gia na ta 3exarisw ston kwdika
	components new AMReceiverC(AM_SAMPLING_MSG) as SamplingAMReceiverC;
	components new AMSenderC(AM_SAMPLING_MSG) as SamplingAMSenderC;

	components SerialActiveMessageC;
	components new SerialAMReceiverC(AM_QUERY_MSG);
	components new SerialAMSenderC(AM_QUERY_MSG);

	App.Boot -> MainC;
	App.Leds -> LedsC;
	App.Read -> Sensor;

	App.Timer0 -> Timer0;
	App.Timer1 -> Timer1;
	App.Timer2 -> Timer2;
	App.Timer3 -> Timer3;
	App.Timer4 -> Timer4;
	App.Timer5 -> Timer5;

	App.SerialReceive -> SerialAMReceiverC;
	App.SerialPacket -> SerialAMSenderC;
	//App.SerialAMPacket -> SerialAMSenderC;
	App.SerialAMSend -> SerialAMSenderC;
	App.SerialAMControl->SerialActiveMessageC;
	
	App.RadioReceive -> AMReceiverC;
	App.Packet -> AMSenderC;
	//App.AMPacket -> AMSenderC;
	App.RadioAMSend -> AMSenderC;
	App.RadioAMControl -> ActiveMessageC;

	App.SamplingRadioReceive -> SamplingAMReceiverC;
	App.SamplingAMPacket -> SamplingAMSenderC;
	App.SamplingRadioAMSend -> SamplingAMSenderC;
}

