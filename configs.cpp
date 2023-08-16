#include "configs.h"


// System Constants
const double DELTA_T = 0.25;                              // m/s
const double ACCELEROMETER_MEASUREMENT_ERR_STD = 0.1;     //  m/(s^2)

// State Transition Matrix F
const vector<vector<double>> F = {{ 1.0, 0.25 },
                                  { 0.0, 1.0 }}; 

// Control Matrix G
const vector<vector<double>> G = {{ 0.0313 },
                                  { 0.25 }};

// Process Noise Matrix Q
const vector<vector<double>> Q = {{ pow(DELTA_T, 4)/4, pow(DELTA_T, 3)/2 },
                                  { pow(DELTA_T, 3)/2, pow(DELTA_T, 2) }};

// Altitude and Acceleration Measurements
#define NUM_MEASUREMENTS    30
const vector<vector<double>> ALTITUDE_MEASUREMENTS = {{ 6.43, 1.3, 39.43, 45.89, 41.44, 48.7, 78.06, 80.08, 61.77, 75.15,
                                                        110.39, 127.83, 158.75, 156.55, 213.32, 229.82, 262.8, 297.57, 335.69, 367.92,
                                                        377.19, 411.18, 460.7, 468.39, 553.9, 583.97, 655.15, 723.09, 736.85, 787.22 }};
const vector<vector<double>> ACCELERATION_MEASUREMENTS = {{ 39.81, 39.67, 39.81, 39.84, 40.05, 39.85, 39.78, 39.65, 61.77, 75.15,
                                                            110.39, 127.83, 158.75, 156.55, 213.32, 229.82, 262.8, 297.57, 335.69, 367.92, 
                                                            377.19, 411.18, 460.7, 468.39, 553.9, 583.97, 655.15, 723.09, 736.85, 787.22 }};
