#include "../include/constants.hpp"
#include "../include/Imageloader.hpp"
#include "../include/background.hpp"

int main(int argc, char* argv[]) {
    if(argv[1] == "") {
        std::cout << "Filename not given\n";
        return -1;
    }

    Imageloader test(argv[1]);

    Background bg(400, 200);
    bg.printBackground();

    int red     = test.imagePixelRed(100, 200);
    int green   = test.imagePixelRed(100, 200);
    int blue    = test.imagePixelRed(100, 200);

    std::cout << RED << "\nThe color profile at location 100, 200 is: r = " << red << ", g = " << green << ", b = " << blue << "\n" << RESET;

    // TODO lower the resolution of the image. 
    // TODO Sqwishing of the image since terminal prints in height x 2. So the height portion should be halved somehow (we will average the pixels using a 1:2 ratio of pixels)
    // TODO RGB to HSV converter. After which we can use the colors and brightness array 

    std::cout << "The width of the original image is: "             << test.imageWidth() << "\n";
    std::cout << "The height of the original image is: "            << test.imageHeight() << "\n";
    std::cout << "The no of channels in the original image is: "    << test.imageChannels() << "\n";
    return 0;
}
