#ifndef SERIAL_BINARYCODE_H
#define SERIAL_BINARYCODE_H

enum {
	AM_BINARY_MSG = 76
};

typedef nx_struct binary_msg {
	nx_uint8_t app_id;
	nx_uint8_t BinaryMessage[30];
	nx_uint8_t state;
	nx_uint8_t action;
	nx_uint32_t query_lifetime;
	//nx_uint8_t propagation_mode;	/*simple = 0, stats = 1, cancel = 2*/
} binary_msg_t;

#endif
