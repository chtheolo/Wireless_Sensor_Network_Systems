#ifndef SAMPLINGACKET_H
#define SAMPLINGACKET_H

#define NODES 10

enum {
	AM_SAMPLING_MSG = 36,
};

typedef nx_struct sampling_msg {
	nx_uint8_t source_id;
	nx_uint8_t data_id;
	nx_uint8_t forwarder_id;
	nx_uint16_t sensor_data;
	nx_uint8_t destination_id;
	nx_uint8_t sequence_number;
	nx_uint8_t  mode;
	nx_uint8_t number_of_nodes;
} sampling_msg_t;

#endif
