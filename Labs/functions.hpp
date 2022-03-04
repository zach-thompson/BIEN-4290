/*
* Author: Zach Thompson
* Date: 3/4/22
* Purpose: Collection of functions created during BIEN 4290 for later use
* Contains: get/set_min/max/mean/stddev/name, make_histogram, calc_correlation, sum/subtract/divide_array(s) 
*/

#ifndef stats_guard
#define stats_guard

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

namespace functionSpace {
    class function {
        public:

            // construct various verions of function objects
            function();
            function(std::vector<float>*);
            function(std::vector<float>*, float);
            function(std::string, float);
            function(std::vector<float>*, std::vector<float>*);
            
            // functions
            void set_min(std::vector<float>*);
            void set_max(std::vector<float>*);
            void set_mean(std::vector<float>*);
            void set_stddev(std::vector<float>*);
            void set_name(std::string name);
            float get_min();
            float get_max();
            float get_mean();
            float get_stddev();
            std::string get_name();
            void make_histogram(std::vector<float>*, float mean_in, float std_in);
            float calc_correlation(std::vector<float>*, std::vector<float>*);
            float sum_array(std::vector<float>*);
            std::vector<float> subtract_arrays(std::vector<float>*, std::vector<float>*);
            std::vector<float> divide_array(std::vector<float>*, float);
            float distance_to_mean(float point);
            

        private:
            // variables
            float min;
            float max;
            float mean;
            float stddev;
            std::string name;
    };
}

#endif