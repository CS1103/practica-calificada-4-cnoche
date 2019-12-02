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
    //test case provided by the execise
    std::string name = "in.png";

    /* ************************************************
        Two more options suggested,
        uncomment the option you'd like to try.
        Please note the output files will have the same name, given the filter is the same.
     ************************************************** */
    
    //std::string name = "mario.png";
    //std::string name = "land.png";

    auto t1 = thread(green,name);
    auto t2 = thread(red,name);
    auto t3 = thread (blue,name);

    t1.join();
    t2.join();
    t3.join();

}
