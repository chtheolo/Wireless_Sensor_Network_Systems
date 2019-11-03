#ifndef SERIALMSG_H
#define SERIALMSG_H

enum {
	AM_BLINKTORADIO = 6,
	TIMER_PERIOD_MILLI = 1000 
};

typedef nx_struct SerialMsg {
	nx_bool startFlooding;
} SerialMsg;

#endif
