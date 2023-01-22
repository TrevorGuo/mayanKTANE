#include "bomb.h"

Bomb::Bomb(sound* s) {
    m_symbolSequenceModule = new SymbolSequence(this);
    m_sound = s;
}

void Bomb::explode() {
    m_sound->playEnd(false);
}

void Bomb::win(){
    m_sound->playEnd(true);
}