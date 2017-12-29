#pragma once

class Unit {
    protected:
        int x, y, hp;
        char symbol;

    public:
        bool isPlant;
        Unit(int y, int x, int hp, char symbol, bool isPlant);
        void bindToScreen();
        void dropFromScreen();
        void takeDamage(int x);
        bool isHit(int x, int y);
        bool isAlive();
        virtual void live();
        virtual void die();
};