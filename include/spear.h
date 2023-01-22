#ifndef SPEAR_H
#define SPEAR_H

#define SERVO_PIN 18
#define SERVO_POS_RIGHT 0
#define SERVO_POS_CENTER 90
#define SERVO_POS_LEFT 180

enum spearDirections
{
    RIGHT,
    CENTER,
    LEFT
};

#endif
// need to initialize the spear in init like this
// spear.attach(SERVO_PIN);

// to control the spear, example
// spear.write(SERVO_POS_RIGHT);