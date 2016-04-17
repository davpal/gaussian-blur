#pragma once
#include <CImg.h>
#include <vector>

using namespace cimg_library;

CImg<unsigned char> gaussianBlur(const CImg<unsigned char> & originalImage, float radius);
std::vector<int> gaussianBoxes(float sigma, int n);
void boxBlur(CImg<unsigned char> & image, float r);
