/*
* Author: Zach Thompson
* Date: 1/31/22
* Description: Practicing the creation and design of classes in C++
*/

#include <iostream>
#include <string>

// mySpace::yourSpace::myClass

namespace mySpace {
    namespace yourSpace {
        class myClass {
            public: // can be accessed globally

                // construct myClass with a name and initial number of students, or just name
                myClass(std::string name, int init_num_students);
                myClass(std::string name);

                int get_num_students();
                std::string get_name();
                void set_num_students(int num);

            private: // protected items
                int num_students;
                std::string className;
        };
    }  
}