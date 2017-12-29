#pragma once
#include "Unit.h"
#include <future>

class Zombie: public Unit {
    public:
        static int maxHp;
        static int walkTime;
        static int damage;
        Zombie(int y);
        void walk();
        void live();
        void die();
};