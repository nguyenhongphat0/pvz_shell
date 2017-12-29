#include "PeaBullet.h"
#include "Global.h"
#include "ncurses.h"

int PeaBullet::moveTime = 1;
int PeaBullet::damage = 1;

PeaBullet::PeaBullet(int y, int x): Unit(y - TOP, x - LEFT + 1, 1, '-', TRUE) {}

PeaBullet::~PeaBullet() {}

void PeaBullet::fly() {
    mvaddch(y, x, ' ');
    if (mvinch(y, x + 1) == ' ') {
        addch(symbol);
        x++;
    } else {
        for (int i = 0; i < AMOUNT; i++) {
            if (UNITS[i]->isHit(x, y) && !UNITS[i]->isPlant) {
                UNITS[i]->takeDamage(damage);
                die();
            } else {
                addch(symbol);
                x++;
            }
        }
    }
    move(CURRENTY, CURRENTX);
}

void PeaBullet::live() {
    if (x < LEFT + WIDTH) {
        if (STEP % moveTime == 0) fly();
    } else {
        delete this;
    }
}

void PeaBullet::die() {
    dropFromScreen();
    delete this;
}