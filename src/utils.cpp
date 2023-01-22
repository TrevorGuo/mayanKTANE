#include "utils.h"
#include <Arduino.h>

int randInt(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}