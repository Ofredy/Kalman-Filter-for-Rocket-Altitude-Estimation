#ifndef _CONFIGS_
#define _CONFIGS_

#include <iostream>
#include <vector>
#include <cmath>

#include <Gauss/Gauss.h>

// System Constants
extern const double DELTA_T;                                // s
#define ROCKET_ACCELERATION                     30          // m/s
#define ALTIMETER_MEASUREMENT_ERR_STD           20          // m
extern const double ACCELEROMETER_MEASUREMENT_ERR_STD;      //  m/(s^2)

// State Transition Matrix F
extern const Gs::Matrix<double, 2, 2> F; 

// Control Matrix G
extern const Gs::Matrix<double, 2, 1> G;

// Process Noise Matrix Q
extern const Gs::Matrix<double, 2, 2> Q;

// Observation Matrix H
extern const Gs::Matrix<double, 1, 2> H;

// Measurement Uncertainty R
extern const Gs::Matrix<double, 1, 1> R;

// Altitude and Acceleration Measurements
#define NUM_MEASUREMENTS    30
extern const std::vector<double> ALTITUDE_MEASUREMENTS;
extern const std::vector<double> ACCELERATION_MEASUREMENTS;

#endif