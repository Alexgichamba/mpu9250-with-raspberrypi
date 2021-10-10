#include "../inc/gyro.h"

double  gyro_scale_factor = 0;
void set_gyro(int device_handle, int scale_val ){
    
    switch (scale_val)
    {
    case 250:
        gyro_scale_factor = 131.0;    
        break;
    case 500:
        gyro_scale_factor = 65.5;     
        break;
    case 1000:
        gyro_scale_factor = 32.8;    
        break;
    case 2500:
        gyro_scale_factor = 16.4;    
        break;
    
    default:
        std::cout << "Unable to set gyro scale\n";
    }
}

double get_gyro_x(int device_handle){
    int raw_gyro_x;
    double scaled_gyro_x;
    raw_gyro_x = read_word(device_handle, GYRO_XOUT_H_ADDR);
    scaled_gyro_x = scale_gyro(raw_gyro_x);
    return scaled_gyro_x;
}

double get_gyro_y(int device_handle){
    int raw_gyro_y;
    double scaled_gyro_y;
    raw_gyro_y = read_word(device_handle, GYRO_YOUT_H_ADDR);
    scaled_gyro_y = scale_gyro(raw_gyro_y);
    return scaled_gyro_y;
}

double get_gyro_z(int device_handle){
    int raw_gyro_z;
    double scaled_gyro_z;
    raw_gyro_z = read_word(device_handle, GYRO_ZOUT_H_ADDR);
    scaled_gyro_z = scale_gyro(raw_gyro_z);
    return scaled_gyro_z;
}

double scale_gyro(int raw_gyro){
    double scaled;
    scaled = (raw_gyro) / (gyro_scale_factor);
    return scaled;
}