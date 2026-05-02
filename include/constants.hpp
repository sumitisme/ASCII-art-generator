#ifndef _CONSTANTS_
#define _CONSTANTS_

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <string>

// Maximum screensize
#define SCREEN_WIDTH 400 
#define SCREEN_HEIGHT 200 

// For the colors
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";

#define STRIDE 

struct Pixel {
    unsigned char r, g, b;
};

//  #define X_STRIDE  
//  #define Y_STRIDE 

#endif