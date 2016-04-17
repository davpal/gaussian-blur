#include "gaussian_blur.h"
#include <cmath>
#include <iostream>

CImg<unsigned char> gaussianBlur(const CImg<unsigned char> & originalImage, float radius) {
    CImg<unsigned char> image(originalImage);
    std::vector<int> box = gaussianBoxes(radius, 3);
    boxBlur(image, (box[0] - 1) / 2);
    boxBlur(image, (box[1] - 1) / 2);
    boxBlur(image, (box[2] - 1) / 2);
    return image;
}

void boxBlur(CImg<unsigned char> & image, float r) {
    for(int i = 0; i < image.height(); ++i)
        for(int j = 0; j < image.width(); ++j) {
            float red = 0;
            float green = 0;
            float blue = 0;
            for(int iy = i - r; iy < i + r + 1; ++iy)
                for(int ix = j - r; ix < j + r + 1; ++ix) {
                    int x = std::min(image.width()  - 1, std::max(0, ix));
                    int y = std::min(image.height() - 1, std::max(0, iy));
                    red   += image(x, y, 0, 0);
                    green += image(x, y, 0, 1);
                    blue  += image(x, y, 0, 2);
                }

            image(j, i, 0, 0) = red   / ((r + r + 1) * (r + r + 1));
            image(j, i, 0, 1) = green / ((r + r + 1) * (r + r + 1));
            image(j, i, 0, 2) = blue  / ((r + r + 1) * (r + r + 1));
        }
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
