#include "../include/constants.hpp"
#include "../include/Imageloader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

Imageloader::Imageloader(char* file) : filename(file) {
    data = stbi_load(filename, &width, &height, &channels, 0);

    if(data == NULL) {
        std::cout << "Error loading the data\n";
    }

    int pixelOffset;

// This isn't working

//  for(int j = 0; j < height; j++) {
//      for(int i = 0; i < width; i++) {
//          pixelOffset = (i * channels) + (j * width * channels);
//          p[i][j].r = data[pixelOffset];
//          p[i][j].g = data[pixelOffset + 1];
//          p[i][j].b = data[pixelOffset + 2];
//      }
//  }
}

Imageloader::~Imageloader() {
    std::cout << "Imageloader instance destroyed\n";
}

// I have made "Pixel" a global struct since normally, it's causing namespacing issues and whatnot.
//  Pixel Imageloader::imagepixelinfo(int a, int b) {
//      return p[a][b];
//  }

int Imageloader::imagePixelRed(int a, int b) {
    int re = data[a * channels + b * width * channels];
    return re;
}

int Imageloader::imagePixelGreen(int a, int b) {
    int gr = data[a * channels + b * width * channels + 1];
    return gr;
}

int Imageloader::imagePixelBlue(int a, int b) {
    int bl = data[a * channels + b * width * channels + 2];
    return bl;
}

int Imageloader::imageWidth() {
    return width;
}

int Imageloader::imageHeight() {
    return height;
}

int Imageloader::imageChannels() {
    return channels;
}
