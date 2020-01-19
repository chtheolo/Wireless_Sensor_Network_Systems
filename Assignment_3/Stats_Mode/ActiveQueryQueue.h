#ifndef ACTIVEQUERYQUEUE_H
#define ACTIVEQUERYQUEUE_H

typedef nx_struct ActiveQueryQueue {
	nx_uint8_t source_id;
	nx_uint8_t sequence_number;
	nx_uint8_t forwarder_id;
	nx_uint8_t father_node;
	nx_uint8_t children[5];
	nx_uint8_t hops;
	nx_uint16_t sampling_period;
	nx_uint16_t query_lifetime;
	nx_uint8_t propagation_mode;
	nx_uint8_t state;
	nx_uint16_t startDelay;
	nx_uint16_t WaitingTime;
	nx_uint16_t RemaingTime;
} ActiveQueryQueue_t;

#endif