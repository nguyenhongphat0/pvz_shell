#pragma once
#include "Unit.h"

class PeaBullet: public Unit {
    public:
        PeaBullet(PeaShooter);
        void move();
        void alive();
}