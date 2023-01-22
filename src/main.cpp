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

using namespace std;


ring* calendar = new ring();
Bomb b(calendar);

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
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //  accelerometer.init();

  strip.begin();
  Serial.println("dom");
  strip.setBrightness(20);
  Serial.println("k");
  strip.fill(strip.Color(255, 0, 60), 10-10, 18 + 5);
  strip.show(); // Initialize all pixels to 'off'
  Serial.println("olson");


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

  // pinMode(SUBMIT_BUTTON, INPUT);
  // spear.attach(SERVO_PIN);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);
}

void loop() {
  // Serial.print(digitalRead(BUTTON_0));
  // Serial.print(digitalRead(BUTTON_1));
  // Serial.print(digitalRead(BUTTON_2));
  // Serial.print(digitalRead(BUTTON_3));
  // Serial.print(digitalRead(BUTTON_4));
  // Serial.println(digitalRead(BUTTON_5));
  delay(100);

  
  // Serial.println(LED_0);
  // digitalWrite(LED_0, HIGH);
  // delay(100);
  // Serial.println(LED_1);
  // digitalWrite(LED_1, HIGH);
  // delay(100);
  // Serial.println(LED_2);
  // digitalWrite(LED_2, HIGH);
  // delay(100);
  // Serial.println(LED_3);
  // digitalWrite(LED_3, HIGH);
  // delay(100);
  // Serial.println(LED_4);
  // digitalWrite(LED_4, HIGH);
  // delay(100);
  // Serial.println(LED_5);
  // digitalWrite(LED_5, HIGH);
  // delay(100);
  // digitalWrite(LED_0, LOW);
  // delay(100);
  // digitalWrite(LED_1, LOW);
  // delay(100);
  // digitalWrite(LED_2, LOW);
  // delay(100);
  // digitalWrite(LED_3, LOW);
  // delay(100);
  // digitalWrite(LED_4, LOW);
  // delay(100);
  // digitalWrite(LED_5, LOW);
  // delay(100);
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