//
// Created by pi on 12.12.2020.
//

#include "main.h"


DriverManager::DriverManager (): left(27, 24),
                                 right(28, 25) {}

void DriverManager::move(int speedLeft, int speedRight) {
    if (speedLeft > 0 && speedRight > 0) {
        left.moveFwd(speedLeft);
        right.moveFwd(speedRight);
    }
    if (speedLeft < 0 && speedRight < 0) {
        left.moveBwd(-1 * speedLeft);
        right.moveBwd(-1 * speedRight);
    }
    if (speedLeft > 0 && speedRight < 0) {
        left.moveFwd(speedLeft);
        right.moveBwd(-1 * speedRight);
    }
    if (speedLeft < 0 && speedRight > 0) {
        left.moveBwd(-1 * speedLeft);
        right.moveFwd(speedRight);
    }
}

void DriverManager::stop() {
    left.stop();
    right.stop();
}