//
// Created by pi on 12.12.2020.
//

#include <iostream>
#include "lib/main.h"

using namespace std;

int main() {
 //   Interface robot_manager;
 //   robot_manager.map_initialization();
    if (wiringPiSetup() == 0) {

        DriverManager driverManager;
        driverManager.move(100, 100);
        delay(1000);
        driverManager.move(-100, -100);
        delay(1000);
        driverManager.move(-100, 100);
        delay(10000);
        driverManager.move(100, -100);
        delay(10000);
        driverManager.stop();

    }
    return 1;
}