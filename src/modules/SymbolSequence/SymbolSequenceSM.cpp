#include "SymbolSequenceSM.h"

SymbolSequenceSM::SymbolSequenceSM() {
    m_start = nullptr;
    m_curr = nullptr;
}

void SymbolSequenceSM::setStart(SymbolSequenceNode* n) {
    m_start = n;
    if (m_curr == nullptr) {
        m_curr = n;
    }
}

SymbolSequenceNode* SymbolSequenceSM::stateTransition(int action) {
    m_curr = m_curr->getNextNode(action);
    if (m_curr == nullptr) {
        m_curr = m_start;
    }
    return m_curr;
}

bool SymbolSequenceSM::isCompleted() {
    return m_curr->isAccepting();
}