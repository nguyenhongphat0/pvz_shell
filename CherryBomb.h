#pragma once
#include "Unit.h"

class CherryBomb: public Unit {
    protected:
        int explodeAt;

    public:
        static int maxHp;
        static int widthRadius;
        static int heightRadius;
        static int coolDownTime;
        static int currentCoolDown;
        static int lockTime;
        static int explodeTime;
        CherryBomb(int y, int x);
        void live();
        void explode();
};