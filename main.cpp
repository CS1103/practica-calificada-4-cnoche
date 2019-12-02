#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <thread>

#include "lodepng.h"
#include "img_color.hpp"
#include "manage_png.hpp"
#include "rotation.hpp"

using namespace std;

int main()
{
    //test case provided by the execise
    std::string name = "./test_cases/in.png";

    /* ************************************************
        Two more options suggested,
        uncomment the option you'd like to try.
        Please note the output files will have the same name, given the filter is the same.
     ************************************************** */
    
    //std::string name = "./test_cases/mario.png"; //this is a good test case becuase of it's color contrast
    //std::string name = "land.png"; // I chose this pic because its really pretty, 
                                    // though its quite large. Please be mindful of this while running tests.
    //std::string name = "./test_cases/chamaleon.png"; //good color contrast, good for testing
    
    //choose the activity
    
    //green(name);
    //red(name);
    blue(name);

    rotate(name);

}
