#ifndef NODE_H
#define NODE_H

#include <unordered_map>

using namespace std;

class Node {
    public:
        Node(bool accepting);
        void addNextNode(int action, Node* n);
        Node* getNextNode(int action);
        virtual void updateHardware();
        bool isAccepting();
    private:
        bool m_accepting;
        unordered_map<int, Node*> m_nextStates;
};

//inherited classes will have hardware states saved in them

#endif