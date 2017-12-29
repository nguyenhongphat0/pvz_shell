#include <iostream>
#include <string>
#include "Unit.h"
#include "PeaShooter.h"
#include "Zombie.h"
#include "Drawer.h"
#include "Global.h"
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

using namespace std;

int CURRENTX = 0, CURRENTY = 0, WIDTH = 80, HEIGHT = 5, TOP = 0, LEFT = 0, CYCLE = 50000, STEP = 0, AMOUNT = 0, MAXAMOUNT = 1000, ZOMBIECYCLE = 100, SECONDPASSED = 0;
bool ISLOSED = false;
Unit* UNITS[1000];

int unitIndex() {
    if (UNITS[AMOUNT] != NULL) UNITS[AMOUNT]->hp = 0;
    AMOUNT = (AMOUNT + 1) % MAXAMOUNT;
    return AMOUNT - 1;
}

int randomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void init() {
    srand(time(NULL));
    Drawer::drawStage(WIDTH, HEIGHT, '@');
}

void animate() {
    for (int i = 0; i < MAXAMOUNT; i++) {
        if (UNITS[i] != NULL && UNITS[i]->isAlive()) UNITS[i]->live();
    }
}

void drawThings() {
    if (ISLOSED) return;
    if (STEP % (1000000 / CYCLE) == 0) {
        Drawer::drawText(1, 4, " Your score: " + to_string(SECONDPASSED) + " ");
        Drawer::drawText(3, 7, " p -> " + to_string(PeaShooter::currentCoolDown) + " ");
        SECONDPASSED++;
        if (ZOMBIECYCLE > 1) ZOMBIECYCLE--;
        if (PeaShooter::currentCoolDown > 0) PeaShooter::currentCoolDown--;
    }
}

void makingZombie() {
    if (STEP % ZOMBIECYCLE == 0) {
        UNITS[unitIndex()] = new Zombie(randomNumber(0, HEIGHT - 1));
    }
}

void keyHandling(int ch) {
    ch = getch();
    if (ISLOSED || ch == ERR) return;
    switch (ch) {
        // Arrow key
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
        // End of arrow key
        case 'p':
            if (mvinch(CURRENTY, CURRENTX) == ' ' && PeaShooter::currentCoolDown == 0) {
                UNITS[unitIndex()] = new PeaShooter(CURRENTY, CURRENTX);
                PeaShooter::currentCoolDown = PeaShooter::coolDownTime;
            }

    }
    move(CURRENTY, CURRENTX);
    refresh();
}

void run() {
    int ch;
    while (1) {
        keyHandling(ch);
        makingZombie();
        drawThings();
        animate();
        STEP = (STEP + 1) % 1000;
        usleep(CYCLE);
    }
}

int main() {
	initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    init();
    run();
	endwin();
	return 0;
}
