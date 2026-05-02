#pragma once

class Imageloader {
    private:
        char* filename;
        int width, height, channels;
        Pixel p[SCREEN_WIDTH][SCREEN_HEIGHT];

    public:
        Imageloader(char* file);
        ~Imageloader();

        Pixel imagepixelinfo(int a, int b);

        int imagewidth();
        int imageheight();
        int imagechannels();
};