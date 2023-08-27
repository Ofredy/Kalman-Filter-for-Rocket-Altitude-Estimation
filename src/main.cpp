#include <iostream>

#include "../include/configs.h"
#include "../include/kalman_filter.h"

int main()
{

    std::cout << "Printing Measurement Data" << std::endl;

    std::cout << ALTITUDE_MEASUREMENTS << std::endl;
    std::cout << ACCELERATION_MEASUREMENTS << std::endl;

    return 0;
}