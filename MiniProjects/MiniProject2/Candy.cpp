#include "drug.hpp"

/*
* Author: Zach Thompson
* Date: 4/19/20
* Description: Class should inherit from drug.hpp to make a candy (Jolly Rancher Gummy)
*/

class JollyRancher : public Drug(std::string name, std::vector<Ingredient>* ingredientList)
    public:
        JollyRancher() : Drug("Jolly Rancher", ingredientList) {

            // add private ingredients to ingredient list
            ingredientList.push_back(&sugar);
            ingredientList.push_back(&corn_syrup);
            ingredientList.push_back(&starch);
            ingredientList.push_back(&oil);
            ingredientList.push_back(&citric_acid);
            ingredientList.push_back(&colorings);
        }

        std::string getName() override { // "override" not required, but ensures that the thing begin overwritten exists
            return this.name;
        }

        std::vector<Topping*>& getIngredients() override {
            return this.ingredientList;
        }

        private:
            Ingredient sugar;
            Ingredient corn_syrup;
            Ingredient starch
            Ingredient oil
            Ingredient citric_acid
            Ingredient colorings
};