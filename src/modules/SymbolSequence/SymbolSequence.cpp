#include "SymbolSequence.h"
#include "SymbolSequenceNode.h"

SymbolSequence::SymbolSequence() {
    m_leds[0] = led(LED_0);
    m_leds[1] = led(LED_1);
    m_leds[2] = led(LED_2);
    m_leds[3] = led(LED_3);
}

void SymbolSequence::begin() {
    SymbolSequenceNode* start = new SymbolSequenceNode(false, p1);
    m_fsm.setStart(start);
    constructGame(start);
    updateHardware(start);
}

bool SymbolSequence::readInput(int action) {
    updateHardware(m_fsm.stateTransition(action));
    return m_fsm.isCompleted();
}

void SymbolSequence::updateHardware(SymbolSequenceNode* curr) {
    Serial.println("UPDATING");
    bool* powerStates = curr->getPowerStates();
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        powerStates[i] ? Serial.println("ON") : Serial.println("OFF");
        powerStates[i] ? m_leds[i].on() : m_leds[i].off();
    }
}

void SymbolSequence::constructGame(SymbolSequenceNode* start) {
    SymbolSequenceNode* s1 = new SymbolSequenceNode(false, p2);
    SymbolSequenceNode* s2 = new SymbolSequenceNode(true, p3);
    start->addNextNode(ONE, s1);
    start->addNextNode(TWO, s2);
    s1->addNextNode(ONE, start);
    s1->addNextNode(TWO, s1);
    s1->addNextNode(THREE, s2);
}