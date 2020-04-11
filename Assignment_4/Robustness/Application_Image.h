#ifndef APPLICATION_IMAGE_H
#define APLLICATION_IMAGE_H


typedef nx_struct Application_Image {
	nx_uint8_t app_id;
	nx_uint8_t BinaryMessage[25];
	nx_uint16_t registers[6];
	nx_uint8_t pc;
	nx_uint8_t state;
	nx_uint8_t TimerCalled;
} Application_Image_t;

#endif
