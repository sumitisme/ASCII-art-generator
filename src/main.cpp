#include "../include/constants.hpp"
#include "../include/Imageloader.hpp"
#include "../include/background.hpp"

int main(int argc, char* argv[]) {
    if(argv[1] == "") {
        std::cout << "Filename not given\n";
        return -1;
    }

    Imageloader test(argv[1]);

    Background bg(100, 50);
    bg.printbackground();

//    Pixel a[300][150];
//    a[100][120] = test.imagepixelinfo(100, 120);

//    std::cout << "at location 100, 120, the color profile is: r = " << a[100][120].r << ", g = " << a[100][120].g << ", b = " << a[100][120].b << "\n";

    std::cout << "The width of the original image is: "             << test.imagewidth() << "\n";
    std::cout << "The height of the original image is: "            << test.imageheight() << "\n";
    std::cout << "The no of channels in the original image is: "    << test.imagechannels() << "\n";
    return 0;
}
