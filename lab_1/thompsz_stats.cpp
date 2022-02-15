#include "thompsz_stats.hpp"
#include <math.h>
/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Main file for stats class
* Includes: Definitions for the get- and set- functions for min, max, mean, std, and histogram
*/

statSpace::statClass::statClass(std::vector<float>* file) {}

void statSpace::statClass::set_min(std::vector<float>* file) {
    float min = 0;
    float temp_min = 100;
    for (int i = 0; i < file->size(); i++) {
        if (file->at(i) < temp_min) {
            temp_min = file->at(i);
        }
    }
    this->min = temp_min;
}

void statSpace::statClass::set_max(std::vector<float>* file) {
    float max = 0;
    float temp_max = 0;
    for (int i = 0; i < file->size(); i++) {
        if (file->at(i) > temp_max) {
            temp_max = file->at(i);
        }
    }
    this->max = temp_max;
}

void statSpace::statClass::set_mean(std::vector<float>* file) {
    float mean = 0;
    float sum = 0;
    float size = file->size();
    for (int i = 0; i < size; i++) {
        sum+= file->at(i);
    }
    this->mean = sum / size;
}

void statSpace::statClass::set_stddev(std::vector<float>* file) {
    // get mean first
    statSpace::statClass statClassy(file);
    statClassy.set_mean(file);
    mean = get_mean();

    // calculate standard deviation
    float sum = 0;
    for (int i = 0; i < file->size(); i++) {
        sum += pow(file->at(i) - mean, 2);
    }

    this->stddev = sqrt(sum / file->size());
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

float statSpace::statClass::get_stddev() {
    return this->stddev;
}

void statSpace::statClass::make_histogram(std::vector<float>* file, float mean_in, float stddev_in) {
    // establish variables
    float mean = mean_in;
    float stddev = stddev_in;
    float bin_width = 0.4 * stddev;
    float first_value = mean - (3 * stddev);
    float last_value = mean + (3 * stddev);
    int num_bins = (last_value - first_value) / bin_width;

    // establish bin arrays
    float* bin_starters = (float*) calloc(num_bins+1, sizeof(float)); // holds the starting values for each bin
    int* bin_counts = (int*) calloc(num_bins+1, sizeof(int)); // holds the number of data points within each bin

    // create histogram bins
    float bin_starts = first_value;
    for (int i = 0; i <= num_bins; i++) { // loops for the calculated number of bins
        bin_starters[i] = bin_starts; // fills bin_starters with inital bin values
        bin_starts += bin_width; // moves ahead the value of a bin width
    }

    // determine bin counts
    int bin_index;
    for (int i = 0; i < file->size(); i++) { // runs through all data points
        if ((file->at(i) >= first_value) && (file->at(i) <= last_value)) { // checks if data point is within desired range
            bin_index = (file->at(i) - first_value) / bin_width; // determines which bin the data falls under
            ++bin_counts[bin_index]; // increases count at that bin index by 1
        }
    }
    
    // print bins and their counts
    std::cout << "\nHistogram: Each '=' is 10 points\n\r";
    for (int i = 0; i <= num_bins; i++) {
        std::cout << "Bin " << i << " (" << bin_starters[i] << ") \t| ";
        for (int j = 0; j < bin_counts[i]/10; j++) {
           std::cout << "=";
        }
        std::cout << " " << bin_counts[i] << "\n";
    }

    free(bin_starters);
    free(bin_counts);
    return;
}