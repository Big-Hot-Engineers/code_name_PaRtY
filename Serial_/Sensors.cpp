#include "Sensors.h"

Sensor::Sensor(): sensor_data(0) {}

int Sensor::get_sensor_data() {
    return sensor_data;
}

void Sensor::set_sensor_data(int sensor_data) {
    this->sensor_data = sensor_data;
}
