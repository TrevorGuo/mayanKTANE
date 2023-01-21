#include "StateMachine.h"

StateMachine::StateMachine() {
    m_start = new Node(false);
    m_curr = m_start;
}

bool StateMachine::readInput(int action) {
    m_curr = m_nextStates[action];
    return m_curr->isAccepting();
}