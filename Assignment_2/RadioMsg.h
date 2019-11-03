#ifndef RADIOMSG_H
#define RADIOMSG_H

enum {
	AM_BLINKTORADIO = 6,
	TIMER_PERIOD_MILLI = 1000 
};

typedef nx_struct RadioMsg {
	nx_uint8_t id;
	nx_uint8_t type;
	//nx_uint8_t nodeid;
	nx_uint16_t data;
	//nx_bool forwardORnot;
} RadioMsg;

#endif
