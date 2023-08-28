#include <iostream>
#include <fstream>

#include "../include/configs.h"
#include "../include/kalman_filter.h"

int main()
{

    KalmanFilter rocket_altitude_estimation("data_rocket_altitude_estimation.txt");
    rocket_altitude_estimation.rocket_altitude_kalman_filter(F, G, Q, H, R, ALTITUDE_MEASUREMENTS, ACCELERATION_MEASUREMENTS);

    return 0;
}