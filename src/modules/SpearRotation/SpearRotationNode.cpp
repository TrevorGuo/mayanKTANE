#include "SpearRotationNode.h"

SpearRotationNode::SpearRotationNode(bool accepting, int p)
{
    m_accepting = accepting;
    setSPos(p);
    m_spos = p;
}

void SpearRotationNode::setSPos(int p)
{
    m_spos = p;
}

int SpearRotationNode::getSPos()
{
    return m_spos;
}

void SpearRotationNode::addNextNode(int action, SpearRotationNode *n)
{
    m_nextStates[action] = n;
}

SpearRotationNode *SpearRotationNode::getNextNode(int action)
{
    if (m_nextStates.find(action) == m_nextStates.end())
    {
        return nullptr;
    }
    return m_nextStates[action];
}

bool SpearRotationNode::isAccepting()
{
    return m_accepting;
}