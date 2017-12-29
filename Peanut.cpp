#include "Peanut.h"

int Peanut::maxHp = 50;
int Peanut::coolDownTime = 12;
int Peanut::currentCoolDown = 0;
int Peanut::lockTime = 20;

Peanut::Peanut(int y, int x): Unit(y, x, Peanut::maxHp, 'O', PLANT) {
    bindToScreen();
};