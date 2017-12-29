#pragma once
#include "Unit.h"

class Peanut: public Unit {
    public:
        static int maxHp;
        static int coolDownTime;
        static int currentCoolDown;
        static int lockTime;
        Peanut(int y, int x);
};