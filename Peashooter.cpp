#include <iostream>
#include "PeaShooter.h"
#include <ncurses.h>
using namespace std;

int PeaShooter::maxHp = 3;

PeaShooter::PeaShooter(int x, int y): Unit(x, y, PeaShooter::maxHp, 'P', true) {};

void PeaShooter::attack () {
    cout << "++ PeaShooter attacking ";
}