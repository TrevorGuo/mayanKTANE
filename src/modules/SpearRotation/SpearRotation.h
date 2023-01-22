#ifndef SPEARROTATION_H
#define SPEARROTATION_H
#include "Arduino.h"

#include "SpearRotationNode.h"
#include "SpearRotationSM.h"
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
    bool readInput(int action);
    void updateHardware(SpearRotationNode *curr);
    bool readInput(ORIENTATION top);

private:
    void constructGame(SpearRotationNode *start);
    SpearRotationSM m_fsm;
    int m_gameNum;
    void setGame0(SpearRotationNode *start);
    void setGame1(SpearRotationNode *start);
    void setGame2(SpearRotationNode *start);
    Servo *m_spear;
};

#endif