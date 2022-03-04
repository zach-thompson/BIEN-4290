#include "functions.hpp"
/*
* Author: Zach Thompson
* Date: 3/4/22
* Description: Main file for stats class
* Includes: Definitions for the get- and set- functions for min, max, mean, std, and histogram
*/

void functionSpace::function::set_min(std::vector<float>* file) {
    float min = 0;
    float temp_min = 100;
    for (int i = 0; i < file->size(); i++) {
        if (file->at(i) < temp_min) {
            temp_min = file->at(i);
        }
    }
    this->min = temp_min;
}

void functionSpace::function::set_max(std::vector<float>* file) {
    float max = 0;
    float temp_max = 0;
    for (int i = 0; i < file->size(); i++) {
        if (file->at(i) > temp_max) {
            temp_max = file->at(i);
        }
    }
    this->max = temp_max;
}

void functionSpace::function::set_mean(std::vector<float>* file) {
    float mean = 0;
    float sum = 0;
    float size = file->size();
    for (int i = 0; i < size; i++) {
        sum+= file->at(i);
    }
    this->mean = sum / size;
}

void functionSpace::function::set_stddev(std::vector<float>* file) {
    // get mean first
    functionSpace::function function(file);
    function.set_mean(file);
    mean = get_mean();

    // calculate standard deviation
    float sum = 0;
    for (int i = 0; i < file->size(); i++) {
        sum += pow(file->at(i) - mean, 2);
    }

    this->stddev = sqrt(sum / file->size());
}

float functionSpace::function::get_min() {
    return this->min;
}

float functionSpace::function::get_max() {
    return this->max;
}

float functionSpace::function::get_mean() {
    return this->mean;
}

float functionSpace::function::get_stddev() {
    return this->stddev;
}

void functionSpace::function::make_histogram(std::vector<float>* file, float mean_in, float stddev_in) {
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
    std::cout << "\nHistogram: Each '=' is 100 data points\n\r";
    for (int i = 0; i <= num_bins; i++) {
        std::cout << "Bin " << i << " (" << bin_starters[i] << ") \t| ";
        for (int j = 0; j < bin_counts[i]/100; j++) {
           std::cout << "=";
        }
        std::cout << " " << bin_counts[i] << "\n";
    }

    free(bin_starters);
    free(bin_counts);
    return;
}

float functionSpace::function::calc_correlation(std::vector<float>* file_x, std::vector<float>* file_y) {
    functionSpace::function function;
    function.set_mean(file_x);
    float mean_x = function.get_mean();
    function.set_mean(file_y);
    float mean_y = function.get_mean();

    // whole bunch of mathy math
    float n = file_x->size();
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0, sum_yy = 0;
    for(int i = 0; i < n; i++) {
        sum_x += file_x->at(i);
        sum_y += file_y->at(i);
        sum_xy += file_x->at(i) * file_y->at(i);
        sum_xx += pow(file_x->at(i), 2);
        sum_yy += pow(file_y->at(i), 2);
    }

    float corr_xy = (sum_xy - n * mean_x * mean_y) / sqrt( (sum_xx - n * pow(mean_x, 2)) * (sum_yy - n * pow(mean_y, 2)) );
    return corr_xy;
}

float functionSpace::function::sum_array(std::vector<float>* file) {
    float sum = 0;
    for (int i = 0; i<file->size(); i++) {
        sum += file->at(i);
    }
    return sum;
}

std::vector<float> functionSpace::function::subtract_arrays(std::vector<float>* file_x, std::vector<float>* file_y) {
    // create output vector
    std::vector<float> difference;

    for (int i = 0; i < file_x->size(); i++) {
        difference.push_back(file_x->at(i) - file_y->at(i));
    }

    return difference;
}

std::vector<float> functionSpace::function::divide_array(std::vector<float>* file, float divisor) {
    // create output vector
    std::vector<float> quotient;

    for (int i = 0; i < file->size(); i++) {
        quotient.push_back(file->at(i) / divisor);
    }

    return quotient;
}

float functionSpace::function::distance_to_mean(float in) {
    float dist = fabs(in - this->mean);
    return dist;
}

functionSpace::function::function() {} // used in set_stddev
functionSpace::function::function(std::vector<float>* file) {} // used in calc_correlation