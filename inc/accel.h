#pragma once

#include "../inc/i2c.h"
#include <iostream>

//defines memory addresses for accelerometer output HIGH registers
#define ACCEL_XOUT_H_ADDR 0x3B
#define ACCEL_YOUT_H_ADDR 0x3D
#define ACCEL_ZOUT_H_ADDR 0x3F

//defines address for register responsible for configuring accelerometer
#define ACCEL_CONFIG_ADDR 0X1C

//defines scales for accelerometer
#define ACCEL_FSCALE_2G 0x00
#define ACCEL_FSCALE_4G 0x01
#define ACCEL_FSCALE_8G 0x02
#define ACCEL_FSCALE_16G 0x03

//defines sensitivity for given scales
#define ACCEL_SENSITIVITY_2G 16384.0
#define ACCEL_SENSITIVITY_4G 8192.0
#define ACCEL_SENSITIVITY_8G 4096.0
#define ACCEL_SENSITIVITY_16G 2048.0

//defines gravitational acceleration at the equator in m/s^2
#define GRAVITATIONAL_CONST 9.7803

double get_accel_x(int device_handle);
double get_accel_y(int device_handle);
double get_accel_z(int device_handle);

double scale_accel(int raw_accel);

void set_accel(int device_handle, int scale_val);