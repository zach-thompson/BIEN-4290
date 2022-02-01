/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Header file for stats
* Includes: get_min, get_max, get_mean, get_std, get_hist
*/

#ifndef stats_guard
#define stats_guard

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>

namespace stats {
    class stats {
        public: 
            void set_min();
            float get_min();
            void set_max();
            float get_max();
            void set_mean();
            float get_mean();
            void set_std();
            float get_std();
            void get_hist(file* name);
    };
}

#endif stats_guard