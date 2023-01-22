#ifndef BOMB_H
#define BOMB_H

#include "utils.h"
#include "./modules/SymbolSequence.h"

class SymbolSequence;

class Bomb {
    public:
        Bomb();

        int getStrike() {return m_strikes;};
        int getSeason() {return m_season;};

        void strike() {m_strikes++; if (m_strikes == 3) explode();};
        //void complete() {m_modulesCompleted++; if (m_modulesCompleted == 3) win();};

    private:
        //Helper Functions
        void explode();
        void win();

        //Member Variables
        int m_strikes;
        bool m_completed[NUM_MODULES];
        int m_season;
        int m_timeRemaining; //in milliseconds

        //Modules
        SymbolSequence* m_symbolSequenceModule;


        //Dom's classes
        //Timer class - Dom

        //Sound class - Dom

        //LED class - Dom

        //Button class - Dom

        //Accelerometer class - Dom

        //Spear class - Dom

        //Dial class - Dom

        //Serial class - Dom
};

#endif