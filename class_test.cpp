#include "class_test.hpp"

// to build a constructor - point is to construct object (initialization process)
mySpace::yourSpace::myClass::myClass(std::string name, int init_num_students) {
    // duplicate myClass to establish constructor
    this->className = name;
    this->num_students = init_num_students;
}

// passing a reference
std::vector<std::string>* mySpace::yourSpace::myClass::get_classlist() {
    return &(this->classlist);
}

int mySpace::yourSpace::myClass::get_num_students() {

    return this->num_students;
}

// might be useful for lab1
int main() {

    mySpace::yourSpace::myClass myclassy("BIEN4290");

    myclassy.get_num_students();
}