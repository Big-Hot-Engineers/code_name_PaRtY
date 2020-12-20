#ifndef MAIN_CPP_SENSOR_INTERFACE_H
#define MAIN_CPP_SENSOR_INTERFACE_H

#include <vector>
#include "IK_sensor.h"
#include "Gyroscope.h"

class Sensor_interface {
public:
    std::vector <IK_sensor> IK_vector;
    Gyroscope gyro;
    Sensor_interface();
    void read_data_from_serial();
};


#endif //MAIN_CPP_SENSOR_INTERFACE_H
