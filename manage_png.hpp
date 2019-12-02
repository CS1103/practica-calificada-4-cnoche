#ifndef MANAGE_PNG_HPP
#define MANAGE_PNG_HPP

#include <iostream>
#include <vector>
#include <string_view>
#include <string.h>

#include "lodepng.h"

using namespace std;

std::vector<unsigned char> decode(std::string_view filename,
    unsigned int& width, unsigned int& height);


void encode(std::string_view filename, std::vector<unsigned char>& image, 
    unsigned width, unsigned height);

#endif