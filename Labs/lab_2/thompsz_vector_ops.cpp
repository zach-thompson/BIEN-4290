#include "thompsz_vector_ops.hpp"
/*
* Author: Zach Thompson
* Date: 2/15/22
* Description: vector_ops
* Includes: getters and setter functions for min, max, mean, std
*/

vectorSpace::vectorClass::vectorClass(std::vector<float>* file) {};
vectorSpace::vectorClass::vectorClass(std::vector<float>* file_x, std::vector<float>* file_y) {};
vectorSpace::vectorClass::vectorClass(std::vector<float>* file, float) {};

float vectorSpace::vectorClass::sum_array(std::vector<float>* file) {
    float sum = 0;
    for (int i = 0; i<file->size(); i++) {
        sum += file->at(i);
    }
    return sum;
}

std::vector<float> vectorSpace::vectorClass::subtract_arrays(std::vector<float>* file_x, std::vector<float>* file_y) {
    // create output vector
    std::vector<float> difference;

    for (int i = 0; i < file_x->size(); i++) {
        difference[i] = file_x->at(i) - file_y->at(i);
    }

    return difference;
}

std::vector<float> vectorSpace::vectorClass::divide_array(std::vector<float>* file, float divisor) {
    // create output vector
    std::vector<float> quotient;

    for (int i = 0; i < file->size(); i++) {
        quotient[i] = file->at(i) / divisor;
    }

    return quotient;
}