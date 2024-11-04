#ifndef ZONE_MANAGER_H
#define ZONE_MANAGER_H

#include <vector>
#include <string>
#include "Zone.h"
#include "Building.h"

class ZoneManager {
public:
    ZoneManager();
    ~ZoneManager();

    // Zone management
    Zone* createZone(const std::string& name, const Point& location, int size);
    bool removeZone(Zone* zone);
    Zone* findZone(const std::string& name) const;
    Zone* findCompatibleZone(const Building* building) const;
    
    // Building placement
    bool placeBuilding(Building* building, Zone* zone);
    
    // Updates
    void update();
    
    // Getters
    const std::vector<Zone*>& getZones() const { return zones; }

private:
    std::vector<Zone*> zones;
};

#endif
