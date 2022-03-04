#include "thompsz_k_means.hpp"
/*
* Author: Zach Thompson
* Date: 2/24/22
* Description: Performs K-clustering on an input file
* Includes: setters and getters for name and mean, and a distance function
*/

kSpace::cluster::cluster(std::string name_in, float mean_in) {
    this->name = name_in;
    this->mean = mean_in;
}

void kSpace::cluster::set_name(std::string in) {
    std::string name;
    this->name = in; 
}

std::string kSpace::cluster::get_name() {
    return this->name;
}

void kSpace::cluster::set_mean(std::vector<float> object) {
    float mean = 0;
    float sum = 0;
    float size = object.size();
    for (int i = 0; i < size; i++) {
        sum+= object[i];
    }
    this->mean = sum / size;
}

double kSpace::cluster::get_mean() {
    return this->mean;
}

float kSpace::cluster::distance(float in) {
    float dist = 0;
    dist = fabs(in - this->mean);
    return dist;
}

int main (int argc, char* argv[]) {
    std::ifstream file1("intensity_0.dat"); // file containing data from sporulating cells (red)
    std::vector<float> data; // vector to hold file data

    if (!file1.is_open()) { // determine if both files exists
        printf("A data file cannot be found.\n");
        return 0;
    }

    float temp;
    while (file1 >> temp) { // fill vector from file
		data.push_back(temp);
    }
    file1.close();

    // initialize clusters
    kSpace::cluster c1("suppressed", -0.5);
    kSpace::cluster c2("stationary", 0.0);
    kSpace::cluster c3("expressed", 0.5);

    std::vector<float> c1_data, c2_data, c3_data;
    float criteria;

    do {
        // fill clusters
        for (int i = 0; i < data.size(); i++) {
            // calculate distance from point to each cluster mean
            float d1 = c1.distance(data[i]);
            float d2 = c2.distance(data[i]);
            float d3 = c3.distance(data[i]);

            // assign each point to the appropriate cluster
            if ((d1 <= d2) && (d1 <= d3)) {
                c1_data.push_back(data[i]);
            }
            else if (d2 <= d3) {
                c2_data.push_back(data[i]);
            }
            else {
                c3_data.push_back(data[i]);
            }
        }

        // get old cluster means
        float old_mean_c1 = c1.get_mean();
        float old_mean_c2 = c2.get_mean();
        float old_mean_c3 = c3.get_mean();

        // set new cluster means using sorted data
        c1.set_mean(c1_data);
        c2.set_mean(c2_data);
        c3.set_mean(c3_data);

        // calculate the criteria value by comparing the old mean to the new mean
        criteria = c1.distance(old_mean_c1) + c2.distance(old_mean_c2) + c3.distance(old_mean_c3);

        // remove all data points from each cluster
        c1_data.clear();
        c2_data.clear();
        c3_data.clear();
    } while (criteria > .0001);
    
    // open gene_list.txt and create files to write to
    FILE* gene_list = fopen("gene_list.txt", "r");
    FILE* expressed = fopen("exppressed_genes.txt", "w");
    FILE* suppressed = fopen("suppressed_genes.txt", "w");
    FILE* stationary = fopen("stationary_genes.txt", "w");
    int j = 0;

    if (gene_list != NULL) {
        char gene[10];
        //fgets(gene, 10, gene_list); // load first gene
        while (!feof (gene_list))
        {
            // establish values (basically redoing last loop of clustering)
            float point = data[j];
            float d1 = c1.distance(point);
            float d2 = c2.distance(point);
            float d3 = c3.distance(point);
            fgets(gene, 10, gene_list); // load gene
        
            // add gene to appropriate file
            if (d1 <= d2 && d1 <= d3) {
                fprintf(suppressed, "%s", gene);
            }
            else if (d2 <= d3) {
                fprintf(stationary, "%s", gene);
            }
            else {
                fprintf(expressed, "%s", gene);
            }
            j++;
            // fgets(gene, 10, gene_list); // load next gene  
        }
        fclose(gene_list);
        fclose(suppressed);
        fclose(stationary);
        fclose(expressed);
        return 0;
    }



}