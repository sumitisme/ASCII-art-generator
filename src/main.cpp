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

    int red     = test.imagepixelred(100, 200);
    int green   = test.imagepixelred(100, 200);
    int blue    = test.imagepixelred(100, 200);

    std::cout << RED << "\nThe color profile at location 100, 200 is: r = " << red << ", g = " << green << ", b = " << blue << "\n" << RESET;

    std::cout << "The width of the original image is: "             << test.imagewidth() << "\n";
    std::cout << "The height of the original image is: "            << test.imageheight() << "\n";
    std::cout << "The no of channels in the original image is: "    << test.imagechannels() << "\n";
    return 0;
}
