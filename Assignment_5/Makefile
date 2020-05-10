COMPONENT= QueryPropagationAppC
BUILD_EXTRA_DEPS = QueryPacket.py 
CLEAN_EXTRA = QueryPacket.py
CFLAGS += -DTOSH_DATA_LENGTH=110

QueryPacket.py: QueryPacket.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=QueryPacket QueryPacket.h query_msg -o $@

include $(MAKERULES)

