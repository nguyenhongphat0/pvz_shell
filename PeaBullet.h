#pragma once
#include "Unit.h"

class PeaBullet: public Unit {
    public:
        static int moveTime;
        static int damage;
        PeaBullet(int y, int x);
        ~PeaBullet();
        void fly();
        void live();
        void die();
};