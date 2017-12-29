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