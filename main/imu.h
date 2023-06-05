#include <Arduino.h>


#ifndef IMU_H
#define IMU_H

void imuSetup();

void imuUpdateReading();

void imuCalibrate();

float imuGetAngleX();

float imuGetAngleY();

float imuGetAccelX();

float imuGetAccelY();



#endif
