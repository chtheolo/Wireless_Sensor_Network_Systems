#ifndef STATSSAMPLINGACKET_H
#define STATSSAMPLINGACKET_H

enum {
	AM_STATS_SAMPLING_MSG = 46,
	MAX_NODES_IDS = 5
};

typedef nx_struct stats_sampling_msg {
	nx_uint8_t source_id;
	nx_uint8_t application_id;
	nx_uint8_t data_id;
	nx_uint8_t forwarder_id;
	nx_uint8_t hops;
	nx_int16_t data_1;
	nx_int16_t data_2;
	nx_uint8_t destination_id;
	nx_uint8_t sequence_number;
	nx_uint8_t mode;
	//nx_uint8_t contributed_ids[5];
} stats_sampling_msg_t;

#endif
