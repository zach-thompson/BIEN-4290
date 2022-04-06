#include <iostream>
#include <memory>
#include <vector>

class Topping {
    public:
    Topping(std::string topping_name, std::string topping_type) {
        name = topping_name;
        type = topping_type;
    }

    std::string getName() const{
        return name;
    }

    std::string getType() const{
        return type;
    }

    virtual std::string tastesLike() = 0; // a statement of taste...

    private:
        std::string name;
        std::string type;

};

class Pickle : public Topping{
    public:
        Pickle() : Topping("Pickle", "Vegetable") {
            snap();
        }

    void snap() {
        std::cout << "Snappin'!";
    }

    std::string tastesLike() override {
        return "briney excellence";
    }
};

class Carrot : public Topping{
    public:
        Carrot() : Topping("Carrot", "Vegetable") {

        }

        std::string tastesLike() override {
            return "pickled dirt";
        }
};

class Olive : public Topping {
    public:
        Olive() : Topping("Olive", "Vegetable") {

        }

        std::string tastesLike() override {
            return "briney";
        }
};