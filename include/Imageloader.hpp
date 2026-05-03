#pragma once

#include "constants.hpp"

class Imageloader {
    private:
        char* filename;
        int width, height, channels;
//      Pixel p[SCREEN_WIDTH][SCREEN_HEIGHT];
        unsigned char* data;
        int XFactor;
        int YFactor;

        Map image;

        HSV AveragingFunction(int, int, int, int); // Private on purpose
        HSV RGBtoHSV(RGB in); // Private on purpose

    public:
        Imageloader(char*);
        ~Imageloader();

//      Pixel imagepixelinfo(int, int);

        int imagePixelRed(int, int);
        int imagePixelGreen(int, int);
        int imagePixelBlue(int, int);

        Map imageDropRes(int, int);

        int imageWidth();
        int imageHeight();
        int imageChannels();
};