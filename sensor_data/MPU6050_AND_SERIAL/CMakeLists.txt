cmake_minimum_required(VERSION 3.15)
project(MPU6050_AND_SERIAL)

set(CMAKE_CXX_STANDARD 14)

add_executable(MPU6050_AND_SERIAL main.cpp MPU6050_AND_SERIAL.h MPU6050.cpp MPU6050.h)