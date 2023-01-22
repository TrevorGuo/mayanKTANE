#include "SymbolSequence.h"

SymbolSequence::SymbolSequence(Bomb* b) {
    m_leds[0] = led(LED_0);
    m_leds[1] = led(LED_1);
    m_leds[2] = led(LED_2);
    m_leds[3] = led(LED_3);
    m_leds[4] = led(LED_4);
    m_leds[5] = led(LED_5);

    m_bomb = b;
    m_currSymbol = 0;
    reset();
}

void SymbolSequence::readInput(int button_in) {
    if (!check(button_in)) {
        Serial.println("WRONG");
        reset();
        return;
    }
    Serial.println("RIGHT");
    Serial.println(button_in);

    m_leds[m_currSymbol].off();
    m_completed++;
    if (m_completed == 1) {
        for (int i = 0; i < NUM_SYMBOLS; i++) {
            m_leds[i].on();
        }
        m_bomb->completeModule(0);
        return;
    }
    m_prevSymbol = m_currSymbol;
    m_pressed[m_currSymbol] = true;
    m_currSymbol = randInt(0, NUM_SYMBOLS - 1);
    m_leds[m_currSymbol].on();
    if (m_startSeason == -1) {
        m_startSeason = m_bomb->getSeason();
    }

}

//SYMBOL NUMBERS ARE OFF BY ONE CUZ WE COUNT STARTING AT ZERO (0)

bool SymbolSequence::check(int button_in) {
    switch(m_currSymbol) {
        case 0:
            if (m_bomb->getStrike() == 1) {
                return m_currSymbol == button_in;
            }
            else {
                return m_currSymbol == button_in;
            }
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
            if (m_prevSymbol != -1 && m_prevSymbol <= 2) {
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
            if (m_startSeason != -1 && m_bomb->getSeason() != m_startSeason) {
                return 3 == button_in;
            }
            else {
                return 2 == button_in;
            }
    }
}

void SymbolSequence::reset() {
    m_leds[m_currSymbol].off();
    m_currSymbol = randInt(0, NUM_SYMBOLS - 1);
    m_completed = 0;
    m_leds[m_currSymbol].on();
    m_prevSymbol = -1;
    // for (int i = 0; i < NUM_SYMBOLS; i++) {
    //     m_pressed[i] = false;
    // }
    m_startSeason = -1;
}