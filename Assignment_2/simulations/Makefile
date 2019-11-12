COMPONENT=RadioFloodingAppC
BUILD_EXTRA_DEPS = RadioFlooding.py 
CLEAN_EXTRA = RadioFlooding.py

RadioFlooding.py: RadioFlooding.h
	mig python -target=$(PLATFORM) $(CFLAGS) -python-classname=RadioFlooding RadioFlooding.h flooding_msg -o $@

include $(MAKERULES)

