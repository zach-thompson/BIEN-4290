#include "thompsz_corr.hpp"
#include "thompsz_stats.hpp"
#include <math.h>
/*
* Author: Zach Thompson
* Date: 2/15/22
* Description: Estimates the correlation coefficient between two data sets
*/

corrSpace::corrClass::corrClass(std::vector<float>* file_x, std::vector<float>* file_y) {}
statSpace::statClass::statClass(std::vector<float>* file_x, std::vector<float>* file_y) {}

float corrSpace::corrClass::calc_corr(std::vector<float>* file_x, std::vector<float>* file_y) {
    /*statSpace::statClass statClassy(file_x, file_y);
    statClassy.set_mean(file_x);
    float mean_x = statClassy.get_mean();
    statClassy.set_mean(file_y);
    float mean_y = statClassy.get_mean(); */

    // whole bunch of mathy math
    float n = file_x->size();
    float sum_x, sum_y, sum_xy, sum_xx, sum_yy = 0;
    for(int i = 0; i < n; i++) {
        sum_x += file_x->at(i);
        sum_y += file_y->at(i);
        sum_xy += file_x->at(i) * file_y->at(i);
        sum_xx += pow(2, file_x->at(i));
        sum_yy += pow(2, file_y->at(i));
    }
    float mean_x = sum_x / n;
    float mean_y = sum_y / n;

    float corr_xy = (sum_xy - n * mean_x * mean_y) / sqrt( (sum_xx - n * pow(2, mean_x)) * (sum_yy - n * pow(2, mean_y)) );

    return corr_xy;
}