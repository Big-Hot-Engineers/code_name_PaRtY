#include "Sensor_interface.h"
#include "serial.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

constexpr const char *serial_port = "/dev/ttyUSB0";

Sensor_interface::Sensor_interface() {
    IK_vector.resize(6);
}

void Sensor_interface::read_data_from_serial()  {
    serial::Connection connection(serial_port, 115200);
    while (true) {
        std::string buf(34, '\0');

        while (connection.read((void *) buf.data(), buf.length()) <= 0) {
            std::this_thread::sleep_for(0.010s);
        }
        if (buf[0] != '[' || buf[33] != ']' || buf.length() != 34) {
            continue;
        }

        std::vector<int> sensors_data;
        sensors_data.resize(7);
        std::this_thread::sleep_for(0.010s);
        std::cout << buf << std::endl;

        int open_chamber = 0;
        int close_chamber = 0;
        bool is_data_correct = true;
        int j = 0;
        for (int i = 0; i < buf.length(); ++i) {
            if (buf[i] == '[') {
                ++open_chamber;
                ++i;
                while (buf[i] != ']') {
                    sensors_data[j] = sensors_data[j] * 10 + (int) buf[i] - 48;
                    ++i;
                }
                ++close_chamber;
            }
            ++j;
        }

        if (open_chamber != this->IK_vector.size() + 1 || close_chamber != this->IK_vector.size() + 1) {
            is_data_correct = false;
        }

        if (is_data_correct) {
            for (int i = 0; i < this->IK_vector.size(); ++i) {
                this->IK_vector[i].set_sensor_data(sensors_data[i]);
            }
            this->gyro.set_sensor_data(sensors_data.back());

            for (int i = 0; i < this->IK_vector.size(); ++i) {
                std::cout << IK_vector[i].get_sensor_data() << std::endl;
            }
            std::cout << gyro.get_sensor_data() << std::endl;
        }
        if (!is_data_correct) {
            std::cout << "Not correct data" << std::endl;
        }
    }
}
