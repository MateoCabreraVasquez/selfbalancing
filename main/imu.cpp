#include "Wire.h"
#include <Arduino.h>
#include "imu.h"

#include "MPU9250.h"
MPU9250 mpu;

#define CALIBRATION_SAMPLES 100
#define GYRO_DEBOUNCE 0.4


// Valores RAW (sin procesar) del acelerometro y giroscopio en los ejes x,y,z

float yAngle=0.0,xAngle=0.0,yAngle_offset=0.0,xAngle_offset=0.0,yAcc=0.0,xAcc=0.0;


void imuSetup(){
    Wire.begin();
    delay(2000);
    if (!mpu.setup(0x68)) {  // change to your own address
        while (1) {
            Serial.println("MPU connection failed. Please check your connection with `connection_check` example.");
            delay(5000);
        }
    }
    Serial.println("IMU conected succes");
}

void imuCalibrate(){
    // calibrate anytime you want to
    Serial.println("Accel Gyro calibration will start in 5sec.");
    Serial.println("Please leave the device still on the flat plane. And press Any key");
    while (true){if(Serial.available()){break;}}
    while(Serial.available()){Serial.read();}
    mpu.calibrateAccelGyro();
    Serial.println("IMU calibrated");

float xProm= 0.0;
float yProm= 0.0;
for (int i =0; i<CALIBRATION_SAMPLES; i++){
    imuUpdateReading();
    xProm =xProm+ mpu.getRoll();
    yProm = yProm +mpu.getPitch();
}
yAngle_offset=yProm/CALIBRATION_SAMPLES;
xAngle_offset=xProm/CALIBRATION_SAMPLES;


Serial.print(yAngle_offset);
delay(2000);

}



void imuUpdateReading(){
  if (mpu.update()) {
        static uint32_t prev_ms = millis();
        if (millis() > prev_ms + 25) {
            float tempX=mpu.getRoll();
            float tempY=mpu.getPitch();
            if(abs(tempX-xAngle)>GYRO_DEBOUNCE) xAngle =tempX;
            if(abs(tempY-yAngle)>GYRO_DEBOUNCE) yAngle =tempY;
            xAcc=mpu.getAccX();
            yAcc=mpu.getAccY();
            prev_ms = millis();
        }
    }


}

float imuGetAngleX(){
  return xAngle-xAngle_offset;
}

float imuGetAngleY(){
  return yAngle-yAngle_offset;
}

float imuGetAccelX(){
  return xAcc*9.8;
}

float imuGetAccelY(){
  return yAcc*9.8;
}

