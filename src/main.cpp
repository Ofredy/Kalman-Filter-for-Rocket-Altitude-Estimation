#include <iostream>
#include <fstream>

#include "../include/configs.h"
#include "../include/kalman_filter.h"

int main()
{

    std::ofstream output_file;
    output_file.open("data_rocket_altitude_estimation.txt");

    KalmanFilter rocket_altitude_estimation;
    rocket_altitude_estimation.rocket_altitude_kalman_filter(output_file, F, G, Q, H, R, ALTITUDE_MEASUREMENTS, ACCELERATION_MEASUREMENTS);

    output_file.close();

    return 0;
}