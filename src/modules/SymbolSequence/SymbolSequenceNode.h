#ifndef SYMBOL_SEQUENCE_NODE_H
#define SYMBOL_SEQUENCE_NODE_H

#include "Node.h"
#include "led.h"
#include "Arduino.h"

#define SEQUENCE_LENGTH 4

class SymbolSequenceNode{
    public:
        SymbolSequenceNode(bool accepting, bool* p);
        void setPowerStates(bool* p);
        bool* getPowerStates();
        void addNextNode(int action, SymbolSequenceNode* n);
        SymbolSequenceNode* getNextNode(int action);
        bool isAccepting();
    private:
        bool m_accepting;
        unordered_map<int, SymbolSequenceNode*> m_nextStates;
        bool m_power[SEQUENCE_LENGTH];
};

#endif