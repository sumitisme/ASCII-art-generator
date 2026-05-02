#pragma once

#include "constants.hpp"

class Background {
    private:
        char map[SCREEN_WIDTH][SCREEN_HEIGHT];
        int x_coord, y_coord;
    
    public:
        Background(int, int);
        ~Background();

        void printbackground();
};