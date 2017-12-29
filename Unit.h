#pragma once

class Unit {
    protected:
        int x, y, hp;
        char symbol;
        bool isPlant;

    public:
        Unit(int x, int y, int hp, char symbol, bool isPlant);
        bool isAlive();
        virtual void live();
        virtual void bindToScreen();
        virtual void dropFromScreen();
};