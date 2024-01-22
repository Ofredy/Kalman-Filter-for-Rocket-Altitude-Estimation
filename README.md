# Kalman-Filter-for-Rocket-Altitude-Estimation

The source used to generate this code is, KalmanFilter.net, an ebook created by Alex Becker.

I recreated the kalman filter for rocket altitude estimation from the python script provided by KalmanFilter.net. The purpose of this is to gain an understanding of the kalman filter and to implement the code in c++.

The system is a multivariate LTI system. The rocket ascent is simplified to have a constant acceleration and the states being tracked are the postion and velocity.

To Compile run the Makefile in the src folder.
  - NOTE: THE Makefile was made for windows, changes may be needed to run on linux or mac
  - Commands to build and run the code are:
      - cd to src
      - make
      - ./rocket_attitude_estimation
      - cd to results
      - python plotting_results.py

The results of the rocket altitude kalman filter are:
![alt text](src/results/rocket_altitude_kf_results.jpg?raw=true)
