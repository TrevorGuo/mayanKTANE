#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "Node.h"

class StateMachine {
    public:
        StateMachine();
        bool readInput(int action); //Returns true if moved into an accepting state
    private:
        Node* m_start;
        Node* m_curr;
};

#endif //STATE_MACHINE_H