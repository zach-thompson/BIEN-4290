/*
* Author: Zach Thompson
* Date: 2/15/22
* Description: Header file for corr
*/

#ifndef corr_guard
#define corr_guard

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "thompsz_stats.hpp"
#include <math.h>

namespace corrSpace {
    class corrClass {
        public:

        corrClass(std::vector<float>*, std::vector<float>*);

        float calc_corr(std::vector<float>*, std::vector<float>*);
    };
}

#endif