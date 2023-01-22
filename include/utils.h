#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

//Constants
#define NUM_MODULES 3
#define DEBOUNCER_TIME 100

//Pin Mappings
#define BUTTON_0 4  //Brown D4
#define BUTTON_1 33 //Orange D33
#define BUTTON_2 5 // Grey D5
#define BUTTON_3 16 // Black 
#define BUTTON_4 17 // White D18
#define BUTTON_5 32 //Red D32
#define LED_0 25
#define LED_1 26
#define LED_2 14
#define LED_3 13
#define LED_4 12
#define LED_5 27

#define ACC_SCL 22
#define ACC_SDA 21

#define SERVO 23
#define SERVO_BUTTON 1

#define NEOPIXEL_PIN 18

// #define BUTTON_0 27
// #define BUTTON_1 12
// #define BUTTON_2 13
// #define BUTTON_3 14
// #define BUTTON_4 26
// #define BUTTON_5 25

// #define LED_0 39
// #define LED_1 33
// #define LED_2 35
// #define LED_3 32
// #define LED_4 36
// #define LED_5 34



//Generates a random number between a and b
int randInt(int a, int b);


#endif