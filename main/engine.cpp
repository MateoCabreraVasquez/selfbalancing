#include <Arduino.h>

// *************************************************
//                  PIN DEFINITIONS 
// *************************************************
// Motor A
#define MOTOR_A_IN1 4
#define MOTOR_A_IN2 5
#define MOTOR_A_ENE 3

// Motor B
#define MOTOR_b_ENE 10
#define MOTOR_B_IN1 8
#define MOTOR_B_IN2 9


// *************************************************
//                     CONSTANTS
// *************************************************
const uint8_t  STOP[] = {LOW,LOW,LOW,LOW};
const uint8_t  FORWARD[] = {LOW,HIGH,LOW,HIGH};
const uint8_t  BACKWARD[] = {HIGH,LOW,HIGH,LOW};
const uint8_t  LEFT[] = {LOW,LOW,LOW,HIGH};
const uint8_t  RIGHT[] = {LOW,HIGH,LOW,LOW};


// *************************************************
//                    SETUP
// *************************************************

void engineSetup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MOTOR_A_ENE, OUTPUT);
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_A_PWM, OUTPUT);

  pinMode(MOTOR_b_ENE, OUTPUT);
  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);
  pinMode(MOTOR_B_PWM, OUTPUT);

  digitalWrite(MOTOR_A_ENE, HIGH);
  digitalWrite(MOTOR_b_ENE, HIGH);
}

// *************************************************
//                    FUNCTIONS
// *************************************************

void engineStop() {
  digitalWrite(MOTOR_A_IN1, STOP[0]);
  digitalWrite(MOTOR_A_IN2, STOP[1]);
  digitalWrite(MOTOR_B_IN1, STOP[2]);
  digitalWrite(MOTOR_B_IN2, STOP[3]);
}

void engineForward() {
  digitalWrite(MOTOR_A_IN1, FORWARD[0]);
  digitalWrite(MOTOR_A_IN2, FORWARD[1]);
  digitalWrite(MOTOR_B_IN1, FORWARD[2]);
  digitalWrite(MOTOR_B_IN2, FORWARD[3]);
}

void engineBackward() {
  digitalWrite(MOTOR_A_IN1, BACKWARD[0]);
  digitalWrite(MOTOR_A_IN2, BACKWARD[1]);
  digitalWrite(MOTOR_B_IN1, BACKWARD[2]);
  digitalWrite(MOTOR_B_IN2, BACKWARD[3]);
}

void engineLeft() {
  digitalWrite(MOTOR_A_IN1, LEFT[0]);
  digitalWrite(MOTOR_A_IN2, LEFT[1]);
  digitalWrite(MOTOR_B_IN1, LEFT[2]);
  digitalWrite(MOTOR_B_IN2, LEFT[3]);
}

void engineRight() {
  digitalWrite(MOTOR_A_IN1, RIGHT[0]);
  digitalWrite(MOTOR_A_IN2, RIGHT[1]);
  digitalWrite(MOTOR_B_IN1, RIGHT[2]);
  digitalWrite(MOTOR_B_IN2, RIGHT[3]);
}

