#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

// Maximum screensize
#define SCREEN_WIDTH 400 
#define SCREEN_HEIGHT 200 

// For the colors
inline const std::string RED = "\033[31m";
inline const std::string GREEN = "\033[32m";
inline const std::string YELLOW = "\033[33m";
inline const std::string BLUE = "\033[34m";
inline const std::string RESET = "\033[0m";

struct RGB {
    unsigned char r, g, b;
};

struct HSV {
    float h; 
    int s, v;
};

struct Map {
    int valueMap[SCREEN_HEIGHT][SCREEN_WIDTH];
    int hueMap[SCREEN_HEIGHT][SCREEN_WIDTH];

    int Xsize;
    int Ysize;
};

//  #define X_STRIDE  
//  #define Y_STRIDE 