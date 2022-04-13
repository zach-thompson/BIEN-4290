#include "/home/thompsz/BIEN-4290/Labs/lab_1/thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 4/12/2022
* Description: Calculate statistics of the airspeed velocity of swallows
*/
//statSpace::statClass::statClass(std::vector<float>*) {}

int main (int argc, char* argv[]) {

    // load file from command line argument
    // argument expected to be "swallowspeed.dat" for this project
    std::ifstream file1(argv[1]);

    // check to make sure an argument was given
    if (argv[1] == NULL) {
        printf("No argument given");
    }

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

    // establish statClass to use functions
    statSpace::statClass statClassy(&data);

    // perform calculations and print results
    statClassy.set_min(&data);
    std::cout << "minimum: " << statClassy.get_min() << "\n"; /*
    statClass.set_max(&data);
    std::cout << "maximum: " << statClass.get_max() << "\n";
    statClass.set_mean(&data);
    std::cout << "mean: " << statClass.get_mean() << "\n";
    statClass.set_stddev(&data);
    std::cout << "std_dev: " << statClass.get_stddev() << "\n";
    */
}