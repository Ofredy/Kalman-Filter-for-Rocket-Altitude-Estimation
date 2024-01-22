#include "../include/configs.h"

// System Constants
const double DELTA_T = 0.25;                              // s
const double ACCELEROMETER_MEASUREMENT_ERR_STD = 0.1;     //  m/(s^2)

// State Transition Matrix F
const Gs::Matrix<double, 2, 2> F = { 1.0, 0.25,
                                     0.0, 1.0 }; 

// Control Matrix G
const Gs::Matrix<double, 2, 1> G = { 0.0313,
                                     0.25 };

// Process Noise Matrix Q
const Gs::Matrix<double, 2, 2> Q = { pow(DELTA_T, 4)/4, pow(DELTA_T, 3)/2,
                                     pow(DELTA_T, 3)/2, pow(DELTA_T, 2) };

// Observation Matrix H
const Gs::Matrix<double, 1, 2> H = { 1, 0 };

// Measurement Uncertainty R
const Gs::Matrix<double, 1, 1> R = { 400 };

// Altitude and Acceleration Measurements
const std::vector<double> ALTITUDE_MEASUREMENTS = { 6.43, 1.3, 39.43, 45.89, 41.44, 48.7, 78.06, 80.08, 61.77, 75.15,
                                                    110.39, 127.83, 158.75, 156.55, 213.32, 229.82, 262.8, 297.57, 335.69, 367.92,
                                                    377.19, 411.18, 460.7, 468.39, 553.9, 583.97, 655.15, 723.09, 736.85, 787.22 };
const std::vector<double> ACCELERATION_MEASUREMENTS = { 39.81, 39.67, 39.81, 39.84, 40.05, 39.85, 39.78, 39.65, 39.67, 39.78,
                                                        39.59, 39.87, 39.85, 39.59, 39.84, 39.9, 39.63, 39.59, 39.76, 39.79, 
                                                        39.73, 39.93, 39.83, 39.85, 39.94, 39.86, 39.76, 39.86, 39.74, 39.94 };
