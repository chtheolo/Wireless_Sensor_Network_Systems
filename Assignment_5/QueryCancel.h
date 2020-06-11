#ifndef QUERYCANCEL_H
#define QUERYCANCEL_H

enum {
	AM_QYERY_CANCEL_MSG = 16
};

typedef nx_struct query_cancel_msg {
	nx_uint8_t source_id;
	nx_uint8_t app_id;
	nx_uint8_t sequence_number;
	nx_uint8_t mode;
	nx_uint8_t forwarder_id;
} query_cancel_msg_t;

#endif
