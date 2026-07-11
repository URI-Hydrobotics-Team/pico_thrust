#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"



#define PICO_THRUST_REFRESH_RATE 50 //every * ms
#define ESC_MAX 1900 //us
#define ESC_MIN 1100 //us
#define ESC_STOP 1500 //us
#define ESC_FREQ 50 // Hz
#define ESC_INITALIZE 1500 //us
#define ESC_INITALIZE_TIME 2000 //ms

#include "pwm.h"


#define PWM_0 0
#define PWM_1 2
#define PWM_2 4
#define PWM_3 6
#define PWM_4 8
#define PWM_5 10



void initialize_thrusters(){


	printf("$PT IN\n");


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



