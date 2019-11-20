#ifndef RADIOFLOODING_H
#define RADIOFLOODING_H

enum {
	AM_FLOODING_MSG = 45
};

typedef nx_struct flooding_msg {
	nx_uint16_t source_id;
	nx_uint16_t seq_num;
	nx_uint16_t forwarder_id;
	nx_uint16_t counter;
	nx_uint16_t counter1;
	nx_uint16_t counter2;
	nx_uint16_t counter3;
	nx_uint16_t counter4;
	nx_uint16_t counter5;
	nx_uint16_t counter6;
	nx_uint16_t counter7;
	nx_uint16_t counter8;
	nx_uint16_t counter9;
	nx_uint16_t counter10;
} flooding_msg_t;

#endif
