#include "../include/Imageloader.hpp"
#include "../include/background.hpp"

// For the Value
char BArray[] = {'.', '-' ,'*', '~', '=', '+', '#', '$', '&', 'X', '@'};

void printer(Map out) {
    Background bg(out);

    int value;
    int hue;
    for(int i = 0; i < out.Ysize; i++) {
        for(int j = 0; j < out.Xsize; j++) {
            value = out.valueMap[i][j];
            hue = out.hueMap[i][j];

            if(value < 23) {
                bg.setBackground(i, j, BArray[0]);
            }
            else if(value >= 23 && value < 46) {
                bg.setBackground(i, j, BArray[1]);
            }
            else if(value >= 46 && value < 69) {
                bg.setBackground(i, j, BArray[2]);
            }
            else if(value >= 69 && value < 92) {
                bg.setBackground(i, j, BArray[3]);
            }
            else if(value >= 92 && value < 115) {
                bg.setBackground(i, j, BArray[4]);
            }
            else if(value >= 115 && value < 138) {
                bg.setBackground(i, j, BArray[5]);
            }
            else if(value >= 138 && value < 161) {
                bg.setBackground(i, j, BArray[6]);
            }
            else if(value >= 161 && value < 184) {
                bg.setBackground(i, j, BArray[7]);
            }
            else if(value >= 184 && value < 207) {
                bg.setBackground(i, j, BArray[8]);
            }
            else if(value >= 207 && value < 230) {
                bg.setBackground(i, j, BArray[9]);
            }
            else if(value >= 230) {
                bg.setBackground(i, j, BArray[10]);
            }
        }
    }
    bg.printBackground();
}

int main(int argc, char* argv[]) {
    Map finalOutput;

    if(argv[1] == "") {
        std::cout << "Filename not given\n";
        return -1;
    }
    Imageloader test(argv[1]);

    // Testing

    finalOutput = test.imageDropRes(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    printer(finalOutput);

    /* //Testing and debugging stuff here

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

    */

    return 0;
}
