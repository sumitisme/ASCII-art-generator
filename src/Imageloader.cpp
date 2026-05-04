#include "../include/Imageloader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

// a, i -> x
// b, j -> y

HSV Imageloader::RGBtoHSV(RGB in) {
    HSV out;
    int vmax, vmin;
    vmax = std::max(in.r, std::max(in.g, in.b));
    vmin = std::min(in.r, std::min(in.g, in.b));

    // V
    out.v = vmax;

    // S
    if(out.v == 0) {
        out.s = 0;
    }
    else {
        out.s = vmax - vmin;
    }

    // H
    if((vmax - vmin) == 0) {
        out.h = 0;
    }
    else if(vmax == in.r) {
        out.h = 60 * (fmod(((float)(in.g - in.b) / (float)(vmax - vmin)), 6));
    }
    else if(vmax == in.g) {
        out.h = 60 * (((float)(in.b - in.r) / (float)(vmax - vmin)) + 2);
    }
    else if(vmax == in.b) {
        out.h = 60 * (((float)(in.r - in.g) / (float)(vmax - vmin)) + 4);
    }

    if (out.h < 0) out.h += 360;

    return out;
}

HSV Imageloader::AveragingFunction(int a, int b, int XFactor, int YFactor) {
    RGB in;
    HSV converted;
    HSV avg;

    avg = {.h = 0, .s = 0, .v = 0};

    for(int j = b; j < b + YFactor; j++) {
        for(int i = a; i < a + XFactor; i++) {
            in.r = imagePixelRed(i, j);
            in.g = imagePixelGreen(i, j);
            in.b = imagePixelBlue(i, j);

            converted = RGBtoHSV(in);

            avg.h += converted.h;
            avg.s += converted.s;
            avg.v += converted.v;
        }
    }

    avg.h /= (XFactor * YFactor);
    avg.s /= (XFactor * YFactor);
    avg.v /= (XFactor * YFactor);

    return avg;
}

Imageloader::Imageloader(char* file) : filename(file) {
    data = stbi_load(filename, &width, &height, &channels, 0);

    if(data == NULL) {
        std::cout << "Error loading the data\n";
        exit(1);
    }


// This isn't working. Gave up on this. I can't even tell why tf it isn't working.

//  int pixelOffset;

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
// This shit didn't work at all.
// Huh

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

Map Imageloader::imageDropRes(int a, int b) { // Input will be the final screen_width and screen_height
    HSV averaged;

    XFactor = width / a;
    YFactor = height / b; // Since in terminal, the words have the width to height ratio of 1:2

    image.Xsize = a;
    image.Ysize = b;

    // Averaging the pixel colors to reduce the res
    for(int j = 0; j < image.Ysize; j++) {
        for(int i = 0; i < image.Xsize; i++) {
            int startX = i * XFactor;
            int startY = j * YFactor;

            if(startX < width && startY < height) {
                int clampedX = std::min(XFactor, width - startX);
                int clampedY = std::min(YFactor, width - startY);
                averaged = AveragingFunction(startX, startY, XFactor, YFactor);
                image.hueMap[j][i]      = averaged.h;
                image.valueMap[j][i]    = averaged.v;
            }
        }
    }

    return image;
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
