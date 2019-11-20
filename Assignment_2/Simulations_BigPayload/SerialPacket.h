#ifndef SERIALPACKET_H
#define SERIALPACKET_H

enum {
	AM_SERIAL_MSG = 6
};

typedef nx_struct serial_msg {
	nx_uint16_t data;
} serial_msg_t;

#endif
