#pragma once

#include <pigpio.h>

#define I2C_DEVICE 1
#define I2C_DEVICE_ADDR 0x68
#define I2C_MAGDEVICE_ADDR 0x0C
#define I2C_FLAGS 0

#define USER_CTRL 0x6A

#define PWR_MGMT_1_ADDR 0x6B
#define PWR_MGMT_1_VAL 0x00

//read word from i2c device
int read_word(int device_handle, int address);