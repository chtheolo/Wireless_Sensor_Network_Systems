#ifndef ACTIVEQUERYQUEUE_H
#define ACTIVEQUERYQUEUE_H

typedef nx_struct ActiveQueryQueue {
	nx_uint16_t source_id;
	nx_uint16_t sequence_number;
	nx_uint16_t forwarder_id;
	nx_uint16_t hops;
	nx_uint16_t sampling_period;
	nx_uint16_t query_lifetime;
	nx_uint16_t propagation_mode;
	nx_uint16_t	state;
} ActiveQueryQueue_t;

#endif