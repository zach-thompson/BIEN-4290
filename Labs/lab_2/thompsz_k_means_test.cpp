#include "thompsz_k_means.hpp"
/*
* Author: Zach Thompson
* Date: 3/1/22
* Description: Performs K-clustering on an input file
* Includes: tbd
*/

int main (int argc, char* argv[]) {
    std::ifstream file1("log_ratio_input.dat"); // file containing data from sporulating cells (red)
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

    kSpace::cluster c1();
    kSpace::cluster c2();
    kSpace::cluster c3();

    // c1.set_name("suppressed");
    // c1.set_mean(-0.5);
    // c2.set_name("stationary");
    // c2.set_mean(0);
    // c3.set_name("expressed");
    // c3.set_mean(0.5);
}