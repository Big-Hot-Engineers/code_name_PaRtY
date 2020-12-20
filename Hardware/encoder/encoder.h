//
// Created by pi on 13.12.2020.
//

#ifndef CODE_NAME_PARTY_ENCODER_H
#define CODE_NAME_PARTY_ENCODER_H

#include <wiringPi.h>

class Encoder {
    int pin;
    int direction;
    int value;
public:
    Encoder(int pin);

    int getValue();

    int getPin();

    int getCounter();

    int getDirection();

    void changeDirection(int direction);
};

#endif //CODE_NAME_PARTY_ENCODER_H
