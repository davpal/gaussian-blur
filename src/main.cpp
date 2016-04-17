#include <iostream>
#include <CImg.h>
#include "gaussian_blur.h"

using namespace cimg_library;

void help();

int main(int argc, char * argv[]) {
    if(argc < 3) {
        help();
        exit(0);
    }

    CImg<unsigned char> image(argv[1]);
    CImgDisplay imageDisplay(image, "Original image");
    
    CImg<unsigned char> blurred = gaussianBlur(image, atof(argv[2]));
    CImgDisplay blurredDisplay(blurred, "Blurred image");
    
    while(!imageDisplay.is_closed()) {
        imageDisplay.wait();
        blurredDisplay.wait();
    }
}

void help() {
    std::cout << "usage: gaussian_blur <image> <radius>\n";
}
