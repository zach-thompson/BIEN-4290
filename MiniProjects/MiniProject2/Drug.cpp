#include "drug.hpp"

/*
* Author: Zach Thompson
* Date: 4/19/20
* Description: Class should inherit from drug.hpp to make a candy (Jolly Rancher Gummy)
*/

Drug::Drug(std::string name, std::vector<Ingredient>* ingredientList) {
    this->name = name;
    this->ingredients = ingredientList;
}

class Candy : public Drug {
    public:
        Candy() : Drug("Jolly Rancher", ingredients) {

            // add private ingredients to ingredient list
            ingredients.push_back(&sugar); /*
            ingredientList.push_back(&corn_syrup);
            ingredientList.push_back(&starch);
            ingredientList.push_back(&oil);
            ingredientList.push_back(&citric_acid);
            ingredientList.push_back(&colorings); */
        }

        std::string getName() override {
            return this->name;
        }

        std::vector<Ingredient>* getIngredients() override {
            return ingredients;
        }
        
        protected:
            Sugar sugar; /*
            Corn_Syrup corn_syrup;
            Starch starch;
            Oil oil;
            Citric_Acid citric_acid;
            Colorings colorings; */
};

int main() {
    return 0;
}