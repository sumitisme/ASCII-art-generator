#include "../include/Imageloader.hpp"
#include "../include/background.hpp"

// For the Value
char BArray[] = {'.', '-' ,'*', '~', '=', '+', '#', '$', '&', 'X', '@'};

HSV RGBtoHSV(RGB in) {
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
    else if(vmax = in.r) {
        out.h = 60 * (fmod((in.g - in.b) / (vmax - vmin), 6));
    }
    else if(vmax = in.g) {
        out.h = 60 * ((in.b - in.r) / (vmax - vmin) + 2);
    }
    else if(vmax = in.b) {
        out.h = 60 * ((in.r - in.g) / (vmax - vmin) + 4);
    }

    if (out.h < 0) out.h += 360;

    return out;
}

int main(int argc, char* argv[]) {
    if(argv[1] == "") {
        std::cout << "Filename not given\n";
        return -1;
    }
    Imageloader test(argv[1]);

    // Testing
    Background bg(400, 200);
    bg.printBackground();

    int red     = test.imagePixelRed(100, 200);
    int green   = test.imagePixelRed(100, 200);
    int blue    = test.imagePixelRed(100, 200);

    std::cout << RED << "\nThe color profile at location 100, 200 is: r = " << red << ", g = " << green << ", b = " << blue << "\n" << RESET;

    // TODO lower the resolution of the image. 
    // Lower into the specified resolution first

    // TODO Sqwishing of the image since terminal prints in height x 2. So the height portion should be halved somehow (we will average the pixels using a 1:2 ratio of pixels)

    std::cout << "The width of the original image is: "             << test.imageWidth() << "\n";
    std::cout << "The height of the original image is: "            << test.imageHeight() << "\n";
    std::cout << "The no of channels in the original image is: "    << test.imageChannels() << "\n";
    return 0;
}
