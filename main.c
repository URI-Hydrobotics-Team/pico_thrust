#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "config.h"
#include "pwm.h"


void initialize_thrusters(){


	printf("$PT IN\n");


}



int main() {
	stdio_init_all();


	thruster_t tardigrade_y, tardigrade_ps, tardigrade_ss, tardigrade_sh, tardigrade_bsh, tardigrade_bph; //create your thrusters

	thruster_t thrusters[6] = {tardigrade_y, tardigrade_ps, tardigrade_ss, tardigrade_sh, tardigrade_bsh, tardigrade_bph}; //put them in a table in the order the PWM values streaming from the host
	



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









	while(1){
		printf("PWM_5 %d\n", PWM_5);

	
		sleep_ms(100);
	}









	return 0;
}



