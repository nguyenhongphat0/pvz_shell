#include "PeaShooter.h"
#include "PeaBullet.h"
#include "Global.h"
#include <ncurses.h>
using namespace std;

int PeaShooter::maxHp = 3;
int PeaShooter::rechargeTime = 5;

PeaShooter::PeaShooter(int y, int x): Unit(y, x, PeaShooter::maxHp, 'P', true) {
    shoted = 0;
};

void PeaShooter::attack () {
    bullets[shoted] = new PeaBullet(y, x);
    shoted = (shoted + 1) % 100;
}

void PeaShooter::live() {
    if (STEP % rechargeTime == 0) attack();
    for (int i = 0; i < 100; i++) {
        if (bullets[i] != NULL) bullets[i]->live();
    }
}