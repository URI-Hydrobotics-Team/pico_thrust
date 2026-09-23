#include "serial.h"



/*
	serial data format from PPSTI:
	PWM,0000,0000,0000,0000,0000,0000

	PPSTI currently uses a fixed number of thrusters
	we will use the built in USB CDC Serial, buad rate is irrelevant


*/

void serial_write_thruster(thruster_t *thruster, const char *value);



int serial_read_and_parse_from_host(thruster_t **thrusters, uint8_t count){

	//read

	char temp_buffer[8]; //stores individual pwm values extracted from string
	char buffer[SERIAL_MESSAGE_BUFFER_SIZE];
	memset(buffer, 0, SERIAL_MESSAGE_BUFFER_SIZE);
	gets(buffer);

	
	//parse	

	memset(temp_buffer, 0, 8);
	uint8_t temp_buffer_index = 0;
	int buffer_index = 0;
	


	if (strncpy(buffer, "PWM", 3) != 0){
		return -1; // error

	}
	buffer_index = 3;


	while (buffer_index < SERIAL_MESSAGE_BUFFER_SIZE){
		if(buffer[buffer_index] == ','){
			if (temp_buffer_index != 0){
				//terminate temp buffer and store into thruster_t
				temp_buffer[temp_buffer_index] = 0;
				serial_write_thruster(thrusters[thruster_index], temp_buffer);

			}


			memset(temp_buffer, 0, 8);
			temp_buffer_index = 0;

				
		}else{
			temp_buffer[temp_buffer_index] = buffer[buffer_index];
			temp_buffer_index++;


		}


		if (buffer[buffer_index] == '\n'){ //or could be when == 0
			//end of buffer
			break;
			
		}
		buffer_index++;
	

	}
	



	


}





