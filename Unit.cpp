#include "Unit.h"
#include "Global.h"
#include <ncurses.h>

Unit::Unit(int y, int x, int hp, char symbol, bool isPlant) {
    this->y = TOP + y;
    this->x = LEFT + x;
    this->hp = hp;
    this->symbol = symbol;
    this->isPlant = isPlant;
    this->bindToScreen();
}

void Unit::takeDamage(int x) {
    hp -= x;
    if (!isAlive()) die();
}

bool Unit::isHit(int x, int y) {
    return this->x == x && this->y == y;
}

bool Unit::isAlive() {
    return hp > 0;
}

void Unit::live() {}

void Unit::die() {}

void Unit::bindToScreen() {
    mvaddch(y, x, symbol);
    move(CURRENTY, CURRENTX);
}

void Unit::dropFromScreen() {
    mvaddch(y, x, ' ');
    move(CURRENTY, CURRENTX);
}