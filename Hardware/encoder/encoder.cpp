//
// Created by pi on 13.12.2020.
//

#include "encoder.h"
#include <iostream>
#include <functional>
using namespace std;

int leftPin = 0;
int rightPin = 2;
int leftCounter = 0;
int rightCounter = 0;
int rightDirection = 1;
int leftDirection = 1;

int leftValue = 0;
int rightValue = 0;

void lEncoderCounter() {
    leftCounter += leftDirection;
}

void rEncoderCounter() {
    rightCounter += rightDirection;
}


Encoder::Encoder (int pin) :    pin(pin),
                                direction(1) {
    while ((this->pin != leftPin) && (this->pin != rightPin)) {
        cout << "Encoder wrong pin. Please change pin, leftPin = " << leftPin << " rightPin = "  << rightPin << endl;
        cin >> this->pin;
        cout << endl;
    }
    wiringPiSetup();
    pinMode(this->pin, INPUT);

}

int Encoder::getValue() {
    return digitalRead(this->pin);
}

int Encoder::getCounter() {
    if (this->pin == rightPin) {return leftCounter;}
    if (this->pin == leftPin)  {return rightCounter;}
    return 1;
}

int Encoder::getPin() {
    return pin;
}

int Encoder::getDirection() {
    return direction;
}

void Encoder::changeDirection(int direction) {
    if (direction > 0)
        this->direction = 1;
    if (direction < 0)
        this->direction = -1;
    if (pin == rightPin) {rightDirection = this->direction;}
    if (pin == leftPin)  {leftDirection  = this->direction;}
}

int leftSpeed  = 0;
int rightSpeed = 0;

int main() {
    wiringPiSetup();
    Encoder left(leftPin);
    Encoder right(rightPin);

    int leftPrew  = left.getValue();
    int rightPrew = right.getValue();

    cout << "enter right and left speed" << endl;
    cin >> leftSpeed >> rightSpeed;
    cout << endl;
    while (true) {
        if ((left.getValue() != leftPrew)   && (leftSpeed !=  0)) {
            leftPrew  = left.getValue() ;
            leftCounter++;
        }
        if ((right.getValue() != rightPrew) && (rightSpeed != 0)) {
            rightPrew = right.getValue() ;
            rightCounter++;
        }
        cout << "   rightCounter: " << rightCounter << endl;
        cout << "   leftCounter:  "  << leftCounter;
    }

    return 0;
}
