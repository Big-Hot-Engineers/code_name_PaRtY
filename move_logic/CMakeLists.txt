cmake_minimum_required(VERSION 3.17)
project(Robotic_way)

set(CMAKE_CXX_STANDARD 14)

add_executable(Robotic_way main.cpp Robot.cpp Robot.h Interface.cpp Interface.h main.h)