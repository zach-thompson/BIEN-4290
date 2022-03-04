#include "thompsz_k_means.hpp"
/*
* Author: Zach Thompson
* Date: 2/24/22
* Description: Performs K-clustering on an input file
* Includes: setters and getters for name and mean, and a distance function
*/
kSpace::cluster::cluster(double mean) {}

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

double kSpace::cluster::get_mean() {
    return this->mean;
}

float kSpace::cluster::distance(float in) {
    float point = 0;
    float temp_dist = 0;
    temp_dist = abs(point - this->mean);
    return temp_dist;
}
