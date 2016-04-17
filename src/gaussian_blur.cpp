#include "gaussian_blur.h"
#include <cmath>

CImg<unsigned char> gaussianBlur(const CImg<unsigned char> & originalImage, float radius) {
    CImg<unsigned char> image(originalImage);
    std::vector<int> box = gaussianBoxes(2.0f, 3);
    return image;
}

std::vector<int> gaussianBoxes(float sigma, int n) {
    float ideal = std::sqrt((12 * sigma * sigma / n) + 1);
    int wl = std::floor(ideal);
    if(wl % 2 == 0) --wl;
    int wu = wl + 2;

    float mIdeal = (12*sigma*sigma - n*wl*wl - 4*n*wl - 3*n) / (-4*wl - 4);
    int m = std::round(mIdeal);

    std::vector<int> sizes(n);
    for(int i = 0; i < n; ++i)
        sizes[i] = i < m ? wl : wu;

    return sizes;
}
