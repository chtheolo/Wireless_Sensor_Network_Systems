#ifndef BLINKTORADIO_H
#define BLINKTORADIO_H

enum {
	AM_BLINKTORADIO = 6,
	TIMER_PERIOD_MILLI = 1000 
};

typedef nx_struct BlinkToRadioMsg {
	nx_uint16_t data;
} BlinkToRadioMsg;

#endif
