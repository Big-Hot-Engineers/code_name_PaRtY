cmake_minimum_required(VERSION 3.17)
project(Position_enc)

set(CMAKE_CXX_STANDARD 14)

add_executable(Position_enc main.cpp Position_from_enc.cpp Position_from_enc.h)