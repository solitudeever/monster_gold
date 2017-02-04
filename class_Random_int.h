#pragma once
#include "common_lib.h"

// get a random int between min and max, must srand first
// bonds inclusive
class Random_int
{
public:
    static int gen(int min, int max)
    {
        /* code given by quiz */
        // static used for efficiency, so we only calculate this value once
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  
        // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
};