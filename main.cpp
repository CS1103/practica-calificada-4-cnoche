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
    //std::string name = "in.png";

    /* ************************************************
        Two more options suggested,
        uncomment the option you'd like to try.
        Please note the output files will have the same name, given the filter is the same.
     ************************************************** */
    
    std::string name = "./test_cases/mario.png";
    //std::string name = "land.png"; // I chose this pic because its really pretty, though its quite large.

    //choose the activity
    green(name);
    //red(name);
    //blue(name);
    //rotate(name);

}
