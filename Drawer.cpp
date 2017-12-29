#include "Drawer.h"
#include "Global.h"
#include <ncurses.h>
using namespace std;

void Drawer::drawStage(int w, int h, char ch) {
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    TOP = (max_y - h) / 2;
    LEFT = (max_x - w) / 2;
    for (int i = 0; i < max_y; i++) {
        for (int j = 0; j < max_x; j++) {
            if (!(i >= TOP && i < TOP + h && j >= LEFT && j < LEFT + w))
                mvaddch(i, j, ch);
        }
    }
    moveToCenter();
}

void Drawer::moveToCenter() {
    CURRENTX = LEFT + WIDTH / 2;
    CURRENTY = TOP + HEIGHT / 2;
    move(CURRENTY, CURRENTX);
}

void Drawer::drawRectangle(int top, int left, int height, int width, char ch) {
    for (int i = top; i < top + height; i++) {
        move(i, left);
        for (int i = left; i < left + width; i++) {
            addch(ch);
        }
    }
    move(CURRENTY, CURRENTX);
}

void Drawer::drawText(int y, int x, std::string text) {
    move(y, x);
    printw(text.c_str());
    move(CURRENTY, CURRENTX);
}

void Drawer::cleanUpChar(char ch) {
    for (int i = 0; i < TOP + HEIGHT; i++) {
        for (int j = 0; j < LEFT + WIDTH; j++) {
            if (mvinch(i, j) == ch) mvaddch(i, j, ' ');
        }
    }
    move(CURRENTY, CURRENTX);
}