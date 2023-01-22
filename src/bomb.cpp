#include "bomb.h"

Bomb::Bomb() {
    Serial.println("Constructing b");

    m_symbolSequenceModule = new SymbolSequence(this);
}

void Bomb::explode() {

}

void Bomb::win(){
}

void Bomb::completeModule(int moduleNum) {
    m_completed[moduleNum] = true;
    for (int i = 0; i < NUM_MODULES; i++) {
        if (!m_completed[i]) {
            return;
        }
    }
    win();
}