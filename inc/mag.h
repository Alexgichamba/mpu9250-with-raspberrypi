#pragma once

#include <iostream>
#include "../inc/i2c.h"

#define MAG_DEVICE_ADDR 0x00
#define MAG_DEVICE_INFO_ADDR 0x01
#define MAG_DEVICE_STATUS_1_ADDR 0x02
#define MAG_DEVICE_CNTRL_ADDR 0x0A

#define MAG_XOUT_L_ADDR 0x03
#define MAG_YOUT_L_ADDR 0x04
#define MAG_ZOUT_L_ADDR 0x05

#define MAG_XOUT_H_ADDR 0x04
#define MAG_YOUT_H_ADDR 0x06
#define MAG_ZOUT_H_ADDR 0x08

#define MAG_XSENSITIVITY_ADDR 0x10
#define MAG_YSENSITIVITY_ADDR 0x11
#define MAG_ZSENSITIVITY_ADDR 0x11

double get_mag_x(int mag_device_handle);
double get_mag_y(int mag_device_handle);
double get_mag_z(int mag_device_handle);

double scale_mag_x(int mag_device_handle, int raw_mag);
double scale_mag_y(int mag_device_handle, int raw_mag);
double scale_mag_z(int mag_device_handle, int raw_mag);