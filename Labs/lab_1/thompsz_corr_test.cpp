#include "thompsz_corr.hpp"
/*
* Author: Zach Thompson
* Date: 2/15/22
* Description: Verifies the existence of two data files and returns the correlation coefficient between them
*/

int main (int argc, char* argv[]) {

    std::ifstream dataFile1("ERP00/ERP001.txt");
    std::ifstream dataFile2("ERP00/ERP002.txt");
    std::vector<float> file1;
    std::vector<float> file2;

    if (!dataFile1.is_open() || !dataFile2.is_open()) {
        printf("A data file cannot be found.\n\r");
        return 0;
    }

    float temp;
    while (dataFile1 >> temp) {
		file1.push_back(temp);
    }
    dataFile1.close();

    while (dataFile2 >> temp) {
		file2.push_back(temp);
    }
    dataFile2.close();

    corrSpace::corrClass corrClassy(&file1, &file2);

    std::cout << "Correlation: " << corrClassy.calc_corr(&file1, &file2) << "\n";
    return 0;
}