#include "drugfactory.hpp"
#include <ifstream>
/*
* Author: Zach Thompson
* Date: 4/20/22
* Description: Defines functions in drugfactory.hpp
*/

DrugFactory::DrugFactory(std::string path) {
    this->drug_warehouse_path = path;
}

class CandyFactory : public DrugFactory {
    public:

        Drug* makeDrug() override {
            // check ingredients
            // if all ingredients = 1, shipDrug()
            return 0;
        }

        void shipDrug() override {
            // write to file in ./warehouse
            // read and append value
            std::fstream file;
            file.open("Jolly_Rancher.txt");
            if (file.isOpen()) {
                getline(file, value);
                value++;
               "jolly_rancher.txt" << value;
            }
            else {
                std::ifstream file("Jolly_Rancher.txt", rw);
                int value = 1;
                "~/Factory_Project/warehouse" << file << value;
            }
        }
};

int main() {
 return 0;
}

