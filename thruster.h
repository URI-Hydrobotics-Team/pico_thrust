
#ifndef THRUSTER_H
#define THRUSTER_H

#define PICO_THRUST_ID_LEN 8



struct thruster{
	
	char id[PICO_THRUST_ID_LEN];
	uint pwm_slice;
	uint8_t gpio;	
	uint16_t width; //microseconds

};
typedef struct thruster thruster_t;
#endif
