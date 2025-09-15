#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <vector>
#include <string>
#include "Motorbike.h"

class Guest {
private:
    std::vector<Motorbike> motorbikes;
public:
    //constructor
    Guest();

    // Load motorbikes from file into vector
    bool loadMotorbikes(const std::string& filename);

    // display general motorbike listings for guest role
    void list();
};

#endif
