//
// Created by ilya on 10.12.2020.
//

#include "MPU6050.h"

void MPU6050::connect(std::string portName)
{
	portNumber = open(portName.c_str(), O_RDWR); //open to read amd write
	sleep(2);
	if (portNumber <= 0)
	{
		cout << ("Port open fail\n");
	}
	ssize_t readFlag = read(portNumber, buffer, NUMBER_OF_BYTES);
	cout << buffer;
}

void MPU6050::calibrate()
{

}

int MPU6050::getYaw()
{
	ssize_t readFlag = read(portNumber, buffer, 20);

	string yawString(buffer);
	if (yawString == "zero")
	{
		return 0;
	}
	return atoi(yawString.c_str());
}

int MPU6050::getPortNumber()
{
	return portNumber;
}

int MPU6050::getDx()
{
	return dx;
}

int MPU6050::getDy()
{
	return dy;
}

MPU6050::MPU6050()
{
	yaw = 0;
	dx = 0;
	dy = 0;
	portNumber = -1;
}
