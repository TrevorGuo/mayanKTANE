#ifndef CALENDAR_H
#define CALENDAR_H

#include "ring.h"

class Calendar {
    public:
        Calendar();
        void completeModule(int module, bool done);

    private:
        ring m_r;
};

#endif