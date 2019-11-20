COMPONENT=RadioFloodingAppC
BUILD_EXTRA_DEPS = SerialPacket.py 
CLEAN_EXTRA = SerialPacket.py

SerialPacket.py: SerialPacket.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=SerialPacket SerialPacket.h serial_msg -o $@

include $(MAKERULES)

