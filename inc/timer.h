#pragma once

#include <chrono>
#include <thread>
#include <string>

using namespace std::chrono;

//function to get time
std::string get_time();

void device_wait(int time_to_wait);



