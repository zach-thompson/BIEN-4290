/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Header file for stats
* Includes: getters and setter functions for min, max, mean, std
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
            void set_min(FILE* filename);
            void set_max(FILE* filename);
            void set_mean(FILE* filename);
            void set_std(FILE* filename);
            float get_min();
            float get_max();
            float get_mean();
            float get_std();

        private:
            float min;
            float max;
            float mean;
            float std;
    };
}

#endif stats_guard