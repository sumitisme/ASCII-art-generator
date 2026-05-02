#include "../include/constants.hpp"
#include "../include/Imageloader.hpp"
#include "../include/background.hpp"

int main(int argc, char* argv[]) {
    if(argv[1] == "") {
        std::cout << "Filename not given\n";
        return -1;
    }

    Imageloader test(argv[1]);

    Background bg(200, 100);
    bg.printbackground();

    std::cout << "The width of the original image is: "             << test.imagewidth() << "\n";
    std::cout << "The height of the original image is: "            << test.imageheight() << "\n";
    std::cout << "The no of channels in the original image is: "    << test.imagechannels() << "\n";
    return 0;
}
