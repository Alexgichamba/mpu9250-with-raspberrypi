#pragma once

#include "../inc/i2c.h"

#define TEMP_OUT_H_ADDR 0x41

//Condition is 21 Celcius hence offset of 4 means room temp = 25 deg
#define ROOMTEMP_OFFSET 4.0

#define TEMP_SENSITIVITY 333.87

double get_temp(int device_handle);

double scale_temp(int raw_temp);