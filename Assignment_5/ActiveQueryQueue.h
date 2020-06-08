#ifndef ACTIVEQUERYQUEUE_H
#define ACTIVEQUERYQUEUE_H

typedef nx_struct ActiveQueryQueue {
	nx_uint8_t source_id;			/* Routing Table */
	nx_uint8_t sequence_number;
	nx_uint8_t sampling_id;			/*new*/
	nx_uint8_t forwarder_id;
	nx_uint8_t father_node;
	nx_uint8_t children[5];
	nx_uint8_t number_of_children;
	nx_uint8_t count_received_children;
	nx_uint8_t hops;
	nx_uint32_t query_lifetime;
	nx_uint16_t startDelay;
	nx_uint16_t WaitingTime;
	nx_uint16_t RemaingTime;
	nx_uint8_t propagation_mode;
	nx_uint8_t temporary_reg7;
	nx_uint8_t temporary_reg8;
	nx_uint8_t state;
/* 	------------------------  */
	nx_uint8_t app_id;				/* application info */
	nx_uint8_t BinaryMessage[30];
	nx_int16_t registers[10];
	nx_uint8_t pc;
	nx_uint8_t TimerCalled;
	nx_uint32_t TimerRemainingTime;
	nx_uint8_t RegisterReadSensor;
	//nx_uint16_t sampling_period;
} ActiveQueryQueue_t;

#endif