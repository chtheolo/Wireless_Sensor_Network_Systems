COMPONENT=RadioFloodingAppC
BUILD_EXTRA_DEPS = SerialFloodingMsg.py 
CLEAN_EXTRA = SerialFloodingMsg.py

SerialFloodingMsg.py : SerialFlooding.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=SerialFloodingMsg SerialFlooding.h serial_flooding_msg -o $@
include $(MAKERULES)

