#include "bomb.h"

Bomb::Bomb(ring* cal) {
    m_symbolSequenceModule = new SymbolSequence(this);
    m_cal = cal;
}

void Bomb::explode() {

}

void Bomb::win(){
    m_cal->updateQuadrant(NUM_MODULES - 1, true);
}

void Bomb::completeModule(int moduleNum) {
    m_completed[moduleNum] = true;
    m_cal->updateQuadrant(moduleNum, true);
    for (int i = 0; i < NUM_MODULES; i++) {
        if (!m_completed[i]) {
            return;
        }
    }
    win();
}