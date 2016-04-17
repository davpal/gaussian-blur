#pragma once
#include <CImg.h>

using namespace cimg_library;

CImg<unsigned char> gaussianMultiThread(const CImg<unsigned char> & image, float radius, int threads);
