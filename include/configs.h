#ifndef CONFIGS
#define CONFIGS

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

// Measurement Uncertainty R
#define R   400

// Altitude and Acceleration Measurements
#define NUM_MEASUREMENTS    30
extern const Gs::Matrix<double, 1, NUM_MEASUREMENTS> ALTITUDE_MEASUREMENTS;
extern const Gs::Matrix<double, 1, NUM_MEASUREMENTS> ACCELERATION_MEASUREMENTS;

#endif