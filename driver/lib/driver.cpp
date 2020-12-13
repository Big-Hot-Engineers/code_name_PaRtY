//
// Created by pi on 07.12.2020.
//


#include "main.h"

using namespace std;

Driver::Driver(int fwdPin, int bwdPin) {
    this->fwdPin = fwdPin;
    this->bwdPin = bwdPin;
}


void Driver::moveFwd(int pwmValue = 100) {
    softPwmStop(bwdPin);
    softPwmCreate(fwdPin, pwmValue, 100);
}

void Driver::moveBwd(int pwmValue = 100) {
    softPwmStop(fwdPin);
    softPwmCreate(bwdPin, pwmValue, 100);
}

void Driver::stop() {
    softPwmStop(fwdPin);
    softPwmStop(bwdPin);
}



