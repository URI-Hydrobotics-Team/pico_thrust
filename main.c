#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "config.h"
#include "pwm.h"


void initialize_thrusters(){


	printf("$PT IN\n");


}



int main() {
	//setup_default_uart();
	//stdio_init_all();


	thruster_t tardigrade_y, tardigrade_ps, tardigrade_ss, tardigrade_bsh;

	thruster_setup(&tardigrade_y, "Y", PWM_0);
	thruster_init(&tardigrade_y);
	thruster_set(&tardigrade_y, 1000);
	
	thruster_setup(&tardigrade_ps, "PS", PWM_1);
	thruster_init(&tardigrade_ps);
	thruster_set(&tardigrade_ps, 1200);

	thruster_setup(&tardigrade_ss, "SS", PWM_2);
	thruster_init(&tardigrade_ss);
	thruster_set(&tardigrade_ss, 800);

	thruster_setup(&tardigrade_bsh, "BSH", PWM_3);
	thruster_init(&tardigrade_bsh);
	thruster_set(&tardigrade_bsh, 1400);


	
	//pwm_set_freq_duty(pwm_slice_0, PWM_0, 50, 6); //1200 us



	while(1){
		printf("PWM_5 %d\n", PWM_5);

	
		sleep_ms(100);
	}









	return 0;
}



