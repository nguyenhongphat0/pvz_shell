#include "Zombie.h"
#include "Global.h"
#include "Drawer.h"
#include <future>
#include <chrono>
#include <ncurses.h>

using namespace std;

int Zombie::maxHp = 10;
int Zombie::walkTime = 1;

Zombie::Zombie(int y): Unit(y, WIDTH - 1, Zombie::maxHp, 'Z', true) {};

void Zombie::walk() {
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
            Drawer::moveToCenter();
            printw("  YOU LOSE");
            Drawer::moveToCenter();
            refresh();
        }
    }
}

void Zombie::die() {
    dropFromScreen();
    delete this;
}