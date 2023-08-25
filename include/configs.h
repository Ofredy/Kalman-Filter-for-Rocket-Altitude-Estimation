#ifndef CONFIGS
#define CONFIGS

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// System Constants
extern const double DELTA_T;                                // s
#define ROCKET_ACCELERATION                     30          // m/s
#define ALTIMETER_MEASUREMENT_ERR_STD           20          // m
extern const double ACCELEROMETER_MEASUREMENT_ERR_STD;      //  m/(s^2)

// State Transition Matrix F
extern const vector<vector<double>> F; 

// Control Matrix G
extern const vector<vector<double>> G;

// Process Noise Matrix Q
extern const vector<vector<double>> Q;

// Measurement Uncertainty R
#define R   400

// Altitude and Acceleration Measurements
#define NUM_MEASUREMENTS    30
extern const vector<vector<double>> ALTITUDE_MEASUREMENTS;
extern const vector<vector<double>> ACCELERATION_MEASUREMENTS;


#endif