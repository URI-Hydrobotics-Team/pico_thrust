#include "pwm.h"


void thruster_setup(thruster_t *thruster, const char *id_, unsigned int pwm_slice_, unsigned int gpio_){
	memset(thruser->id, 0, PICO_THRUST_ID_LEN);
	strncpy(thruster->id, id_, PICO_THRUST_ID_LEN);
	thruster->pwm_slice = pwm_slice_;
	thruster->gpio = gpio;
	thruster-> 


}

void thruster_init(thruster_t *thruster){
	gpio_set_function(thruster->gpio, GPIO_FUNC_PWM);
	thruster->pwm_slice = pwm_gpio_to_slice_num(thruster->gpio);
	pwm_set_enabled(thruster_pwm_slice, true);

	printf("Thruster %s initilized", thruster->id);
	

}

void thruster_set(thruster_t *thruster, float width){


	float duty = (width / (1.0 / ESC_FREQ)) / (1000 * 10);

	pwm_set_freq_duty(thruster->pwm_slice, thruster->gpio, ESC_FREQ, duty);

}



uint32_t pwm_set_freq_duty(uint slice_num, uint chan, uint32_t f, float d){
	uint32_t clock = 125000000;
	uint32_t divider16 = clock / f / 4096 + (clock % (f * 4096) != 0);
	if (divider16 / 16 == 0){
		divider16 = 16;
	}
	uint32_t wrap = clock * 16 / divider16 / f - 1;
	pwm_set_clkdiv_int_frac(slice_num, divider16/16, divider16 & 0xF);
	pwm_set_wrap(slice_num, wrap);
	pwm_set_chan_level(slice_num, chan, wrap * d / 100);
	return wrap;
}

