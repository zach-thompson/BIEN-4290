#include "thompsz_pre_processing.hpp"
#include "thompsz_vector_ops.hpp"
/*
* Author: Zach Thompson
* Date: 2/20/22
* Description: Accepts 6 arguments and prints data to file
* Arguments: data file1, context file1, data file2, context file2, name of file to create, number of points to calibrate
* Returns: data filed named "argv[5]"" with calibrated intensity ratios between 2 file sets
*/

int main (int argc, char* argv[]) {

    std::ifstream file1(argv[1]); // file containing data from sporulating cells (red)
    std::vector<float> redData;
    std::ifstream file2(argv[2]); // file containing the correlating background red data
    std::vector<float> background_redData;
    std::ifstream file3(argv[3]); // file containing data from non-sporulating cells (green)
    std::vector<float> greenData;
    std::ifstream file4(argv[4]); // file containing the correlating background green data
    std::vector<float> background_greenData;
    std::fstream file5; // file to which the calibrated data will be written
    file5.open(argv[5]);
    int num = atoi(argv[6]); // number of genes to be sequenced

    // verify that all files exist and make sure the number of genes requested in within bounds
    if (!file1.is_open() || !file2.is_open() || !file3.is_open() || !file4.is_open() || !file5.is_open()) {
        printf("A data file cannot be found.\n");
        return 0;
    }
    else if (num > 6118) {
        printf("Number of genes requested exceeds data range\n");
        return 0;
    }

    // fill redData vector from file
    float temp;
    while (file1 >> temp) {
		  redData.push_back(temp);
    }
    file1.close();

    // fill background_redData vector from file
    while (file2 >> temp) {
		  background_redData.push_back(temp);
    }
    file2.close();

    // fill greenData vector from file
    while (file3 >> temp) {
      greenData.push_back(temp);
    }
    file3.close();

    // fill background_greenData from file
    while (file4 >> temp) {
		  background_greenData.push_back(temp);
    }
    file4.close();

    vectorSpace::vectorClass vectorClassy; // create vectorClass object

    // correct the red and green datasets by their corresponding backgrounds
    std::vector<float> correct_red = vectorClassy.subtract_arrays(&redData, &background_redData);
    std::vector<float> correct_green = vectorClassy.subtract_arrays(&greenData, &background_greenData);

    // calculate the means of the corrected datasets
    float red_mean = vectorClassy.sum_array(&redData) / num;
    float green_mean = vectorClassy.sum_array(&greenData) / num;

    // normalize the corrected datasets by their corresponding means
    std::vector<float> normal_red = vectorClassy.divide_array(&correct_red, red_mean);
    std::vector<float> normal_green = vectorClassy.divide_array(&correct_green, green_mean);

    // write the calculated log intensity ratios to the file specified in the input arguments
    for (int i = 0; i < num; i++) {
        file5 << std::log10(normal_red[i] / normal_green[i]) << "\n";
    }
    file5.close();

    return 0;
}