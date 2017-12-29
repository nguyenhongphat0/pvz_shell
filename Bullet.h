#pragma once
#include "Unit.h"

class Bullet: public Unit {
    public:
        int moveTime;
        int damage;
        Bullet(int y, int x, char symbol, int damage, int moveTime);
        void fly();
        void live();
        void die();
};