////
//// Created by ilya on 03.12.2020.
////
//
//#include <Wire.h>
//#include <Servo.h>
//#include <I2Cdev.h>
//#include "MPU6050.h"
//
//MPU6050 gyro_1; //создание объекта gyro_1 класса MPU 6050
//
//const float KOEFF_GYRO_250 = 1 / 131.072, MILLISEC_2_SEC = 1 / 1000.0;
////131.072 -коэффициент масштаба сырых данных при 250град/сек
//const uint8_t T_INTEGR_GYRO = 10;
//
//const float NUM_READ =
//		1 / 1024.0;//для оптимизации деления (целого на целое) лучше использоввать 2^n, но нам нужен float
//float midArifm();
//
//float driftError;
//
//float elapsedTime, currentTime, currentTimeGyro, previousTime, servoTime, restTime;
//float yaw, oldYaw = 0;
//
//void setup()
//{
//	Serial.begin(9600);// Инициирование последовательного соединения со скоростью 9600 бод
//	gyro_1.initialize(); // первичная настройка датчика
//	gyro_1.setFullScaleAccelRange(MPU6050_ACCEL_FS_8);//режим 8g
//	gyro_1.setFullScaleGyroRange(MPU6050_GYRO_FS_250);//Максимальное значение уг. ск-ти 250 град/сек
//	Serial.println(gyro_1.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
//	delay(1000);
//	driftError = midArifm();
//	Serial.println(driftError);
//}
//
//uint16_t restCount = 0;
//int64_t time_count = 0;
//int16_t sumRest = 0;
//
//void loop()
//{
//	int16_t ax_raw, ay_raw, az_raw, gx_raw, gy_raw, gz_raw;//переменные для значений акселерометра и гироскопа
//	float gyro_z;
//
//	gyro_1.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);//опрос
//	previousTime = currentTimeGyro;        // Previous time is stored before the actual time read
//	currentTimeGyro = millis();            // Current time actual time read
//	elapsedTime = (currentTimeGyro - previousTime) * MILLISEC_2_SEC;
//
//	gyro_z = (float)gz_raw * KOEFF_GYRO_250 - driftError;
//	yaw = yaw + gyro_z * elapsedTime;
//
//	currentTime = millis();
//	Serial.println(yaw);
//
//}
//
//float midArifm()
//{
//	int16_t ax_raw, ay_raw, az_raw, gx_raw, gy_raw, gz_raw;//переменные для значений акселерометра и гироскопа
//
//	long sum = 0;                       // локальная переменная sum
//	for (int i = 0; i < 1024; i++)
//	{  // согласно количеству усреднений
//		gyro_1.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);//опрос
//		sum += gz_raw;
//	}// суммируем значения с любого датчика в переменную sum
//	return ((float)sum * NUM_READ * KOEFF_GYRO_250);
//}
//
