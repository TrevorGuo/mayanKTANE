#ifndef SPEAR_ROTATION_NODE_H
#define SPEAR_ROTATION_NODE_H
#include "led.h"
#include "Arduino.h"
#include "accel.h"
#include <unordered_map>

using namespace std;

class SpearRotationNode
{
public:
    SpearRotationNode(bool accepting, int pget);
    void setSPos(int p);
    int getSPos();
    void addNextNode(int action, SpearRotationNode *n);
    SpearRotationNode *getNextNode(int action);
    bool isAccepting();
    bool readInput(ORIENTATION top);

private:
    bool m_accepting;
    unordered_map<int, SpearRotationNode *> m_nextStates;

    int m_spos;
};

#endif