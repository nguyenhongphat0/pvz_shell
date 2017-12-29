#include "Unit.h"
#include "Global.h"
#include <ncurses.h>

Unit::Unit(int y, int x, int hp, char symbol, UnitType unitType) {
    this->y = y;
    this->x = x;
    this->hp = hp;
    this->symbol = symbol;
    this->unitType = unitType;
}

void Unit::takeDamage(int x) {
    hp -= x;
    if (!isAlive()) die();
}

bool Unit::isAlive() {
    return hp > 0;
}

void Unit::live() {}

void Unit::die() {
    dropFromScreen();
}

void Unit::bindToScreen() {
    mvaddch(y, x, symbol);
    move(CURRENTY, CURRENTX);
}

void Unit::dropFromScreen() {
    if (mvinch(y, x) == symbol) mvaddch(y, x, ' ');
    symbol = ' ';
    move(CURRENTY, CURRENTX);
}