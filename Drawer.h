#pragma once
#include <string>

class Drawer {
    public:
        static void drawStage(int w, int h, char ch);
        static void moveToCenter();
        static void drawRectangle(int top, int left, int height, int width, char ch);
        static void drawText(int y, int x, std::string text);
        static void cleanUpChar(char ch);
};