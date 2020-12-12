//
// Created by pi on 07.12.2020.
//

#ifndef CODE_NAME_PARTY_DRIVER_H
#define CODE_NAME_PARTY_DRIVER_H

#include <wiringPi.h>
#include <softPwm.h>

class Driver {
    int fwdPin;
    int bwdPin;
public:

    Driver(int fwdPin, int bwdPin);

   // ~Driver();

    void moveFwd(int pwmValue);

    void moveBwd(int pwmValue);

    void stop();
};


#endif //CODE_NAME_PARTY_DRIVER_H
