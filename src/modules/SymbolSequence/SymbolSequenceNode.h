#ifndef SYMBOL_SEQUENCE_NODE_H
#define SYMBOL_SEQUENCE_NODE_H
#include "led.h"
#include "Arduino.h"
#include <unordered_map>

#define SEQUENCE_LENGTH 4

using namespace std;

class SymbolSequenceNode
{
public:
    SymbolSequenceNode(bool accepting, bool *p);
    void setPowerStates(bool *p);
    bool *getPowerStates();
    void addNextNode(int action, SymbolSequenceNode *n);
    SymbolSequenceNode *getNextNode(int action);
    bool isAccepting();

private:
    bool m_accepting;
    unordered_map<int, SymbolSequenceNode *> m_nextStates;
    bool m_power[SEQUENCE_LENGTH];
};

#endif