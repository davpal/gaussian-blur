#include <iostream>
#include <CImg.h>

using namespace cimg_library;

void help();

int main(int argc, char * argv[]) {
    if(argc < 2) {
        help();
        exit(0);
    }

    CImg<unsigned char> image(argv[1]);
    CImgDisplay imageDisplay(image, "Original image");
    while(!imageDisplay.is_closed()) {
        imageDisplay.wait();
    }
}

void help() {
    std::cout << "usage: gaussian_blur <image>\n";
}
