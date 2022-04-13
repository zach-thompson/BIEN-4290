#include "/home/thompsz/Labs/lab_1/thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 4/12/2022
* Description: Calculate statistics of the airspeed velocity of swallows
*/

int main (int argc, char* argv[]) {

    // load file from command line argument
    // argument expected to be "swallowspeed.dat" for this project
    std::ifstream file1(argv[1])

    // check for file
    if (!file1.is_open()) {
        printf("The data file cannot be found.\n");
        return 0;
    }

    // fill vector with file data
    float temp;
    std::vector<float> data;
    while (file1 >> temp) {
		  data.push_back(temp);
    }
    file1.close();

    // establish statClass tp use functions
    statSpace::statClass statClassy(&data);

    // perform calculations and print results
    statClassy.set_min(&data);
    std::cout << "minimum: " << statClassy.get_min() << "\n";
    statClassy.set_max(&data);
    std::cout << "maximum: " << statClassy.get_max() << "\n";
    statClassy.set_mean(&data);
    std::cout << "mean: " << statClassy.get_mean() << "\n";
    statClassy.set_stddev(&data);
    std::cout << "std_dev: " << statClassy.get_stddev() << "\n";
    
}