
#ifndef THRUSTER_H
#define THRUSTER_H

#define PICO_THRUST_ID_LEN 8



struct thruster{
	
	char id[PICO_THRUST_ID_LEN];
	unsigned int pwm_slice;
	unsigned int gpio;	
	unsigned int width; //microseconds

};
typedef struct thruster thruster_t;
#endif
