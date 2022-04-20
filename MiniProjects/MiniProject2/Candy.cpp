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
            toppingList.push_back(&corn syrup);
        }

        std::string getName() override { // "override" not required, but ensures that the thing begin overwritten exists
            return name;
        }

        std::vector<Topping*>& getIngredients() override {
            return ingredientList;
        }

        private:
            Ingredient sugar;
            Ingredient corn syrup;
};