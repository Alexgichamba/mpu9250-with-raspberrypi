#include "../inc/mag.h"
/* Still in progress
//functions called by main
double get_mag_x(int mag_device_handle){ 
    double mag_x, raw_mag_h,raw_mag_l;
    raw_mag_h = read_word(mag_device_handle, MAG_XOUT_H_ADDR);
    raw_mag_l = read_word(mag_device_handle, MAG_XOUT_L_ADDR);
    mag_x = scale_mag_x(mag_device_handle,raw_mag_l);
    return mag_x;
}
double get_mag_y(int mag_device_handle){
    int raw_mag_y;
    double mag_y;
    raw_mag_y = read_word(mag_device_handle, MAG_YOUT_H_ADDR);
    mag_y = scale_mag_y(mag_device_handle,raw_mag_y);
    return mag_y;
}
double get_mag_z(int mag_device_handle){
    int raw_mag_z;
    double mag_z;
    raw_mag_z = read_word(mag_device_handle, MAG_ZOUT_H_ADDR);
    mag_z = scale_mag_z(mag_device_handle,raw_mag_z);
    return mag_z;
}
//functions to scale raw values
double scale_mag_x(int mag_device_handle, int raw_mag){
    double scaled_mag_x, x_sensitivity;
    x_sensitivity = 5.0;
    scaled_mag_x = ( raw_mag * ( ( (x_sensitivity-128) / 256.0 ) + 1) );
    return scaled_mag_x;
}
double scale_mag_y(int mag_device_handle, int raw_mag){
    double scaled_mag_y, y_sensitivity;
    y_sensitivity =  5.0;
    scaled_mag_y =( raw_mag * ( ( (y_sensitivity-128) / 256.0 ) + 1) );
    return scaled_mag_y;
}
double scale_mag_z(int mag_device_handle, int raw_mag){
    double scaled_mag_z, z_sensitivity;
    z_sensitivity = 5.0;
    scaled_mag_z = ( raw_mag * ( ( (z_sensitivity-128) / 256.0 ) + 1) );
    return scaled_mag_z;
}

*/