#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#include "config.h"
#include "pwm.h"
#include "serial.h"

int main() {
	stdio_init_all();


	thruster_t tardigrade_y, tardigrade_ps, tardigrade_ss, tardigrade_sh, tardigrade_bsh, tardigrade_bph; //create your thrusters

	thruster_t tardigrade_thrusters[6] = {tardigrade_y, tardigrade_ps, tardigrade_ss, tardigrade_sh, tardigrade_bsh, tardigrade_bph}; //put them in a table in the order the PWM values streaming from the host
	

	thruster_setup(&tardigrade_y, "Y", PWM_0);
	thruster_setup(&tardigrade_ps, "PS", PWM_1);
	thruster_setup(&tardigrade_ss, "SS", PWM_2);
	thruster_setup(&tardigrade_bsh, "BSH", PWM_3);
	thruster_setup(&tardigrade_sh, "SH", PWM_4);
	thruster_setup(&tardigrade_bph, "BPH", PWM_5);



	for (uint8_t i = 0; i < 6; i++){
		thruster_init(tardigrade_thrusters[i]);
		thruster_set(tardigrade_thrusters[i], ESC_INITALIZE);
	
	}

	sleep_ms(ESC_INITALIZE_TIME);

	int status;

	while(1){

		sleep_ms(GLOBAL_DELAY);

		//read from host
		status = serial_read_and_parse_from_host(&tardigrade_thrusters, 6);
		
		if (status == -1){
			//an error occured clamp to 0 IMMIDIATELY

			for (uint8_t i = 0; i < 6; i++){
				thruster_set(tardigrade_thrusters[i], ESC_INITALIZE);

			}
	
		}			

		}
		//update the thrusters
		for (uint8_t i = 0; i < 6; i++){

			thruster_update(tardigrade_thrusters[i]);
		}
	


	
	}


	return 0;
}



