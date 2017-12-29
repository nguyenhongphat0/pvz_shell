#include "PeaShooter.h"
#include "Bullet.h"
#include "Global.h"
#include <ncurses.h>
using namespace std;

int PeaShooter::maxHp = 3;
int PeaShooter::rechargeTime = 60;
char PeaShooter::bulletSymbol = '-';
int PeaShooter::bulletDamage = 2;
int PeaShooter::bulletMoveTime = 1;
int PeaShooter::coolDownTime = 5;
int PeaShooter::currentCoolDown = 0;

PeaShooter::PeaShooter(int y, int x): Unit(y, x, PeaShooter::maxHp, 'p', PLANT) {
    shoted = 0;
    latency = STEP % rechargeTime;
    this->bindToScreen();
};

void PeaShooter::attack () {
    for (int i = 0; i < MAXAMOUNT; i++) {
        if (UNITS[i] != NULL && UNITS[i]->y == y && UNITS[i]->x > x && UNITS[i]->unitType == ZOMBIE && UNITS[i]->isAlive()) {
            bullets[shoted] = new Bullet(y, x, PeaShooter::bulletSymbol, PeaShooter::bulletDamage, PeaShooter::bulletMoveTime);
            shoted = (shoted + 1) % 100;
            return;
        }
    }
}

void PeaShooter::live() {
    if (STEP % rechargeTime == latency) attack();
    for (int i = 0; i < 100; i++) {
        if (bullets[i] != NULL && bullets[i]->isAlive()) bullets[i]->live();
    }
}