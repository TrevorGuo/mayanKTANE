#include <Arduino.h>
#include <stdio.h>
#include <iostream>

#include "modules/SymbolSequence.h"
#include "bomb.h"
#include "ring.h"
#include "utils.h"

#include <accel.h>
#include <spear.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "modules/SpearRotation/SpearRotation.h"

using namespace std;

// Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, NEOPIXEL_PIN, NEO_RGBW + NEO_KHZ800);
// ring* calendar = new ring(&strip);
Bomb b;

void button0ISR() {
    static int buttonNum = 0;
    Serial.println(buttonNum);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 10ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > DEBOUNCER_TIME)               // Debounce logic..
    {
        last_interrupt_time = interrupt_time;
        b.getSymbolModule()->readInput(buttonNum);
    }
}

void button1ISR() {
    static int buttonNum = 1;
    Serial.println(buttonNum);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 10ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > DEBOUNCER_TIME)               // Debounce logic..
    {
        last_interrupt_time = interrupt_time;
        b.getSymbolModule()->readInput(buttonNum);
    }
}

void button2ISR() {
    static int buttonNum = 2;
    Serial.println(buttonNum);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 10ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > DEBOUNCER_TIME)               // Debounce logic..
    {
        last_interrupt_time = interrupt_time;
        b.getSymbolModule()->readInput(buttonNum);
    }
}

void button3ISR() {
    static int buttonNum = 3;
    Serial.println(buttonNum);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 10ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > DEBOUNCER_TIME)               // Debounce logic..
    {
        last_interrupt_time = interrupt_time;
        b.getSymbolModule()->readInput(buttonNum);
    }
}

void button4ISR() {
    static int buttonNum = 4;
    Serial.println(buttonNum);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 10ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > DEBOUNCER_TIME)               // Debounce logic..
    {
        last_interrupt_time = interrupt_time;
        b.getSymbolModule()->readInput(buttonNum);
    }
}

void button5ISR() {
    static int buttonNum = 5;
    Serial.println(buttonNum);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 10ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > DEBOUNCER_TIME)               // Debounce logic..
    {
        last_interrupt_time = interrupt_time;
        b.getSymbolModule()->readInput(buttonNum);
    }
}

// bool prev_button_state = false;
// int state = 0;
// Servo spear;
// Adafruit_MPU6050 mpu;
// accel accelerometer(&mpu);
Servo spear;

SpearRotation spearGame = SpearRotation(&spear);
Adafruit_MPU6050 mpu;
accel acc(&mpu);
int prev_button = HIGH;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting!");

  //Attach interrupts
  pinMode(BUTTON_0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_0), button0ISR, FALLING);
  pinMode(BUTTON_1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_1), button1ISR, FALLING);
  pinMode(BUTTON_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_2), button2ISR, FALLING);
  pinMode(BUTTON_3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_3), button3ISR, FALLING);
  pinMode(BUTTON_4, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_4), button4ISR, FALLING);
  pinMode(BUTTON_5, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_5), button5ISR, FALLING);
  //Helper class for buttons 
  delay(2000);
  Serial.println("start");
  spearGame.begin();
  acc.init();
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

  pinMode(SERVO_BUTTON, INPUT);
  // spear.attach(SERVO_PIN);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

// int thing = 0;

bool finished = false;

void loop()
{
  // Serial.println("bing chillin");
  // delay(99);
  if (!finished) {
    int curr_butt = digitalRead(SERVO_BUTTON);
    if (curr_butt == LOW && prev_button == HIGH)
    {
        // thing = (thing + 1) % 180;
        // spear.write(thing);
        acc.update();

        ORIENTATION pos = acc.get_orientation();

        finished = spearGame.readInput(pos);

        // Serial.println      "Pressed");
    }
    prev_button = curr_butt;
  }
  delay(100);
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