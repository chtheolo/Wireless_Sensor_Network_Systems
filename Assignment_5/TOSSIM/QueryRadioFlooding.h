#ifndef QUERYRADIOFLOODING_H
#define QUERYRADIOFLOODING_H

enum {
	AM_QYERY_FLOODING_MSG = 45
};

typedef nx_struct query_flooding_msg {
	nx_uint8_t source_id;
	nx_uint8_t sequence_number;
	nx_uint8_t forwarder_id;
	nx_uint8_t father_node;
	nx_uint8_t hops;
	nx_uint16_t sampling_period;
	nx_uint16_t query_lifetime;
	nx_uint8_t propagation_mode;
} query_flooding_msg_t;

#endif
