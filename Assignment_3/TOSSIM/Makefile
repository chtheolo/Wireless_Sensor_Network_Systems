COMPONENT= QueryPropagationAppC
BUILD_EXTRA_DEPS = QueryPacketMsg.py 
CLEAN_EXTRA = QueryPacketMsg.py

QueryPacketMsg.py: QueryPacket.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=QueryPacketMsg QueryPacket.h query_msg -o $@

include $(MAKERULES)

