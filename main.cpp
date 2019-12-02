#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <thread>

#include "lodepng.h"
#include "img.hpp"
#include "manage_png.hpp"

using namespace std;

int main()
{
    std::string name = "in.png";

    auto t1 = thread(green,name);
    auto t2 = thread(red,name);
    auto t3 = thread (blue,name);

    t1.join();
    t2.join();
    t3.join();

}
