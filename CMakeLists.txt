cmake_minimum_required(VERSION 3.3)
project(gaussian_blur)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(Boost_USE_MULTITHREADED ON)

set(SOURCE_FILES
    src/main.cpp
    src/gaussian_blur.cpp
    src/gaussian_multithread.cpp)

find_package(CImg REQUIRED )
find_package(Boost COMPONENTS thread)

include_directories(${CIMG_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(gaussian_blur ${SOURCE_FILES})
target_link_libraries(gaussian_blur ${CIMG_LINK_LIBRARIES} ${Boost_LIBRARIES})
