#include <iostream>
#include <vector>
#include <string_view>

#include "lodepng.h"
#include "manage_png.hpp"

using namespace std;

void red(std::string name){
    unsigned int w;
    unsigned int h;
    auto image = decode(name, w, h);
    for (size_t i = 0; i < h; i++) 
    {
        for (size_t j = 0; j < w * 4; j += 4) 
        {
            int r = image[i * w * 4 + j + 0]; // Red component
            int g = image[i * w * 4 + j + 1] = 0; // Green component
            int b = image[i * w * 4 + j + 2] = 0; // Blue component
            int a = image[i * w * 4 + j + 3]; // Alpha component
            std::cout << r << " ";
            std::cout << g << " ";
            std::cout << b << " ";
            std::cout << a << "|";
        }
            encode("red_filter.png", image, w, h);
    }
}

void blue(std::string name){
    unsigned int w;
    unsigned int h;
    auto image = decode(name, w, h);
    for (size_t i = 0; i < h; i++) 
    {
        for (size_t j = 0; j < w * 4; j += 4)
        {
            int r = image[i * w * 4 + j + 0] = 0; // Red component
            int g = image[i * w * 4 + j + 1] = 0; // Green component
            int b = image[i * w * 4 + j + 2]; // Blue component
            int a = image[i * w * 4 + j + 3]; // Alpha component
            std::cout << r << " ";
            std::cout << g << " ";
            std::cout << b << " ";
            std::cout << a << "|";
        }
        encode("blue_filter.png", image, w, h);
    }
}

void green(std::string name){
    unsigned int w;
    unsigned int h;
    auto image = decode(name, w, h);
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w * 4; j += 4) 
        {
            int r = image[i * w * 4 + j + 0] = 0; // Red component
            int g = image[i * w * 4 + j + 1]; // Green component
            int b = image[i * w * 4 + j + 2] = 0; // Blue component
            int a = image[i * w * 4 + j + 3]; // Alpha component
            std::cout << r << " ";
            std::cout << g << " ";
            std::cout << b << " ";
            std::cout << a << "|";
        }
            encode("green_filter.png", image, w, h);
    }
}

void rotate(){

}