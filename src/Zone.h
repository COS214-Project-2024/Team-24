#ifndef ZONE_H
#define ZONE_H

#include "Building.h"
#include <iostream>
#include <vector>

class Zone{
    private:
        std::string type;
        std::vector<Building*> buildings;
        int capacity;
        Point location;

    public:
        bool addBuilding(Building* building);

        void removeBuilding(Building* building);

        bool isCompatible(Building* building);
};

#endif