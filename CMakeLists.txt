cmake_minimum_required(VERSION 3.3)
project(gaussian_blur)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/gaussian_blur.cpp)

find_package( CImg REQUIRED )

link_directories(${CImg_SYSTEM_LIBS_DIR})
include_directories(${CImg_INCLUDE_DIRS})

add_executable(gaussian_blur ${SOURCE_FILES})