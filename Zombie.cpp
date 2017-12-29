#include "Zombie.h"
#include "Global.h"
#include "Drawer.h"
#include <future>
#include <chrono>
#include <ncurses.h>

using namespace std;

int Zombie::maxHp = 10;
int Zombie::walkTime = 10;
int Zombie::damage = 1;

Zombie::Zombie(int y): Unit(TOP + y, LEFT + WIDTH - 1, Zombie::maxHp, 'Z', ZOMBIE) {
    this->bindToScreen();
};

void Zombie::walk() {
    for (int i = 0; i < MAXAMOUNT; i++) {
        if (UNITS[i] != NULL && UNITS[i]->isAlive() && UNITS[i]->y == y && UNITS[i]->x == x - 1) {
            if (UNITS[i]->unitType == PLANT) {
                UNITS[i]->takeDamage(damage);
                return; 
            }
            if (UNITS[i]->unitType == BULLET) {
                return;
            }
        }
    }
    x--;
    mvaddch(y, x, symbol);
    addch(' ');
    move(CURRENTY, CURRENTX);
}

void Zombie::live() {
    if (isAlive()) {
        if (x > LEFT) {
            if (STEP % walkTime == 0) walk();
        } else {
            if (ISLOSED) return;
            ISLOSED = true;
            Drawer::moveToCenter();
            printw("  YOU LOSE");
            Drawer::moveToCenter();
            refresh();
            die();
        }
    }
}