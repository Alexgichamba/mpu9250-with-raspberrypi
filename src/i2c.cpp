#include "../inc/i2c.h"

int read_word(int device_handle, int address){
    int value;
    value = i2cReadByteData(device_handle, address);
    value = value << 8;
    value += i2cReadByteData(device_handle, address+1);
    if (value >= 0x8000)
        value = -(65536 - value);
    return value;
}
