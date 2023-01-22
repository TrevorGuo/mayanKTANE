#include "SymbolSequenceNode.h"

SymbolSequenceNode::SymbolSequenceNode(bool accepting, bool* p)
{
    setPowerStates(p);
}

void SymbolSequenceNode::setPowerStates(bool* p) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        m_power[i] = p[i];
    }
}

bool* SymbolSequenceNode::getPowerStates() {
    return m_power;
}

void SymbolSequenceNode::addNextNode(int action, SymbolSequenceNode* n) {
    m_nextStates[action] = n;
}

SymbolSequenceNode* SymbolSequenceNode::getNextNode(int action) {
    if (m_nextStates.find(action) == m_nextStates.end()) {
        return nullptr;
    }
    return m_nextStates[action];
}

bool SymbolSequenceNode::isAccepting() {
    return m_accepting;
}