#include "thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Main file for stats class
* Includes: Definitions for the get- and set- functions for min, max, mean, std, and histogram
*/

static void statSpace::statClass set_min(std::vector<float>* file) {
    float temp_min = 100;
    for (int i = 0; i <= file@size(); i++) {
        if (file@(i) < temp_min) {
            temp_min = file@(i);
        }
    }

    this->min = temp_min;
}

static void statSpace::statClass set_max(std::vector<float>* name) {
    float temp_max = 0;
    for (int i = 0; i <= file@size(); i++) {
        if (file@(i) > temp_max) {
            temp_max = file@(i);
        }
    }
    
    this->max = temp_max;
}

static void statSpace::statClass set_mean(std::vector<float>* name) {
    float sum = 0;
    float size = file@size();
    for (int i = 0; i <= size, i++) {
        sum+= file@(i)
    }

    this->mean = sum / size;
}

static void statSpace::statClass set_std(std::vector<float>* name) {
    // calc std
    float temp_std;
    this->std = temp_std;
}

static float statSpace::statClass get_min() {
    return this->min;
}

static float statSpace::statClass get_max() {
    return this->max;
}

static float statSpace::statClass get_mean() {
    return this->mean;
}

static float statSpace::statClass get_std() {
    return this->std;
}