#include "../inc/temp.h"

double get_temp(int device_handle){
    int raw_temp;
    double scaled_temp;
    raw_temp = read_word(device_handle,TEMP_OUT_H_ADDR);
    scaled_temp = scale_temp(raw_temp);
    return scaled_temp;
}

double scale_temp(int raw_temp){
    double scaled_temp;
    scaled_temp = ((raw_temp - ROOMTEMP_OFFSET) / TEMP_SENSITIVITY) + 16.0;
    return scaled_temp;

}