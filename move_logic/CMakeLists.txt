cmake_minimum_required(VERSION 3.17)
project(Robotic_way)

set(CMAKE_CXX_STANDARD 14)

add_executable(Robotic_way main.cpp Robot/Robot.cpp Robot/Robot.h Interface/Interface.cpp Interface/Interface.h main.h)