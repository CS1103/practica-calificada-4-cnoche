#include <iostream>
#include <cmath>
#include <vector>
#include <string_view>
#include <string>
#include <thread>

#include "manage_png.hpp"
using namespace std;
// i tried friends

void rotate(std::string name)
{
    unsigned int w;
    unsigned int h;

    std::vector<unsigned char> image = decode(name, w, h);
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            image[(i * w * 4 + j + 0 )*sin(45)]=image[i * w * 4 + j + 0];
            image[(i * w * 4 + j + 1 )*sin(45)]=image[i * w * 4 + j + 1];
            image[(i * w * 4 + j + 2 )*sin(45)]=image[i * w * 4 + j + 2];
            image[(i * w * 4 + j + 3 )*sin(45)]=image[i * w * 4 + j + 3];
        }
    }
    encode("./outimages/rotated.png",image,w,h);
}
