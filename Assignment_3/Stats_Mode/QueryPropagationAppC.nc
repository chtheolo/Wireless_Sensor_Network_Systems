#include "QueryRadioFlooding.h"
#include "QueryPacket.h"
#include "SamplingPacket.h"

configuration QueryPropagationAppC
{
}
implementation
{
	components MainC, LedsC;
	components new TimerMilliC() as TimerQueryBroadcast;
	components new TimerMilliC() as TimerReadSensor;
	components new TimerMilliC() as TimerSendPCSerial;
	components new TimerMilliC() as TimerQueryFired;
	components new TimerMilliC() as TimerSimpleMeasurementUcast;
	components new TimerMilliC() as TimerStatsMeasurement_ReUcastSimple;
	
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

	App.TimerQueryBroadcast -> TimerQueryBroadcast;
	App.TimerReadSensor -> TimerReadSensor;
	App.TimerSendPCSerial -> TimerSendPCSerial;
	App.TimerQueryFired -> TimerQueryFired;
	App.TimerSimpleMeasurementUcast -> TimerSimpleMeasurementUcast;
	App.TimerStatsMeasurement_ReUcastSimple -> TimerStatsMeasurement_ReUcastSimple;

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

