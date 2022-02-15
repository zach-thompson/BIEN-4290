#include "thompsz_stats.hpp"
/*
* Author: Zach Thompson
* Date: 2/1/22
* Description: Verifies the existence of a data file and performs basic calculations on the data
*/

int main (int argc, char* argv[]) {

    std::ifstream dataFile("ERP00/ERP001.txt");
    std::vector<float> file;

    if (!dataFile.is_open()) {
        printf("Invalid file.\n\r");
        return 0;
    }

    float temp;
    while (dataFile >> temp) {
		file.push_back(temp);
    }
    dataFile.close();

    statSpace::statClass statClassy(&file);

    statClassy.set_min(&file);
    statClassy.set_max(&file);
    statClassy.set_mean(&file);
    statClassy.set_stddev(&file);

    std::cout << "Number of points: " << file.size() << "\n";
    std::cout << "Mean: " << statClassy.get_mean() << "\n";
    std::cout << "STD: " << statClassy.get_stddev() << "\n";
    std::cout << "Minimum: " << statClassy.get_min() << "\n";
    std::cout << "Maximum: " << statClassy.get_max() << "\n";
    statClassy.make_histogram(&file, statClassy.get_mean(), statClassy.get_stddev());
    
    return 0;
}