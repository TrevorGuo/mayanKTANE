#ifndef SYMBOLSEQUENCESM_H
#define SYMBOLSEQUENCESM_H

#include "SymbolSequenceNode.h"
#include "Arduino.h"

#define SEQUENCE_LENGTH 4

class SymbolSequenceSM {
    public:
        SymbolSequenceSM();
        void setStart(SymbolSequenceNode* n);
        SymbolSequenceNode* stateTransition(int action);
        bool isCompleted();
    private:
        SymbolSequenceNode* m_start;
        SymbolSequenceNode* m_curr;
};

#endif //STATE_MACHINE_H