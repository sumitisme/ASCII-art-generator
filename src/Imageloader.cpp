#include "../include/constants.hpp"
#include "../include/Imageloader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

Imageloader::Imageloader(char* file) : filename(file) {
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);

    if(data == NULL) {
        std::cout << "Error loading the data\n";
    }

    std::cout << &data << "\n";
}

Imageloader::~Imageloader() {
    std::cout << "Imageloader instance destroyed\n";
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
