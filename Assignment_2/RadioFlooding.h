#ifndef RADIOFLOODING_H
#define RADIOFLOODING_H

enum {
	AM_FLOODING_MSG = 0x89,
	TIMER_PERIOD_MILLI = 1000 
};

typedef nx_struct radio_flooding_msg {
	nx_uint16_t source_id;
	nx_uint8_t sender_id;
	nx_uint16_t seq_num;
	nx_uint16_t data;
} radio_flooding_msg_t;

#endif
