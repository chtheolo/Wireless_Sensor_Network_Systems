#ifndef BINARY_RESPONSE_H
#define BINARY_RESPONSE_H

enum {
	AM_BINARY_RSP = 86
};

typedef nx_struct binary_rsp {
	nx_uint8_t IDs[2];
	nx_uint8_t mode;
} binary_rsp_t;

#endif