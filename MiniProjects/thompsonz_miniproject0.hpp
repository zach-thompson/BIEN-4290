/*
* Author: Zach Thompson
* Date: 2/18/22
* Description: Miniproject0 header file
*/

#ifndef HACKED
#define HACKED

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

namespace hackerSpace {
    class TimeHacking {
        public:

            TimeHacking(std::string objectToHack);

            void setTimeToHack(int seconds);
            int getTimeToHack();
            std::string getObjectToHack();
            void hackTime();

        private:
            int time_to_hack;
            std::string objectToHack;
    };
}

#endif