#pragma once
#include "Unit.h"
#include "PeaBullet.h"

class PeaShooter: public Unit {
    protected:
        PeaBullet* bullets[100];
        int shoted;

    public:
        static int maxHp;
        static int rechargeTime;
        PeaShooter(int x, int y);
        void attack();
        void live();
};