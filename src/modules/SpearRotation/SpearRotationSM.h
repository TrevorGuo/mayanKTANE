#ifndef SPEARROTATIONSM_H
#define SPEARROTATIONSM_H

#include "SpearRotationNode.h"
// #include "Arduino.h"

// #define SEQUENCE_LENGTH 4

class SpearRotationSM
{
public:
    SpearRotationSM();
    void setStart(SpearRotationNode *n);
    SpearRotationNode *stateTransition(int action);
    bool isCompleted();
    SpearRotationNode *getCurr()
    {
        return m_curr;
    };

private:
    SpearRotationNode *m_start;
    SpearRotationNode *m_curr;
};

#endif // STATE_MACHINE_H