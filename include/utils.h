#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

//Constants
#define NUM_MODULES 3

//Pin Mappings
#define BUTTON_0 34
#define BUTTON_1 36
#define BUTTON_2 32
#define BUTTON_3 35
#define BUTTON_4 33
#define BUTTON_5 39

#define LED_0 25
#define LED_1 26
#define LED_2 14
#define LED_3 13
#define LED_4 12
#define LED_5 27

#define SOUND_RX 16
#define SOUND_TX 17
#define SOUND_RST 3

//Generates a random number between a and b
int randInt(int a, int b);

//Enumeration for
enum MODULES {DIAL, BUTTONS, SPEAR};

#endif