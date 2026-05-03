#pragma once

class Imageloader {
    private:
        char* filename;
        int width, height, channels;
//      Pixel p[SCREEN_WIDTH][SCREEN_HEIGHT];
        unsigned char* data;

    public:
        Imageloader(char*);
        ~Imageloader();

//      Pixel imagepixelinfo(int, int);

        int imagePixelRed(int, int);
        int imagePixelGreen(int, int);
        int imagePixelBlue(int, int);

        int imageDropRes(int, int);

        int imageWidth();
        int imageHeight();
        int imageChannels();
};