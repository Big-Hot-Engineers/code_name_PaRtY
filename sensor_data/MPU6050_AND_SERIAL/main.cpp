#include <iostream>
#include "MPU6050.h"
#include <time.h>

using namespace std;

int main()
{
	MPU6050 mpu6050;
	mpu6050.connect("/dev/ttyUSB0");
	while (1 != 0)
	{
		usleep(100000);
		cout << mpu6050.getYaw() << endl;
	}
		return 0;
}