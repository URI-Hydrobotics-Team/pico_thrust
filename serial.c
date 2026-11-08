#include "serial.h"
#include "config.h"
#include <stdlib.h>

/*
	serial data format from PPSTI:
	PWM,0000,0000,0000,0000,0000,0000

	PPSTI currently uses a fixed number of thrusters
	we will use the built in USB CDC Serial, buad rate is irrelevant


*/
#define BUFFER_STATUS_TIME 500 //ms of time before stdio_get_until errors tf out
void serial_write_thruster(thruster_t *thruster, const char *value){

	int pwm_int = atoi(value);
	thruster->width = pwm_int;



}


void serial_read_and_parse_from_host(thruster_t **thrusters, uint8_t count, int* status){

	//read

	char temp_buffer[8]; //stores individual pwm values extracted from string
	char buffer[SERIAL_MESSAGE_BUFFER_SIZE];
	memset(buffer, 0, SERIAL_MESSAGE_BUFFER_SIZE);

	int buffer_status;
        uint32_t timeout = BUFFER_STATUS_TIME;
	buffer_status = stdio_get_until(buffer,SERIAL_MESSAGE_BUFFER_SIZE, make_timeout_time_ms(timeout));


	if (buffer_status != PICO_ERROR_TIMEOUT){	
		printf("buffer: %s\n", buffer);
                *status = 1;
	}else{
            *status = -1;
        }
	//parse	

	memset(temp_buffer, 0, 8);
	uint8_t temp_buffer_index = 0;
	int buffer_index = 0;
	uint8_t thruster_count = 0;	


	buffer_index = 4; //skip first comma


	//while (thruster_index < count){
	while (buffer_index < SERIAL_MESSAGE_BUFFER_SIZE){

		if(buffer[buffer_index] == ',' || buffer[buffer_index] == '\n'){

			thruster_count++;

			if (temp_buffer_index != 0){
				//terminate temp buffer and store into thruster_t

				temp_buffer[temp_buffer_index] = 0;
				serial_write_thruster(thrusters[thruster_count - 1], temp_buffer);
				printf("set thruster[%d] to: %d\n", thruster_count - 1, thrusters[thruster_count - 1]->width);

			}
			temp_buffer_index = 0;
			memset(temp_buffer, 0, 8);

		}else{
			temp_buffer[temp_buffer_index] = buffer[buffer_index];
			temp_buffer_index++;
			

		}


		if (buffer[buffer_index] == '\n'){ //or could be when == 0
			//end of buffer
			return;
			
		}
		buffer_index++;
	

	}
	return;	

}
