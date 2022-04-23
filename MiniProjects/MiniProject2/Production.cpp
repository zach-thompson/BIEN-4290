#include "drugfactory.hpp"
#include <iostream>
#include <stdlib.h>
#include <sys/file.h>
#include <stdio.h>
/*
* Author: Group 5
* Date: 4/20/22
* Description: Accesses public warehouse to gather ingredients to make drugs in a drug factory
*/

Drug::Candy();

int main (int argc, char* argv[]) { // argument should be path to warehouse
    std::string path = argv[1];
    Factory : DrugFactory(path) {}

    // intialize ingredientList to access all ingredients
    // Sugar.getPath()
    // access specific warehouse
    // lock file
    // decrement truck value
    // wait 1 second
    // Sugar.setQuantity(1)
    // wait 1 second
    // increment truck value
    // unlock file
    // do same for all remaining ingredients
    // once all ingredients getQuantity() > 1, makeDrug()
    // shipDrug()
    // repeat

    // locking/unlocking procedure
    int fd = fileno(path));
    flock(fd, lock_ex());
    // deal with file
    flock(fd, lock_un());

    return 0;
}