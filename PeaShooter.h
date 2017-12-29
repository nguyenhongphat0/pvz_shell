#pragma once
#include "Unit.h"

class PeaShooter: public Unit {
    protected:
        int ad, spd;

    public:
        static int maxHp;
        PeaShooter(int x, int y);
        void attack();
};