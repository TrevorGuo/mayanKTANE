#include "Node.h"

Node::Node(bool accepting) {
    m_accepting = accepting;
}

void Node::addNextNode(int action, Node* n) {
    m_nextStates[action] = n;
}

Node* Node::getNextNode(int action) {
    return m_nextStates[action];
}

bool Node::isAccepting() {
    return m_accepting;
}