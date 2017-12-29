#include <iostream>
#include "Unit.h"
#include "PeaShooter.h"
#include "Zombie.h"
#include "Drawer.h"
#include "Global.h"
#include <unistd.h>
#include <ncurses.h>

int CURRENTX = 0, CURRENTY = 0, WIDTH = 80, HEIGHT = 5, TOP = 0, LEFT = 0, STEP = 0;
Unit* units[1000];

using namespace std;

void start() {
    Drawer::drawStage(WIDTH, HEIGHT, '@');
    units[0] = new Zombie(2);
}

void animate() {
    units[0]->live();
}

void keyHandling(int ch) {
    ch = getch();
    if (ch == ERR) return;
    switch (ch) {
        case KEY_UP:
            CURRENTY = CURRENTY > TOP ? CURRENTY - 1 : CURRENTY;
            break;
        case KEY_DOWN:
            CURRENTY = CURRENTY < TOP + HEIGHT - 1 ? CURRENTY + 1 : CURRENTY;
            break;
        case KEY_LEFT:
            CURRENTX = CURRENTX > LEFT ? CURRENTX - 1 : CURRENTX;
            break;
        case KEY_RIGHT:
            CURRENTX = CURRENTX < LEFT + WIDTH - 1 ? CURRENTX + 1 : CURRENTX;
            break;
    }
    move(CURRENTY, CURRENTX);
    refresh();
}

void run() {
    int ch;
    while (1) {
        STEP = (STEP + 1) % 1000;
        animate();
        keyHandling(ch);
        usleep(50000);
    }
}

int main() {
	initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    start();
    run();
	endwin();
	return 0;
}
