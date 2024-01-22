#include "../include/kalman_filter.h"

// Rocekt altitude estimation kalman filter
void KalmanFilter::rocket_altitude_kalman_filter(std::ofstream& output_file,
                                                 Gs::Matrix<double, 2, 2> F, 
                                                 Gs::Matrix<double, 2, 1> G, 
                                                 Gs::Matrix<double, 2, 2> Q,
                                                 Gs::Matrix<double, 1, 2> H,
                                                 Gs::Matrix<double, 1, 1> R,
                                                 std::vector<double> ALTITUDE_MEASUREMENTS,
                                                 std::vector<double> ACCELERATION_MEASUREMENTS)
{
    // Creating helper matrices
    Gs::Matrix<double, 1, 1> K_t_calc_step;
    Gs::Matrix<double, 1, 1> Measurement_t;
    Gs::Matrix<double, 2, 2> P_t_calc_step;
    Gs::Matrix<double, 2, 2> I = { 1, 0,
                                   0, 1 };
    
    // Create state vector and make initial predictions
    Gs::Matrix<double, 2, 1> X_t = { 0.0,
                                     0.0 };

    // Make an initial prediction on acceleration as well
    double u_t = 0;

    // Since our initial state vector is a guess, we set a very high state uncertainty
    Gs::Matrix<double, 2, 2> P_t = { 500, 0,
                                     0, 500 };

    // Creating the Kalman Gain Vector
    Gs::Matrix<double, 2, 1> K_t;

    // We make our first state prediction based of our inital guesses
    X_t = F * X_t + G * u_t;
    P_t = F * P_t * F.Transposed() + Q;

    // Now we can start iterating through the measurement data
    for( int time_step=0; time_step<NUM_MEASUREMENTS; time_step++ )
    {
        output_file << "time_step " << time_step << std::endl;

        // First calculate the Kalman Gain
        K_t_calc_step = H * P_t * H.Transposed() + R;
        K_t = P_t * H.Transposed() * ( 1 / K_t_calc_step(0, 0) );

        // Estimate the current state using the new gain
        Measurement_t = { ALTITUDE_MEASUREMENTS[time_step] };
        X_t = X_t + K_t * ( Measurement_t - H * X_t );
        output_file << "State Estimate" << std::endl;
        output_file << X_t;
        output_file << "Altitude Measurements" << std::endl;
        output_file << ALTITUDE_MEASUREMENTS[time_step] << std::endl;

        // Update the estimate uncertainty
        P_t_calc_step = I - K_t * H;
        P_t = P_t_calc_step * P_t * P_t_calc_step.Transposed() + K_t * R * K_t.Transposed();

        // Now we we predict the next state
        u_t = ACCELERATION_MEASUREMENTS[time_step] - 9.8;
        X_t = F * X_t + G * u_t;
        P_t = F * P_t * F.Transposed() + Q;
    }
}