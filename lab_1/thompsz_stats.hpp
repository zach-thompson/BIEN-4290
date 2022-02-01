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

namespace statSpace {
    class statClass {
        public:
            void set_min(std::vector<float>*);
            void set_max(std::vector<float>*);
            void set_mean(std::vector<float>*);
            void set_std(std::vector<float>*);
            void set_histogram(std::vector<float>*);
            float get_min();
            float get_max();
            float get_mean();
            float get_std();
            float get_histogram();

        private:
            float min;
            float max;
            float mean;
            float std;
    };
}

#endif stats_guard