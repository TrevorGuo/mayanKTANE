#include "SymbolSequence.h"

SymbolSequence::SymbolSequence(Bomb* b) {
    m_leds[0] = led(LED_0);
    m_leds[1] = led(LED_1);
    m_leds[2] = led(LED_2);
    m_leds[3] = led(LED_3);
    m_leds[4] = led(LED_4);
    m_leds[5] = led(LED_5);

    m_completed = 0;
    m_bomb = b;
}

bool SymbolSequence::readInput(int button_in) {
    //return m_fsm.isCompleted();
}

//SYMBOL NUMBERS ARE OFF BY ONE CUZ WE COUNT STARTING AT ZERO (0)

bool SymbolSequence::check(int button_in) {
    switch(m_currSymbol) {
        case 0:
            if (m_bomb->getStrike() == 1) {
                return m_currSymbol == button_in;
            }
            //more rules
        case 1:
            if (m_bomb->getSeason() == 0) {
                return m_prevSymbol == button_in;
            }
            if (m_prevSymbol >= 3) {
                return m_prevSymbol == button_in;
            }
        case 2:
            if (m_bomb->getSeason() == 1) {
                return 2 == button_in;
            }
            else {
                return 1 == button_in;
            }
        case 3:
            if (m_prevSymbol <= 2) {
                return m_prevSymbol == button_in;
            }
            if (m_pressed[1]) {
                return 2 == button_in;
            }
        case 4:
            if (m_bomb->getSeason() == 2) {
                return 4 == button_in;
            }
            else {
                return 0 == button_in;
            }
        case 5:
            if (m_bomb->getSeason() == 3) {
                return 5 == button_in;
            }
            if (m_bomb->getSeason() != m_startSeason) {
                return 3 == button_in;
            }
            else {
                return 2 == button_in;
            }
    }
}