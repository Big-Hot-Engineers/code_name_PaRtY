//
// Created by ilya on 10.12.2020.
//

#ifndef MPU6050_AND_SERIAL_MPU6050_H
#define MPU6050_AND_SERIAL_MPU6050_H
#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>

using namespace std;

const int SIZE_OF_BUFFER = 5;
const int NUMBER_OF_BYTES = 5;


class MPU6050
{
	int yaw = 0;
	int dx = 0;
	int dy = 0;

	int portNumber = -1;

	char buffer[SIZE_OF_BUFFER];
public:
	MPU6050 ();
	void connect(string Port_name);
	void calibrate();
	int getYaw();
	int getDx();
	int getDy();
	int getPortNumber();
};


#endif //MPU6050_AND_SERIAL_MPU6050_H
