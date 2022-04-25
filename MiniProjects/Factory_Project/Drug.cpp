#include "drug.hpp"

/*
* Author: Zach Thompson
* Date: 4/19/20
* Description: Defines functions in drugs.hpp
*/

Drug::Drug(std::string name, std::vector<Ingredient>* ingredientList, int quantity) {
    this->name = name;
    this->ingredients = ingredientList;
    this->quantity = quantity;
}

class Candy : public Drug {
    public:
        Candy() : Drug("Jolly Rancher", ingredients, 0) {

            // initialize ingredient vector
            std::vector<Ingredient>* ingredients;

            // add protected ingredients to ingredient list
            ingredients->push_back(Sugar()); /*
            ingredients->push_back(corn_syrup);
            ingredients->push_back(starch);
            ingredients->push_back(oil);
            ingredients->push_back(citric_acid);
            ingredients->push_back(coloring);
            */
        }

        std::string getName() override {
            return this->name;
        }

        std::vector<Ingredient>* getIngredients() override {
            return this->ingredients;
        }

        int getQuantity() override {
            return this->quantity;
        }
        
        protected:
            class Sugar; /*
            Corn_Syrup corn_syrup;
            Starch starch;
            Oil oil;
            Citric_Acid citric_acid;
            Colorings colorings; */
};

int main() {
    return 0;
}