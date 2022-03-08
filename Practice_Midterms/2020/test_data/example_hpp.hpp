/*
* 
* This is an example of some aspects of C++.
* For a general reference of C++ functions, you can go here: http://www.cplusplus.com/reference/
* And for a modern style guide (though certainly not the only one), you can refer to Google's
* Style Guide, here: https://google.github.io/styleguide/cppguide.html
* @author: Robert F Cooper
* @created: 12/19/19
* @version: 1.0
*/
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>

// Our project/class namespace.
// It is important to keep a unique name (or nest the namespaces)
// so that we do not have namespace collisons.
namespace DrCSpace{

    class myClass{
        public:
            myClass(std::string name);

            /* This function does a thing on a standard vector of doubles.
            // In this case, the thing it does is sum the data vector.
            // @param data: a vector of double data we wish to sum
            // @return: the Sum of the data.
			 */
            double do_a_thing(std::vector<double> data);
            
            // A setter for the class variable name
     	    // We can (and sometimes should go into more detail if it was more complex.)
            // @param new_name: The desired new name of the class.
            void set_name(std::string new_name);

            // A getter for the class variable name
            // @return: the current name of the class.
            std::string get_name();
        
        private:
            // The name of the class.
            std::string name;
    };

}
