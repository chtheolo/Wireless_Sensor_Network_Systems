#ifndef SENDERSHISTORY_H
#define SENDERSHISTORY_H

typedef nx_struct SendersHistory {
	nx_uint8_t source_id;
	//nx_uint16_t forwarder_id;
	nx_uint8_t sequence_number;
} SendersHistory_t;

#endif