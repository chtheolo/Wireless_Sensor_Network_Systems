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
} sampling_msg_t;

#endif
