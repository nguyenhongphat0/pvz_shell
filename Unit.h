#pragma once

enum UnitType {PLANT, ZOMBIE, BULLET};

class Unit {
    public:
        int x, y, hp;
        char symbol;
        UnitType unitType;
        Unit(int y, int x, int hp, char symbol, UnitType unitType);
        void bindToScreen();
        void dropFromScreen();
        void takeDamage(int x);
        bool isAlive();
        virtual void live();
        virtual void die();
};