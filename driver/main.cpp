//
// Created by pi on 12.12.2020.
//

#include <iostream>
#include "driver.h"
#include "driverManager.h"

using namespace std;

int main() {
    if (wiringPiSetup() == 0) {
//        softPwmCreate(25, 100, 100);
//        softPwmCreate(24, 100, 100);
//        delay(1000);
//        softPwmStop(25);
//        softPwmStop(24);
//        delay(1000);
//        softPwmCreate(28, 100, 100);
//        softPwmCreate(27, 100, 100);
//        delay(1000);
//        softPwmStop(28);
//        softPwmStop(27);
//        delay(1000);
//        softPwmCreate(25, 100, 100);
//        softPwmCreate(27, 100, 100);
//        delay(1000);
//        softPwmStop(25);
//        softPwmStop(27);
//        delay(1000);
//        softPwmCreate(24, 100, 100);
//        softPwmCreate(28, 100, 100);
//        delay(1000);
//        softPwmStop(24);
//        softPwmStop(28);
//        delay(1000);
//
//        Driver left(27, 24);
//        Driver right(28, 25);//= new Driver(16, 20);
//
//        left.moveFwd(100);
//        right.moveFwd(100);
//
//        delay(1000);
//
//        left.moveBwd(100);
//        right.moveBwd(100);
//
//        delay(1000);
//
//        left.stop();
//        right.stop();

        DriverManager driverManager;
        driverManager.move(100, 100);
        delay(1000);
        driverManager.move(-100, -100);
        delay(1000);
        driverManager.move(-100, 100);
        delay(1000);
        driverManager.move(100, -100);
        delay(1000);
        driverManager.stop();
    }
    return 1;
}