#ifndef SERIALFLOODING_H
#define SERIALFLOODING_H

enum {
	AM_SERIAL_FLOODING_MSG = 0x89
//	TIMER_PERIOD_MILLI = 1000 
};

typedef nx_struct serial_flooding_msg {
	nx_uint8_t period;
} serial_flooding_msg_t;

#endif
