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
}

void help() {
    std::cout << "usage: gaussian_blur <image>\n";
}
