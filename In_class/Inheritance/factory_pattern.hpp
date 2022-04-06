#include <iostream>
#include <memory>
#include <vector>
#include "topping.hpp"

/*
* This header file is designed to show:
* - The "Factory" programming pattern
* - Inheritance in C++ (class extension)
* - Polymorphism
* - "fancy ass" C++ programming
*/

enum Bloodies{Hollander, Southsider, Milwaukeean, Spicy_Badger};

class BloodyMary{
        public:
            BloodyMary(std::string name, std::string liquor) {
                // stuff
            }

            // static type - associated with class, but doesn't require an instance
            static BloodyMary* makeDrink(Bloodies); // Key factory function - return object of given type

            virtual void mix() = 0; // Pure virtual function, MUST define this function to inherit from BloodyMary
            
            virtual std::string chaser() = 0;

            virtual std::vector<Topping*>& getToppingList() = 0; // '&' means return instance of, pointer to toppingList

            std::string getName() {
                return drink_name;
            }

            std::string getLiquor() {
                return liquor_type;
            }

        // Protected only lets subclasses (classes that inherit from this) access things in here
        protected:
            std::vector<Topping*> toppingList;

        private:
            std::string drink_name;
            std::string liquor_type;
};

class Hollander : public BloodyMary { // How to entail inheritance in C++
    public:
        Hollander(int price) : BloodyMary("The Hollander", "Prairie Vodka") {
            my_price = price;

            // add private toppings to topping list
            toppingList.push_back(&pickle);
            toppingList.push_back(&carrot);
            toppingList.push_back(&olive);
        }

        void mix() override { // "override" not required, but ensures that the thing begin overwritten exists
            std::cout << "Shaking together the ..."; // add toppings?
        }

        std::string chaser() override {
            std::cout << "Chasing this with High Life";
        }

        std::vector<Topping*>& getToppingList() override {
            return toppingList;
        }

        private:
            int my_price;
            Pickle pickle;
            Carrot carrot;
            Olive olive;
};