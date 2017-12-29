#pragma once
#include "Unit.h"
#include "Bullet.h"

class PeaShooter: public Unit {
    protected:
        Bullet* bullets[100];
        int shoted, latency;

    public:
        static int maxHp;
        static int rechargeTime;
        static char bulletSymbol;
        static int bulletMoveTime;
        static int bulletDamage;
        static int coolDownTime;
        static int currentCoolDown;
        PeaShooter(int y, int x);
        void attack();
        void live();
};