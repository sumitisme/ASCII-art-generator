#pragma once

class Imageloader {
    private:
        char* filename;
        int width, height, channels;

    public:
        Imageloader(char* file);
        ~Imageloader();

        int imagewidth();
        int imageheight();
        int imagechannels();
};