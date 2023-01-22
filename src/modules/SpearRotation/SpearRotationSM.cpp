#include "SpearRotationSM.h"

SpearRotationSM::SpearRotationSM()
{
    m_start = nullptr;
    m_curr = nullptr;
}

void SpearRotationSM::setStart(SpearRotationNode *n)
{
    m_start = n;
    if (m_curr == nullptr)
    {
        m_curr = n;
    }
}

SpearRotationNode *SpearRotationSM::stateTransition(int action)
{
    m_curr = m_curr->getNextNode(action);
    if (m_curr == nullptr)
    {
        m_curr = m_start;
    }
    return m_curr;
}

bool SpearRotationSM::isCompleted()
{
    return m_curr->isAccepting();
}