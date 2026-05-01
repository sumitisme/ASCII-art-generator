#include <iostream>

#include "../include/Imageloader.hpp"

int main(int argc, char* argv[]) {
    if(argv[1] == "") {
        std::cout << "Filename not given\n";
        return -1;
    }

    Imageloader test(argv[1]);
    std::cout << "The width of the image is: " << test.imagewidth() << "\n";
    std::cout << "The height of the image is: " << test.imageheight() << "\n";
    std::cout << "The no of channels in the image is: " << test.imagechannels() << "\n";
    return 0;
}
