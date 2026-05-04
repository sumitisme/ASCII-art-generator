#pragma once

#include "constants.hpp"

class Background {
    private:
        char bgmap[SCREEN_WIDTH][SCREEN_HEIGHT];
        int x_coord, y_coord;
    
    public:
        Background(const Map&);
        ~Background();

        void setBackground(int, int, char);
        void printBackground();
};