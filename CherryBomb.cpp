#include "CherryBomb.h"
#include "Global.h"
#include <cstddef>
#include <ncurses.h>

int CherryBomb::maxHp = 3;
int CherryBomb::coolDownTime = 2;
int CherryBomb::currentCoolDown = 0;
int CherryBomb::lockTime = 99;
int CherryBomb::explodeTime = 3;
int CherryBomb::widthRadius = 3;
int CherryBomb::heightRadius = 1;

CherryBomb::CherryBomb(int y, int x): Unit(y, x, CherryBomb::maxHp, '@', PLANT) {
    explodeAt = SECONDPASSED + explodeTime;
    bindToScreen();
};

void CherryBomb::explode() {
    for (int i = 0; i < MAXAMOUNT; i++) {
        if (UNITS[i] != NULL && UNITS[i]->isAlive() && UNITS[i]->unitType == ZOMBIE && UNITS[i]->x >= x - widthRadius && UNITS[i]->x <= x + widthRadius && UNITS[i]->y >= y - heightRadius && UNITS[i]->y <= y + heightRadius) {
            UNITS[i]->die();
        }
    }
    for (int i = y - heightRadius; i <= y + heightRadius; i++) {
        for (int j = x - widthRadius; j <= x + widthRadius; j++) {
            if (mvinch(i, j) == ' ')
                mvaddch(i, j, '~');
        }
    }
    move(CURRENTY, CURRENTX);
}

void CherryBomb::live() {
    if (SECONDPASSED == explodeAt) {
        explode();
        die();
    }
}