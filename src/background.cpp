#include "..\include\background.hpp"

Background::Background(Map out){
    x_coord = out.Xsize;
    y_coord = out.Ysize;
    for(int j = 0; j < y_coord; j++) {
        for(int i = 0; i < x_coord; i++) {
            bgmap[i][j] = '.';
        }
    }
}

void Background::setBackground(int i, int j, char ch) {
    bgmap[i][j] = ch;
}

void Background::printBackground() {
    for(int j = 0; j < y_coord; j++) {
        for(int i = 0; i < x_coord; i++) {
            std::cout << bgmap[i][j];
        }
        std::cout << "\n";
    }
}

Background::~Background() {
    std::cout << "Background instance destroyed\n";
}