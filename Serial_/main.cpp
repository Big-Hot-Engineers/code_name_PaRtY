#include "Sensor_interface.h"
#include <iostream>

int main() {
    Sensor_interface sensors_manager;
    std::cout << sensors_manager.IK_vector.size() <<std::endl;
    sensors_manager.read_data_from_serial();
    return 0;
}