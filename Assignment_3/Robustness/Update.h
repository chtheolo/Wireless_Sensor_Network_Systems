#ifndef UPDATE_H
#define UPDATE_H

enum {
	AM_UPDATE_MSG = 26
};

typedef nx_struct update_msg {
	nx_uint8_t node_id;
	nx_uint8_t propagation_mode;
} update_msg_t;

#endif