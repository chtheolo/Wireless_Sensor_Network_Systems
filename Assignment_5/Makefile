COMPONENT= QueryPropagationAppC
BUILD_EXTRA_DEPS = QueryPacket.py 
CLEAN_EXTRA = QueryPacket.py

QueryPacket.py: QueryPacket.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=QueryPacket QueryPacket.h query_msg -o $@

include $(MAKERULES)

