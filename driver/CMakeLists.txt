cmake_minimum_required(VERSION 3.13)
project(driver)

set(CMAKE_CXX_STANDARD 17)

add_library(driver lib/driver.cpp lib/driverManager.cpp)

target_include_directories(driver PUBLIC lib)

target_link_libraries(driver PUBLIC wiringPi pthread)

add_executable(driver_exec main.cpp)

target_link_libraries(driver_exec driver)