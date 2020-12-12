cmake_minimum_required(VERSION 3.14)
project(code_name_PaRtY)

set(SOURCE_EXE main.cpp)
set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_subdirectory(positioning)
add_subdirectory(arduino)
add_subdirectory(cv)
add_subdirectory(map)
add_subdirectory(move_logic)
add_subdirectory(driver)

add_executable(main ${SOURCE_EXE})