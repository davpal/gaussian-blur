#pragma once
#include <CImg.h>

using namespace cimg_library;

CImg<unsigned char> gaussianBlur(const CImg<unsigned char> & originalImage, float radius);

