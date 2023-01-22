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
void setup() {
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
}