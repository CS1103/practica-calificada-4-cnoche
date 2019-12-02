#ifndef IMG_HPP
#define IMG_HPP

#include <string>

void green(std::string name);
void red(std::string name);
void blue(std::string name);

std::vector<unsigned char> iterate_image(std::string name);
void iterate_blue(std::vector<unsigned char>& image, unsigned int start, unsigned int end, unsigned int w);
void iterate_red(std::vector<unsigned char>& image, unsigned int start, unsigned int end, unsigned int w);
void iterate_green(std::vector<unsigned char>& image, unsigned int start, unsigned int end, unsigned int w);
void rotate();
    
#endif