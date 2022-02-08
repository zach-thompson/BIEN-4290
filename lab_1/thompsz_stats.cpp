#include "thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Main file for stats class
* Includes: Definitions for the get- and set- functions for min, max, mean, std, and histogram
*/

statSpace::statClass::statClass(std::vector<float>* file) {}

void statSpace::statClass::set_min(std::vector<float>* file) {
    float temp_min = 100;
    for (int i = 0; i < file->size(); i++) {
        if (file->at(i) < temp_min) {
            temp_min = file->at(i);
        }
    }
    this->min = temp_min;
}

void statSpace::statClass::set_max(std::vector<float>* file) {
    float temp_max = 0;
    for (int i = 0; i < file->size(); i++) {
        if (file->at(i) > temp_max) {
            temp_max = file->at(i);
        }
    }
    this->max = temp_max;
}

void statSpace::statClass::set_mean(std::vector<float>* file) {
    float sum = 0;
    float size = file->size();
    for (int i = 0; i < size; i++) {
        sum+= file->at(i);
    }
    this->mean = sum / size;
}

void statSpace::statClass::set_std(std::vector<float>* file) {
    // calc std
    float temp_std;
    this->std = temp_std;
}

float statSpace::statClass::get_min() {
    return this->min;
}

float statSpace::statClass::get_max() {
    return this->max;
}

float statSpace::statClass::get_mean() {
    return this->mean;
}

float statSpace::statClass::get_std() {
    return this->std;
}