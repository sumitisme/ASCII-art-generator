#pragma once

class Imageloader {
    private:
        char* filename;
        int width, height, channels;
        Pixel p[SCREEN_WIDTH][SCREEN_HEIGHT];
        unsigned char* data;

    public:
        Imageloader(char*);
        ~Imageloader();

//      Pixel imagepixelinfo(int, int);

        int imagepixelred(int, int);
        int imagepixelgreen(int, int);
        int imagepixelblue(int, int);

        int imagewidth();
        int imageheight();
        int imagechannels();
};