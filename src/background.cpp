#include "..\include\background.hpp"

Background::Background(const Map& out){
    x_coord = out.Xsize;
    y_coord = out.Ysize;
    for(int j = 0; j < y_coord; j++) {
        for(int i = 0; i < x_coord; i++) {
            bgmap[j][i] = '.';
        }
    }
}

void Background::setBackground(int i, int j, char ch) {
    bgmap[j][i] = ch;
}

void Background::printBackground() {
    for(int j = 0; j < y_coord; j++) {
        for(int i = 0; i < x_coord; i++) {
            std::cout << bgmap[j][i];
        }
        std::cout << "\n";
    }
}

Background::~Background() {
    std::cout << "Background instance destroyed\n";
}