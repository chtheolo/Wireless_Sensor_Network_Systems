#ifndef CHILDRENNODES_H
#define CHILDRENNODES_H

typedef nx_struct ChildrenNodes {
	nx_uint8_t node_id;
	nx_uint8_t source_id;
	nx_uint8_t sequence_number;
	//nx_uint8_t waiting_time;
	nx_uint8_t state;
} ChildrenNodes_t;

#endif