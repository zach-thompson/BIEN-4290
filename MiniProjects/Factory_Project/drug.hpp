#include "ingredient.hpp"
#include <vector>

class Drug {    
    public:
        Drug(std::string name, std::vector<Ingredient>* ingredientList, int quantity);

        virtual std::string getName() = 0;
        virtual std::vector<Ingredient>* getIngredients() = 0;
        virtual int getQuantity() = 0;

    protected:
        std::string name;
        std::vector<Ingredient>* ingredients;
        int quantity;
};
