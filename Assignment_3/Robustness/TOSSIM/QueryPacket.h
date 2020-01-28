#ifndef QUERYPACKET_H
#define QUERYPACKET_H

enum {
	AM_QUERY_MSG = 6
};

typedef nx_struct query_msg {
	nx_uint16_t sampling_period;
	nx_uint16_t query_lifetime;
	nx_uint16_t propagation_mode; //0 = simple, 1=stats
} query_msg_t;

#endif
