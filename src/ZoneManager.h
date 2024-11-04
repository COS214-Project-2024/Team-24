#ifndef ZONEMANAGER_H
#define ZONEMANAGER_H

#include <iostream>
#include <map>
#include <vector>
#include "Zone.h"
#include "Point.h"
#include "Building.h"

class ZoneManager{
    private:
        std::map<std::string, std::vector<Zone*>> zones;
        std::vector<std::string> zoneTypes;

    public:
        Zone* createZone(std::string type, Point* location);

        bool checkZoneRequirements(Building* building);

        std::vector<Zone*> getAvailableZones();
};

#endif