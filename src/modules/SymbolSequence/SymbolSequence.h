#ifndef SYMBOL_SEQUENCE_H
#define SYMBOL_SEQUENCE_H

#include "SymbolSequenceNode.h"
#include "SymbolSequenceSM.h"
#include "led.h"

enum ACTIONS {ONE, TWO, THREE};

class SymbolSequence{
    public:
        SymbolSequence();
        void begin();
        bool readInput(int action);
        void updateHardware(SymbolSequenceNode* curr);
    private:
        void constructGame(SymbolSequenceNode* start);

        SymbolSequenceSM m_fsm;

        led m_leds[SEQUENCE_LENGTH];

        bool p1[SEQUENCE_LENGTH] = {1, 0};
        bool p2[SEQUENCE_LENGTH] = {0, 1};
        bool p3[SEQUENCE_LENGTH] = {1, 1};
};

#endif