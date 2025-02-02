#include "ingredient.hpp"
/*
* Author: Grace Gibson
* Date: 4/20/2022
* Description: Implementation for non virtual functions in ingredients.hpp
*/

Ingredient::Ingredient(std::string name, int quantity, std::string path) {
	this->name = name;
	this->quantity = quantity;
	this->path = path;
}

Ingredient::Ingredient(std::string name, std::string path) {
	this->name = name;
	this->path = path;
}

//sub classes inheritance 
class Sugar : public Ingredient {
	public:
		Sugar() : Ingredient("sugar", "~/Factory_Project/warehouse/sugar") {
				// stuff
        }
		
        std::string getName() override {
			return this->name;
		}

		std::string getPath() override {
			return this->path;
		}

		int getQuantity() override {
			return this->quantity;
		}

		void setQuantity(int quantity) override {
			this->quantity = quantity;
		}
};

class Corn_Syrup : public Ingredient {
	public:
		Corn_Syrup() : Ingredient("corn syrup", "~/Factory_Project/warehouse/corn_syrup") {

        }
		
        std::string getName() override {
			return this->name;
		}

		std::string getPath() override {
			return this->path;
		}

		int getQuantity() override {
			return this->quantity;
		}

		void setQuantity(int quantity) override {
			this->quantity = quantity;
		}
};

class Starch : public Ingredient {
	public:
		Starch() : Ingredient("starch", "~/Factory_Project/warehouse/starch") {

        }
		
        std::string getName() override {
			return this->name;
		}

		std::string getPath() override {
			return this->path;
		}

		int getQuantity() override {
			return this->quantity;
		}

		void setQuantity(int quantity) override {
			this->quantity = quantity;
		}
};

class Oil : public Ingredient {
	public:
		Oil() : Ingredient("oil", "~/Factory_Project/warehouse/oil") 

        }
		
        std::string getName() override {
			return this->name;
		}

		std::string getPath() override {
			return this->path;
		}

		int getQuantity() override {
			return this->quantity;
		}

		void setQuantity(int quantity) override {
			this->quantity = quantity;
		}
};

class Citric_Acid : public Ingredient {
	public:
		Citric_Acid() : Ingredient("citric acid", "~/Factory_Project/warehouse/citric_acid") {

        }
		
        std::string getName() override {
			return this->name;
		}

		std::string getPath() override {
			return this->path;
		}

		int getQuantity() override {
			return this->quantity;
		}

		void setQuantity(int quantity) override {
			this->quantity = quantity;
		}
};

class Colorings : public Ingredient {
	public:
		Colorings() : Ingredient("colorings", "~/Factory_Project/warehouse/colorings") {
            
        }
		
        std::string getName() override {
			return this->name;
		}

		std::string getPath() override {
			return this->path;
		}

		int getQuantity() override {
			return this->quantity;
		}

		void setQuantity(int quantity) override {
			this->quantity = quantity;
		}
};

int main() {
    return 0;
}