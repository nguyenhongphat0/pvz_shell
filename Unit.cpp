#include "Unit.h"
#include "Global.h"
#include <ncurses.h>

Unit::Unit(int x, int y, int hp, char symbol, bool isPlant) {
    this->x = x;
    this->y = y;
    this->hp = hp;
    this->symbol = symbol;
    this->isPlant = isPlant;
}

bool Unit::isAlive() {
    return hp > 0;
}

void Unit::live() {}

void Unit::bindToScreen() {
    mvaddch(y, x, symbol);
    move(CURRENTY, CURRENTX);
}

void Unit::dropFromScreen() {
    mvaddch(y, x, ' ');
    move(CURRENTY, CURRENTX);
}