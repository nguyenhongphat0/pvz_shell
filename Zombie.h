#pragma once
#include "Unit.h"
#include <future>

class Zombie: public Unit {
    public:
        static int maxHp;
        static int walkTime;
        Zombie(int y);
        void walk();
        void live();
};