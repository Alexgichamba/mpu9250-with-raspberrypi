#include "../inc/stats.h"

//deque
std::deque <std::string> deq_time;
std::deque <double> deq_temp;
std::deque <double> deq_accel_x;
std::deque <double> deq_accel_y;
std::deque <double> deq_accel_z;
std::deque <double> deq_gyro_x;
std::deque <double> deq_gyro_y;
std::deque <double> deq_gyro_z;
std::deque <double> deq_mag_x;
std::deque <double> deq_mag_y;
std::deque <double> deq_mag_z;

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
                    */
                   )
{
    int append_handle = 0;
    int counter = 1;
    //push back readings into deque
    deq_time.push_back(time_date);
    deq_temp.push_back(temp);
    deq_accel_x.push_back(accel_x);
    deq_accel_y.push_back(accel_y);
    deq_accel_z.push_back(accel_z);
    deq_gyro_x.push_back(gyro_x);
    deq_gyro_y.push_back(gyro_y);
    deq_gyro_z.push_back(gyro_z);
    /*
    deq_mag_x.push_back(mag_x);
    deq_mag_y.push_back(mag_y);
    deq_mag_z.push_back(mag_z);
    */
    while (counter > 1)
    {
        if (deq_time.size() || deq_temp.size() == 0)
            append_handle = -1;
        if (deq_accel_x.size() || deq_accel_y.size() || deq_accel_z.size() == 0)
            append_handle = -2;
        if (deq_gyro_x.size() || deq_gyro_y.size() || deq_gyro_z.size() == 0)
            append_handle = -3;
            /*
        if (deq_mag_x.size() || deq_mag_y.size() || deq_mag_z.size() == 0)
            append_handle = -4;
            */
    }   
   counter++;
    return append_handle;
}

void get_stats()
{   
    //find min and max
    auto temp_min_max = std::minmax_element(deq_temp.begin(), deq_temp.end());
    auto accel_x_min_max = std::minmax_element(deq_accel_x.begin(), deq_accel_x.end());
    auto accel_y_min_max = std::minmax_element(deq_accel_y.begin(), deq_accel_y.end());
    auto accel_z_min_max = std::minmax_element(deq_accel_z.begin(), deq_accel_z.end());
    auto gyro_x_min_max = std::minmax_element(deq_gyro_x.begin(), deq_gyro_x.end());
    auto gyro_y_min_max = std::minmax_element(deq_gyro_y.begin(), deq_gyro_y.end());
    auto gyro_z_min_max = std::minmax_element(deq_gyro_z.begin(), deq_gyro_z.end());
    /*
    auto mag_x_min_max = std::minmax_element(deq_mag_x.begin(), deq_mag_x.end());
    auto mag_y_min_max = std::minmax_element(deq_mag_y.begin(), deq_mag_y.end());
    auto mag_z_min_max = std::minmax_element(deq_mag_z.begin(), deq_mag_z.end());
    */
    //write stats to file
    std::ofstream fout;
    fout.open("stats.txt",std::ios::out); //open file to write
    if (!fout.is_open())
    {
        std::cout << "Unable to write to file: stats.txt\n";
        exit(EXIT_FAILURE);
    }
    
    fout << "Stats: \n\n";

    fout << "MAXIMUMS\n";
    fout << "Temperature: " << *MAXTEMP << " at: " << deq_time[MAXTEMP - deq_temp.begin()];
    fout << "Acceleration in x: " << *MAXACCELX << " at: " << deq_time[MAXACCELX - deq_accel_x.begin()];
    fout << "Acceleration in y: " << *MAXACCELY << " at: " << deq_time[MAXACCELY - deq_accel_y.begin()];
    fout << "Acceleration in z: " << *MAXACCELZ << " at: " << deq_time[MAXACCELZ - deq_accel_z.begin()];
    fout << "Rate of rotation in x: " << *MAXGYROX << " at: " << deq_time[MAXGYROX - deq_gyro_x.begin()];
    fout << "Rate of rotation in y: " << *MAXGYROY << " at: " << deq_time[MAXGYROY - deq_gyro_y.begin()];
    fout << "Rate of rotation in z: " << *MAXGYROZ << " at: " << deq_time[MAXGYROZ - deq_gyro_z.begin()];
    /*
    fout << "Mag flux density in x: " << *MAXMAGX << " at: " << deq_time[MAXMAGX - deq_mag_x.begin()];
    fout << "Mag flux density in y: " << *MAXMAGY << " at: " << deq_time[MAXMAGY - deq_mag_y.begin()];
    fout << "Mag flux density in z: " << *MAXMAGZ << " at: " << deq_time[MAXMAGZ - deq_mag_z.begin()];
    */
    fout << "\nMINIMUMS\n";
    fout << "Temperature: " << *MINTEMP << " at: " << deq_time[MINTEMP - deq_temp.begin()];
    fout << "Acceleration in x: " << *MINACCELX << " at: " << deq_time[MINACCELX - deq_accel_x.begin()];
    fout << "Acceleration in y: " << *MINACCELY << " at: " << deq_time[MINACCELY - deq_accel_y.begin()];
    fout << "Acceleration in z: " << *MINACCELZ << " at: " << deq_time[MINACCELZ - deq_accel_z.begin()];
    fout << "Rate of rotation in x: " << *MINGYROX << " at: " << deq_time[MINGYROX - deq_gyro_x.begin()];
    fout << "Rate of rotation in y: " << *MINGYROY << " at: " << deq_time[MINGYROY - deq_gyro_y.begin()];
    fout << "Rate of rotation in z: " << *MINGYROZ << " at: " << deq_time[MINGYROZ - deq_gyro_z.begin()];
    /*
    fout << "Mag flux density in x: " << *MINMAGX << " at: " << deq_time[MINMAGX - deq_mag_x.begin()];
    fout << "Mag flux density in y: " << *MINMAGY << " at: " << deq_time[MINMAGY - deq_mag_y.begin()];
    fout << "Mag flux density in z: " << *MINMAGZ << " at: " << deq_time[MINMAGZ - deq_mag_z.begin()];
    */
}
