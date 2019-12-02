#include <iostream>
#include <vector>
#include <string_view>
#include <thread>

#include "lodepng.h"
#include "manage_png.hpp"

using namespace std;

void iterate_red(std::vector<unsigned char>& image, unsigned int start, unsigned int end, unsigned int w)
{
    for (unsigned int i = start; i < end; i++) 
    {
        for (unsigned int j = 0; j < w * 4; j += 4) 
        {
            //int r = image[i * w * 4 + j + 0]; // Red component
            image[i * w * 4 + j + 1] = 0; // Green component
            image[i * w * 4 + j + 2] = 0; // Blue component
            //int a = image[i * w * 4 + j + 3]; // Alpha component
        }
        encode("./outimages/red_filter.png", image, w, end);
    }
}



void iterate_blue(std::vector<unsigned char>& image, unsigned int start, unsigned int end, unsigned int w)
{
    for (unsigned int i = start; i < end; i++) 
    {
        for (unsigned int j = 0; j < w * 4; j += 4)
        {
            image[i * w * 4 + j + 0] = 0; // Red component
            image[i * w * 4 + j + 1] = 0; // Green component
            //int b = image[i * w * 4 + j + 2]; // Blue component
            //int a = image[i * w * 4 + j + 3]; // Alpha component
        }
        encode("./outimages/blue_filter.png", image, w, end);
    }
}

void iterate_green(std::vector<unsigned char>& image, unsigned int start, unsigned int end, unsigned int w)
{
    for (unsigned int i = start; i < end; i++)
    {
        for (unsigned int j = 0; j < w * 4; j += 4) 
        {
            image[i * w * 4 + j + 0] = 0; // Red component
            //int g = image[i * w * 4 + j + 1]; // Green component
            image[i * w * 4 + j + 2] = 0; // Blue component
            //int a = image[i * w * 4 + j + 3]; // Alpha component
        }
        encode("./outimages/green_filter.png", image, w, end);
    }
}

void red(std::string name)
{
    unsigned int w;
    unsigned int h;

    std::vector<unsigned char> image = decode(name, w, h);

    //separate current range into 4 to then feed the threads
    auto r0 = 0;
    auto r1 = h/4;
    auto r2 = h/2;
    auto r3 = (3*h)/4;
    
    std::thread t1(iterate_red,std::ref(image),r0,r1,w);
    std::thread t2(iterate_red,std::ref(image),r1,r2,w);
    std::thread t3(iterate_red,std::ref(image),r2,r3,w);
    std::thread t4(iterate_red,std::ref(image),r3,h,w);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
}

void green(std::string name)
{
    unsigned int w;
    unsigned int h;

    std::vector<unsigned char> image = decode(name, w, h);

    //separate current range into 4 to then feed the threads
    auto r0 = 0;
    auto r1 = h/4;
    auto r2 = h/2;
    auto r3 = (3*h)/4;


    std::thread t1(iterate_green,std::ref(image),r0,r1,w);
    std::thread t2(iterate_green,std::ref(image),r1,r2,w);
    std::thread t3(iterate_green,std::ref(image),r2,r3,w);
    std::thread t4(iterate_green,std::ref(image),r3,h,w);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
}

void blue(std::string name)
{
    unsigned int w;
    unsigned int h;

    std::vector<unsigned char> image = decode(name, w, h);

    //separate current range into 4 to then feed the threads
    auto r0 = 0;
    auto r1 = h/4;
    auto r2 = h/2;
    auto r3 = (3*h)/4;
    
    std::thread t1(iterate_blue,std::ref(image),r0,r1,w);
    std::thread t2(iterate_blue,std::ref(image),r1,r2,w);
    std::thread t3(iterate_blue,std::ref(image),r2,r3,w);
    std::thread t4(iterate_blue,std::ref(image),r3,h,w);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
}

void rotate(std::string name){
    std::cout << name << std::endl;
}