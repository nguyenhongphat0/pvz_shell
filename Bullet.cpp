#include "Bullet.h"
#include "Global.h"
#include "ncurses.h"

Bullet::Bullet(int y, int x, char symbol, int damage, int moveTime): Unit(y, x, 1, symbol, BULLET) {
    this->damage = damage;
    this->moveTime = moveTime;
}

void Bullet::fly() {
    if (mvinch(y, x) == symbol) mvaddch(y, x, ' ');
    if (mvinch(y, x + 1) == ' ') {
        mvaddch(y, x + 1, symbol);
        x++;
    } else {
        for (int i = 0; i < MAXAMOUNT; i++) {
            if (UNITS[i] != NULL && UNITS[i]->x == x + 1 && UNITS[i]->y == y && UNITS[i]->unitType == ZOMBIE) {
                UNITS[i]->takeDamage(damage);
                die();
            }
        }
        if (isAlive()) x++;
    }
    move(CURRENTY, CURRENTX);
}

void Bullet::live() {
    if (x < LEFT + WIDTH) {
        if (STEP % moveTime == 0) fly();
    } else {
        die();
    }
}

void Bullet::die() {
    dropFromScreen();
    hp = 0;
}