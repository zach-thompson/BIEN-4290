#include "thompsz_k_means.hpp"
/*
* Author: Zach Thompson
* Date: 3/1/22
* Description: Performs K-clustering on an input file
* Includes: tbd
*/

int main (int argc, char* argv[]) {
    std::ifstream file1("intensity_0.dat"); // file containing data from sporulating cells (red)
    std::vector<float> data;

    if (!file1.is_open()) {
        printf("A data file cannot be found.\n");
        return 0;
    }

    float temp;
    while (file1 >> temp) {
		  data.push_back(temp);
    }
    file1.close();

    kSpace::cluster clustery(22.2);

    kSpace::cluster c1(-0.5);
    kSpace::cluster c2(0.0);
    kSpace::cluster c3(0.5);

    c1.set_name("suppressed");
    c2.set_name("stationary");
    c3.set_name("expressed");
}