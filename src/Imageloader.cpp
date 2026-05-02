#include "../include/constants.hpp"
#include "../include/Imageloader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

Imageloader::Imageloader(char* file) : filename(file) {
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);

    if(data == NULL) {
        std::cout << "Error loading the data\n";
    }

    int pixelOffset;

    for(int j = 0; j < width; j++) {
        for(int i = 0; i < height; i++) {
            pixelOffset = (j * width + i) * channels;
            p[i][j].r = data[pixelOffset];
            p[i][j].g = data[pixelOffset + 1];
            p[i][j].b = data[pixelOffset + 2];
        }
    }
}

Imageloader::~Imageloader() {
    std::cout << "Imageloader instance destroyed\n";
}

// I have made "Pixel" a global struct since normally, it's causing namespacing issues and whatnot.
Pixel Imageloader::imagepixelinfo(int a, int b) {
    return p[a][b];
}

int Imageloader::imagewidth() {
    return width;
}

int Imageloader::imageheight() {
    return height;
}

int Imageloader::imagechannels() {
    return channels;
}
