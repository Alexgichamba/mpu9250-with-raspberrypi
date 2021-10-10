#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <fstream>

#define MAXTEMP temp_min_max.second
#define MAXACCELX accel_x_min_max.second
#define MAXACCELY accel_y_min_max.second
#define MAXACCELZ accel_z_min_max.second
#define MAXGYROX gyro_x_min_max.second
#define MAXGYROY gyro_y_min_max.second
#define MAXGYROZ gyro_z_min_max.second
#define MAXMAGX mag_x_min_max.second
#define MAXMAGY mag_y_min_max.second
#define MAXMAGZ mag_z_min_max.second

#define MINTEMP temp_min_max.first
#define MINACCELX accel_x_min_max.first
#define MINACCELY accel_y_min_max.first
#define MINACCELZ accel_z_min_max.first
#define MINGYROX gyro_x_min_max.first
#define MINGYROY gyro_y_min_max.first
#define MINGYROZ gyro_z_min_max.first
#define MINMAGX mag_x_min_max.first
#define MINMAGY mag_y_min_max.first
#define MINMAGZ mag_z_min_max.first

int append_readings(std::string time_date,
                    double temp,
                    double accel_x,
                    double accel_y,
                    double accel_z,
                    double gyro_x,
                    double gyro_y,
                    double gyro_z
                    /*,
                    double mag_x,
                    double mag_y,
                    double mag_z
                    */);

void get_stats();