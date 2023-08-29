#ifndef _KALMAN_FILTER_
#define _KALMAN_FILTER_

#include <iostream>
#include <fstream>

#include <Gauss/Gauss.h>
#include "configs.h"

class KalmanFilter
{

    public:
        
        // Rocekt altitude estimation kalman filter
        void rocket_altitude_kalman_filter(std::ofstream& output_file,
                                           Gs::Matrix<double, 2, 2> F, 
                                           Gs::Matrix<double, 2, 1> G, 
                                           Gs::Matrix<double, 2, 2> Q,
                                           Gs::Matrix<double, 1, 2> H,
                                           Gs::Matrix<double, 1, 1> R,
                                           std::vector<double> ALTITUDE_MEASUREMENTS,
                                           std::vector<double> ACCELERATION_MEASUREMENTS);
                                           
};

#endif