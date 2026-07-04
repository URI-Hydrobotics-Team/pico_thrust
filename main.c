#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_0 0
#define PWM_1 2
#define PWM_2 4
#define PWM_3 6
#define PWM_4 8
#define PWM_5 10

uint32_t pwm_set_freq_duty(uint slice_num,
		uint chan,uint32_t f, int d)
{
	uint32_t clock = 125000000;
	uint32_t divider16 = clock / f / 4096 + 
		(clock % (f * 4096) != 0);
	if (divider16 / 16 == 0)
		divider16 = 16;
	uint32_t wrap = clock * 16 / divider16 / f - 1;
	pwm_set_clkdiv_int_frac(slice_num, divider16/16,
			divider16 & 0xF);
	pwm_set_wrap(slice_num, wrap);
	pwm_set_chan_level(slice_num, chan, wrap * d / 100);
	return wrap;
}

int main() {
	//setup_default_uart();
	stdio_init_all();



	/* configure PWM */

	gpio_set_function(PWM_0, GPIO_FUNC_PWM);
	gpio_set_function(PWM_1, GPIO_FUNC_PWM);
	gpio_set_function(PWM_2, GPIO_FUNC_PWM);
	gpio_set_function(PWM_3, GPIO_FUNC_PWM);
	gpio_set_function(PWM_4, GPIO_FUNC_PWM);
	gpio_set_function(PWM_5, GPIO_FUNC_PWM);


	unsigned int pwm_slice_0 = pwm_gpio_to_slice_num(PWM_0);
	unsigned int pwm_slice_1 = pwm_gpio_to_slice_num(PWM_1);
	unsigned int pwm_slice_2 = pwm_gpio_to_slice_num(PWM_2);
	unsigned int pwm_slice_3 = pwm_gpio_to_slice_num(PWM_3);
	unsigned int pwm_slice_4 = pwm_gpio_to_slice_num(PWM_4);
	unsigned int pwm_slice_5 = pwm_gpio_to_slice_num(PWM_5);

	// set

	pwm_set_freq_duty(pwm_slice_0, PWM_0, 50, 5);
	pwm_set_freq_duty(pwm_slice_1, PWM_1, 50, 20);
	pwm_set_freq_duty(pwm_slice_2, PWM_2, 50, 30);
	pwm_set_freq_duty(pwm_slice_3, PWM_3, 50, 40);
	pwm_set_freq_duty(pwm_slice_4, PWM_4, 50, 50);
	pwm_set_freq_duty(pwm_slice_5, PWM_5, 50, 60);


	pwm_set_enabled(pwm_slice_0, true);
	pwm_set_enabled(pwm_slice_1, true);
	pwm_set_enabled(pwm_slice_2, true);
	pwm_set_enabled(pwm_slice_3, true);
	pwm_set_enabled(pwm_slice_4, true);
	pwm_set_enabled(pwm_slice_5, true);

	sleep_ms(10 * 1000);

	
	pwm_set_freq_duty(pwm_slice_0, PWM_0, 50, 6);

	while(1){
		printf("Alive\n");

	
		sleep_ms(100);
	}









	return 0;
}



