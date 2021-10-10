# MPU-9250 with Raspberry Pi
This program provides basic functionality of the MPU-9250 with a Raspberry Pi over an I<sup>2</sup>C interface. The program uses the [pigpio](https://abyz.me.uk/rpi/pigpio/index.html) library for the I<sup>2</sup>C read and write functionality.
<p>This program was tested on a Raspberry Pi Zero W running Raspbian GNU/Linux 10 (buster).</p>

## To install
You would first need to check if you have pigpio installed. To do so, run the following line of code in the terminal.
```bash
pigpiod -v
```
If the command is not recognized you can [download and install pigpio](https://abyz.me.uk/rpi/pigpio/download.html).
Once pigpio is installed, you may download and build this program. To do so, run the following lines in the terminal:
```bash

```
Then you may run the program:
```bash
sudo ./bin/mpu9250
```

## Functionality
* [X] Read and output inertial measurment unit data
* [X] Read and output temperature data
* [X] Calculate and log maximums and minimums to a file
* [ ] Read and output magnetometer data
* [ ] Plot the data on graphs