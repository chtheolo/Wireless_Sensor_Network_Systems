#ifndef RADIOFLOODING_H
#define RADIOFLOODING_H

enum {
	AM_FLOODING_MSG = 45
};

typedef nx_struct flooding_msg {
	nx_uint16_t sender_id;
	nx_uint16_t counter;
	nx_uint16_t seq_num;
	nx_uint16_t hops;
} flooding_msg_t;

#endif
