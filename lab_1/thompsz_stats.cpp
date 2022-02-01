#include "thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Main file for stats class
* Includes: Definitions for the getter and setter functions for min, max, mean, std
*/

static void set_mean(std::vector<float>* name) {
    // calc mean and set to temp mean
    float mean;
    this->statsmean = mean;
}

static float get_mean() {
    return this->mean;
}
