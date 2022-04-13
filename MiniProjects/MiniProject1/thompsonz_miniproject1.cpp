#include "../../Labs/lab_1/thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 4/12/2022
* Description: Calculate statistics of the airspeed velocity of swallows
*/

int main (int argc, char* argv[]) {

    std::ifstream file1(argv[1]); // file containing data from sporulating cells (red)
    std::vector<float> data;

    if (!file1.is_open()) {
        printf("The data file cannot be found.\n");
        return 0;
    }

    float temp;
    while (file1 >> temp) {
		  data.push_back(temp);
    }
    file1.close();

    statSpace::statClass statClassy(&data);

    statClassy.set_min(&data);
    statClassy.set_max(&data);
    statClassy.set_mean(&data);

}