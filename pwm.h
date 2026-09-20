#include "thruster.h"
#include "hardware/pwm.h"
#include <string.h>

#ifndef PWM_H
#define PWM_H

#define PICO_THRUST_DEFUALT_WIDTH 1000;

void thruster_setup(thruster_t *thruster, const char *id_, uint8_t gpio_);
void thruster_init(thruster_t *thruster);

void thruster_set(thruster_t *thruster, float width);

uint32_t pwm_set_freq_duty(uint slice_num, uint chan,uint32_t f, float d);
#endif
