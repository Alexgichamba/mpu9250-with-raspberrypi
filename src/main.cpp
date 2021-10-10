/*
    Author: Alex Gichamba
*/
#include <iostream>

#include "../inc/i2c.h"
#include "../inc/timer.h"
#include "../inc/stats.h"
#include "../inc/temp.h"
#include "../inc/accel.h"
#include "../inc/gyro.h"
#include "../inc/mag.h"


int main(int argc, char* argv[])
{
    if (gpioInitialise()<0) //initialises pigpio.h
    {
        //if pigpio initialisation failed
        std::cout<<"pigpio.h initialisation failed\n";
        return -1;
    }

    //variables commonly used in main()
    int device_handle, mag_device_handle, wake_handle, mag_wake_handle, append_handle;
    std::string current_time;
    double temp_degC;
    double accel_x, accel_y, accel_z;
    double gyro_x, gyro_y, gyro_z;
    /* Magnetometer functionality is still in progress
    double mag_x, mag_y, mag_z;
    */
    //attempt to open I2C devices
    device_handle = i2cOpen(I2C_DEVICE,I2C_DEVICE_ADDR,I2C_FLAGS);
    if (device_handle < 0)
    {
        std::string err = "Failed to open i2c communication to IMU\n";
        std::cout<<err<<"\n";
        return -2;
    }
    mag_device_handle = i2cOpen(I2C_DEVICE,I2C_MAGDEVICE_ADDR,I2C_FLAGS);
    if (mag_device_handle < 0)
    {
        std::string err = "Failed to open i2c communication to mag\n";
        std::cout<<err<<"\n";
        return -3;
    }

    //attempt to disable sleep modes
    wake_handle = i2cWriteByteData(device_handle,PWR_MGMT_1_ADDR,PWR_MGMT_1_VAL);
    if (wake_handle<0)
    {
        std::string err = "Failed to wake IMU device\n";
        std::cout<<err<<"\n";
        return -4;
    }
    // Enable I2C Master mode
    i2cWriteByteData(device_handle,USER_CTRL,0x20);
    mag_wake_handle = i2cReadByteData(mag_device_handle,MAG_DEVICE_ADDR);
    if (mag_wake_handle != 72)
    {
        std::string err = "Mag device not found\n";
        std::cout<<err<<"\n";
        return -5;
    }
    
    
    

    device_wait(100); //to allow device to be ready to take readings
    std::cout << "Device is ready to take readings\n\n";

    //attempt to set scales
    set_gyro(device_handle,250);
    set_accel(device_handle,2);
    
    //infinite loop to get readings from device
    while (true)
    {
        //find the time now
        current_time = get_time();

        //get readings
        temp_degC = get_temp(device_handle);
        accel_x = get_accel_x(device_handle);
        accel_y = get_accel_y(device_handle);
        accel_z = get_accel_z(device_handle);
        gyro_x = get_gyro_x(device_handle);
        gyro_y = get_gyro_y(device_handle);
        gyro_z = get_gyro_z(device_handle);
        /* Magnetometer functionality is still in progress
        mag_x = get_mag_x(mag_device_handle);
        mag_y = get_mag_y(mag_device_handle);
        mag_z = get_mag_z(mag_device_handle);
        */
        //output readings
        std::cout<<"Time and date: "<<current_time;
        std::cout << "Temp: "<<temp_degC<<"  [deg Celcius]\n";
        std::cout << "Accel:  x: "<<accel_x<<"  y: "<<accel_y<<"  z: "<<accel_z<<"  [m/s^2]\n";
        std::cout << "Gyro:  x: "<<gyro_x<<"  y: "<<gyro_y<<"  z: "<<gyro_z<<"  [deg/sec]\n";
        /* Magnetometer functionality is still in progress
        std::cout << "Mag:  x: "<<mag_x<<"  y: "<<mag_y<<"  z: "<<mag_z<<"  [uT]\n";
        */
        std::cout <<"\n";
        
        append_handle = append_readings(current_time,temp_degC,accel_x,accel_y,accel_z,gyro_x,
                                        gyro_y,gyro_z /* ,mag_x,mag_y,mag_z */);       
        if (append_handle < 0)
        {
            std::cout<< "Unable to append readings\n";
        }
        
        get_stats();
        
        device_wait(5000); //sleep for 5 sec
    }
    
    return 0;
}