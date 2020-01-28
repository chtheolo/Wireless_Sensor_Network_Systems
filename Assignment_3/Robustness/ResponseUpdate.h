#ifndef RESPONSEUPDATE_H
#define RESPONSEUPDATE_H

enum {
	AM_RESPONSE_UPDATE_MSG = 56
};

typedef nx_struct response_update_msg {
	nx_uint8_t source_id;
	nx_uint8_t sequence_number;
	nx_uint8_t forwarder_id;
	nx_uint8_t father_node;
	nx_uint8_t hops;
	nx_uint16_t sampling_period;
	nx_uint16_t query_lifetime;
	nx_uint8_t propagation_mode;
	nx_uint16_t rest_of_time_period;
} response_update_msg_t;

#endif
