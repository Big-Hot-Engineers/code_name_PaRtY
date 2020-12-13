cmake_minimum_required(VERSION 3.17)
project(Robotic_way)

set(CMAKE_CXX_STANDARD 14)

add_executable(Robotic_way main.cpp ../driver/lib/Robot.cpp ../driver/lib/Robot.h ../driver/lib/Interface.cpp ../driver/lib/Interface.h main.h)