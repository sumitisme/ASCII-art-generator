#include "..\include\constants.hpp"
#include "..\include\background.hpp"

Background::Background(int a, int b) : x_coord(a), y_coord(b){
    for(int j = 0; j < y_coord; j++) {
        for(int i = 0; i < x_coord; i++) {
            map[i][j] = '#';
        }
    }
}

void Background::printBackground() {
    for(int j = 0; j < y_coord; j++) {
        for(int i = 0; i < x_coord; i++) {
            std::cout << map[i][j];
        }
        std::cout << "\n";
    }
}

Background::~Background() {
    std::cout << "Background instance destroyed\n";
}