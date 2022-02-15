#include "thompsz_corr.hpp"
/*
* Author: Zach Thompson
* Date: 2/15/22
* Description: Estimates the correlation coefficient between two data sets
*/

corrSpace::corrClass::corrClass(std::vector<float>* file_x, std::vector<float>* file_y) {}

float corrSpace::corrClass::calc_corr(std::vector<float>* file_x, std::vector<float>* file_y) {
    statSpace::statClass statClassy;
    statClassy.set_mean(file_x);
    float mean_x = statClassy.get_mean();
    statClassy.set_mean(file_y);
    float mean_y = statClassy.get_mean();

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