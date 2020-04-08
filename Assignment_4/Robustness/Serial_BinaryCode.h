#ifndef SERIAL_BINARYCODE_H
#define SERIAL_BINARYCODE_H

enum {
	AM_BINARY_MSG = 76
};

typedef nx_struct binary_msg {
	nx_uint8_t app_id;
	nx_uint8_t BinaryMessage[25];
	nx_uint8_t state;
	nx_uint8_t mode;
} binary_msg_t;

#endif
