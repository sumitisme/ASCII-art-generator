#include "../include/Imageloader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

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
        out.h = 60 * (fmod((in.g - in.b) / (vmax - vmin), 6));
    }
    else if(vmax == in.g) {
        out.h = 60 * ((in.b - in.r) / (vmax - vmin) + 2);
    }
    else if(vmax == in.b) {
        out.h = 60 * ((in.r - in.g) / (vmax - vmin) + 4);
    }

    if (out.h < 0) out.h += 360;

    return out;
}

HSV Imageloader::AveragingFunction(int a, int b, int XFactor, int YFactor) {
    RGB in;
    HSV converted;
    HSV avg;

    avg = {.h = 0, .s = 0, .v = 0};

    for(int i = a; i < a + YFactor; i++) {
        for(int j = b; j < b + XFactor; j++) {
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

    XFactor = ceil(width / a);
    YFactor = ceil(height / b);

    image.Xsize = ceil(width / XFactor);
    image.Ysize = ceil(height / YFactor);

    // Averaging the pixel colors to reduce the res
    for(int i = 0; i < image.Ysize; i++) {
        for(int j = 0; j < image.Xsize; j++) {
            int startX = i * YFactor;
            int startY = j * XFactor;

            averaged = AveragingFunction(startX, startY, XFactor, YFactor);
            image.hueMap[i][j]      = averaged.h;
            image.valueMap[i][j]    = averaged.v;
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
