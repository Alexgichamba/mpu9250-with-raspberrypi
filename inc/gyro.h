#pragma once

#include "../inc/i2c.h"
#include <iostream>

//defines self test addresses for gyro
#define SELF_TEST_X_GYRO_ADDR 0x00
#define SELF_TEST_Y_GYRO_ADDR 0x01
#define SELF_TEST_Z_GYRO_ADDR 0x02

//defines memory address for register responsible for configuring gyroscope
#define GYRO_CONFIG_ADDR 0X1B

//defines memory addresses for gyroscope output HIGH registers
#define GYRO_XOUT_H_ADDR 0x43
#define GYRO_YOUT_H_ADDR 0x45
#define GYRO_ZOUT_H_ADDR 0x47

//define scales for gyro
#define GYRO_FSCALE_250 0x00
#define GYRO_FSCALE_500 0x01
#define GYRO_FSCALE_1000 0x02
#define GYRO_FSCALE_2000 0x03

//defines parameters for gyro
#define GYRO_SENSITIVITY_250 131.0
#define GYRO_SENSITIVITY_500 65.5
#define GYRO_SENSITIVITY_1000 32.8
#define GYRO_SENSITIVITY_2000 16.4

void set_gyro(int device_handle, int scale_val);

double get_gyro_x(int device_handle);
double get_gyro_y(int device_handle);
double get_gyro_z(int device_handle);
double scale_gyro(int raw_gyro);