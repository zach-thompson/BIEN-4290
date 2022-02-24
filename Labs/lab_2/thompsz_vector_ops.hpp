/*
* Author: Zach Thompson
* Date: 2/15/22
* Description: Header file for vector_ops
* Includes: Vector operations object creators, sum_array, subtract_arrays, divide_array
*/

#ifndef vector_ops_guard
#define vector_ops_guard

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace vectorSpace{
    class vectorClass{
        public:
            // object creation types
            vectorClass();
            vectorClass(std::vector<float>*);
            vectorClass(std::vector<float>*, std::vector<float>*);
            vectorClass(std::vector<float>*, float);

            // functions
            float sum_array(std::vector<float>*);
            std::vector<float> subtract_arrays(std::vector<float>*, std::vector<float>*);
            std::vector<float> divide_array(std::vector<float>*, float);

    };
}

#endif