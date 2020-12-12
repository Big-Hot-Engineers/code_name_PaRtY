#include <iostream>
#include "main.h"

int main() {
    Interface robot_manager;
    std::cout << "OK" << std::endl;
    robot_manager.map_initialization();
    robot_manager.random_movement();
    return 0;
}
