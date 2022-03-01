#include "thompsz_k_means.hpp"
/*
* Author: Zach Thompson
* Date: 2/24/22
* Description: Performs K-clustering on an input file
* Includes: tbd
*/

void kSpace::cluster::set_name(std::string in) {
    std::string name;
    this->name = in; 
}

std::string kSpace::cluster::get_name() {
    return this->name;
}

void kSpace::cluster::set_mean(std::vector<float> object) {
    float mean = 0;
    float sum = 0;
    float size = object.size();
    for (int i = 0; i < size; i++) {
        sum+= object[i];
    }
    this->mean = sum / size;
}

float kSpace::cluster::get_mean() {
    return this->mean;
}

float kSpace::cluster::distance(float point) {
    
}
