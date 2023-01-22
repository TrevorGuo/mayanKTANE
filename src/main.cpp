#include <Arduino.h>
#include <stdio.h>
#include <iostream>

#include "modules/SymbolSequence/SymbolSequence.h"

using namespace std;

#include <accel.h>
#include <spear.h>
#include <Servo.h>
#include "modules/SpearRotation/SpearRotation.h"
#define SUBMIT_BUTTON 5

// bool prev_button_state = false;
// int state = 0;
// Servo spear;
// Adafruit_MPU6050 mpu;
// accel accelerometer(&mpu);
Servo spear;

SpearRotation spearGame = SpearRotation(&spear);
Adafruit_MPU6050 mpu;
accel acc(&mpu);
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(2000);

  // SymbolSequence symbolSequenceModule;
  // symbolSequenceModule.begin();
  // Serial.println("LED 0 should be on");
  // delay(2000);
  // symbolSequenceModule.readInput(0);
  // Serial.println("LED 1 should be on");
  // delay(2000);
  // symbolSequenceModule.readInput(0);
  // Serial.println("LED 0 should be on");
  // delay(2000);
  // symbolSequenceModule.readInput(1);
  // Serial.println("BOTH should be on");
  // delay(2000);
  // symbolSequenceModule.readInput(2);
  // Serial.println("LED 0 should be on");
  //  accelerometer.init();

  pinMode(SUBMIT_BUTTON, INPUT);
  // spear.attach(SERVO_PIN);
}

void loop()
{
  if (digitalRead(SUBMIT_BUTTON) == LOW)
  {
    spearGame.readInput(SPEAR);
    Serial.println("Pressed");
    delay(1000);
  }
  // if (digitalRead(SUBMIT_BUTTON) && !prev_button_state) {
  //   Serial.println("button pressed");
  //   prev_button_state = true;
  //   accelerometer.update();
  //   if (state == 0) {
  //     if (accelerometer.get_orientation() == SIDE_3) {
  //       state = 1;
  //     }
  //     else {
  //       state = 0;
  //     }
  //     Serial.print("new state: ");
  //     Serial.println(state);
  //   }
  //   else if (state == 1) {
  //     if (accelerometer.get_orientation() == SIDE_1) {
  //       state = 2;
  //     }
  //     else {
  //       state = 0;
  //     }
  //     Serial.print("new state: ");
  //     Serial.println(state);
  //   }
  //   else if (state == 2) {
  //     if (accelerometer.get_orientation() == SIDE_4) {
  //       state = 3;
  //       Serial.println("you win");
  //     }
  //     else {
  //       state = 0;
  //     }
  //     Serial.print("new state: ");
  //     Serial.println(state);
  //   }
  //   else if (state == 3) {
  //     Serial.println("restarting");
  //     state = 0;
  //   }
  // }
  // if (!digitalRead(SUBMIT_BUTTON) && prev_button_state) {
  //   Serial.println("button unpressed");
  //   prev_button_state = false;
  // }

  // if (state == 1) {
  //   spear.write(SERVO_POS_CENTER);
  // }
  // else if (state == 2) {
  //   spear.write(SERVO_POS_LEFT);
  // }
  // else {
  //   spear.write(SERVO_POS_RIGHT);
  // }
}