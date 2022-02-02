/*
* Author: Zach Thompson
* Date: 1/31/22
* Description: Practicing the creation and design of classes in C++
*/

#include <iostream>
#include <string>
#include <vector>

// mySpace::yourSpace::myClass

namespace mySpace {
    namespace yourSpace {
        class myClass {
            public: // can be accessed globally

                // construct myClass object with a name and initial number of students, or just name
                myClass(std::string name, int init_num_students);
                myClass(std::string name);
                myClass();
                ~myClass(); // destructor, look into this

                int get_num_students();
                std::string get_name();
                void set_num_students(int num);
                void set_name(std::string newname);
                std::vector<std::string>* get_classlist();

            private: // protected items
                int num_students;
                std::string className;
                std::vector<std::string> classlist;
        };
    }  
}