#ifndef SAMPLINGACKET_H
#define SAMPLINGACKET_H

enum {
	AM_SAMPLING_MSG = 36
};

typedef nx_struct sampling_msg {
	nx_uint16_t source_id;
	nx_uint16_t data_id;
	nx_uint16_t forwarder_id;
	nx_uint16_t sensor_data;
	nx_uint16_t destination_id;
	nx_uint16_t sequence_number;
	nx_uint8_t count_contributed_nodes;
} sampling_msg_t;

#endif
