#ifndef STATSSAMPLINGACKET_H
#define STATSSAMPLINGACKET_H

enum {
	AM_STATS_SAMPLING_MSG = 46,
	MAX_NODES_IDS = 5
};

typedef nx_struct stats_sampling_msg {
	nx_uint8_t source_id;
	nx_uint8_t data_id;
	nx_uint8_t forwarder_id;
	nx_uint8_t hops;
	nx_uint16_t min;
	nx_uint16_t max;
	nx_uint16_t average;
	nx_uint8_t destination_id;
	nx_uint8_t sequence_number;     
	nx_uint8_t contributed_ids[5];
	nx_uint8_t mode;
} stats_sampling_msg_t;

#endif
