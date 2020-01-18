#ifndef STATSSAMPLINGACKET_H
#define STATSSAMPLINGACKET_H

enum {
	AM_STATS_SAMPLING_MSG = 46
};

typedef nx_struct stats_sampling_msg {
	nx_uint16_t source_id;
	nx_uint16_t data_id;
	nx_uint16_t forwarder_id;
	nx_uint16_t hops;
	nx_uint16_t min;
	nx_uint16_t max;
	nx_uint16_t average;
	nx_uint16_t destination_id;
	nx_uint16_t sequence_number;
	nx_uint8_t sum_contributed_ids;
	nx_uint8_t mode;
} stats_sampling_msg_t;

#endif
