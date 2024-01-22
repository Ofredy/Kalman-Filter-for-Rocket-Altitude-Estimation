# System imports
import re

# Library imports
import numpy as np
import matplotlib.pyplot as plt


# Configs
NUM_DATA_POINTS = 30 
DELTA_T = 0.25
NUM_LINES_FOR_EACH_DATA_POINT = 6
ESTIMATE_LINE = 2
MEASUREMENT_LINE = 5

time_steps = np.arange(0, DELTA_T*NUM_DATA_POINTS, DELTA_T)
estimates = np.zeros((NUM_DATA_POINTS, 1))
measurements = np.zeros((NUM_DATA_POINTS, 1))


# Parsing the output txt file
with open('data_rocket_altitude_estimation.txt', 'r') as file:

    lines = file.readlines()

    data_idx = 0

    for idx, line in enumerate(lines):

        if idx % NUM_LINES_FOR_EACH_DATA_POINT == ESTIMATE_LINE:

            estimates[data_idx] = float(re.findall(r"[-+]?(?:\d*\.*\d+)", line)[0])

        elif idx % NUM_LINES_FOR_EACH_DATA_POINT == MEASUREMENT_LINE:

            measurements[data_idx] = float(re.findall(r"[-+]?(?:\d*\.*\d+)", line)[0])
            data_idx += 1

# Plotting the results and saving them as a jpg
figure, axis = plt.subplots(1, 1)

axis.plot(time_steps, estimates, label='Estimates')
axis.plot(time_steps, measurements, label='Measurements')
axis.legend()
axis.set_xlabel('Time [s]')
axis.set_ylabel('Altitude [m]')
axis.set_title('Rocket Altitude Kalman Filter')

plt.savefig('rocket_altitude_kf_results.jpg')