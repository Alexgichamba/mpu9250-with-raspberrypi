#include "../inc/timer.h"

std::string get_time(){
    //get time
    system_clock::time_point rawtime = system_clock::now();
    time_t tt = system_clock::to_time_t ( rawtime );
    std::string time_date = ctime(&tt);
    return time_date;
}

void device_wait(int time_to_wait){
    std::this_thread::sleep_for(std::chrono::milliseconds(time_to_wait));
}