COMPONENT= QueryPropagationAppC
BUILD_EXTRA_DEPS = QueryPacketMsg.py 
CLEAN_EXTRA = QueryPacketMsg.py
PLATFORM_BUILD_FLAGS= -fpic *-shared* -W1,--enabled-auto-image-base

QueryPacketMsg.py: QueryPacket.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=QueryPacketMsg QueryPacket.h query_msg -o $@

include $(MAKERULES)
