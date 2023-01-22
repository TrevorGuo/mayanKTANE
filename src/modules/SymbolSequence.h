#ifndef SYMBOL_SEQUENCE_H
#define SYMBOL_SEQUENCE_H

#include "led.h"
#include "../bomb.h"
#include "utils.h"
#include <Arduino.h>

#define NUM_SYMBOLS 6

class Bomb;

class SymbolSequence{
    public:
        SymbolSequence(Bomb* b);

        void readInput(int button_in);
        bool check(int button_in);
        void reset();

    private:
        Bomb* m_bomb;

        //States to keep track of
        int m_completed;
        int m_currSymbol;
        int m_prevSymbol;
        bool m_pressed[NUM_SYMBOLS];
        int m_startSeason;

        //Hardware
        led m_leds[NUM_SYMBOLS];
        //Array of buttons - interrupts attach to each - the interrupt will call 'readInput'
};

#endif