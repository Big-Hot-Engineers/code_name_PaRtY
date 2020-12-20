cmake_minimum_required(VERSION 3.17)
project(Serial_)

set(CMAKE_CXX_STANDARD 14)

add_executable(Serial_ main.cpp file_descriptor.cpp serial.cpp base_exception.cpp Sensors.cpp Sensors.h IK_sensor.cpp IK_sensor.h Sensor_interface.cpp Sensor_interface.h Gyroscope.cpp Gyroscope.h)