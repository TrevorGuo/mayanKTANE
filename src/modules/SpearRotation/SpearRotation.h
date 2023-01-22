#ifndef SPEARROTATION_H
#define SPEARROTATION_H
#include "Arduino.h"
#include <stdlib.h>

// #include "led.h"
#include "spear.h"
#include "accel.h"
#include <Servo.h>
#include "spear.h"

class SpearRotation
{
public:
    SpearRotation(Servo *spear);
    void begin();
    bool readInput(ORIENTATION top);
    void updateHardware();
    bool isComplete()
    {
        return m_step == 4;
    };

private:
    int m_game[5][2];
    int m_step = 0;
    int m_gameNum;
    void setGame0();
    void setGame1();
    void setGame2();

    Servo *m_spear;
};

#endif