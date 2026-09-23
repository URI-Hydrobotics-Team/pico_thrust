#ifndef SERIAL_H
#define SERIAL_H

#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "thruster.h"


void serial_write_thruster(thruster_t *thruster, const char *value);
int serial_read_and_parse_from_host(thruster_t **thrusters, uint8_t count);



#endif
