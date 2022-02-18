#include "thompsonz_miniproject0.hpp"
/*
* Author: Zach Thompson
* Date: 2/18/22
* Description: Hacking time
*/

hackerSpace::TimeHacking::TimeHacking(std::string objectToHack) {
    this->objectToHack = objectToHack;
}

void hackerSpace::TimeHacking::setTimeToHack(int seconds) {
    this->time_to_hack = seconds;
}

int hackerSpace::TimeHacking::getTimeToHack() {
    return time_to_hack;
}

std::string hackerSpace::TimeHacking::getObjectToHack() {
    return this->objectToHack;
}

void hackerSpace::TimeHacking::hackTime() {
    sleep(this->time_to_hack);
    std::cout << "Hacking complete\n";
    return;
}

int main(int argc, char* argv[]) {
    std::string temp_object;
    int temp_time;

    std::cout << "What do you want to hack?\n";
    std::cin >> temp_object;
    std::cout << "How long do you want to hack it?\n";
    std::cin >> temp_time;

    hackerSpace::TimeHacking TimeHackings(temp_object);
    TimeHackings.setTimeToHack(temp_time);

    std::cout << "You are hacking " << TimeHackings.getObjectToHack() << " for " << TimeHackings.getTimeToHack() << " seconds\n";
    TimeHackings.hackTime();
}