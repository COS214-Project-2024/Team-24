#ifndef CITY_MANAGER_H
#define CITY_MANAGER_H

#include <string>
#include "ZoneManager.h"

class CityManager {
public:
    CityManager(const std::string& name);
    ~CityManager();

    // Basic getters
    std::string getName() const { return name; }
    ZoneManager* getZoneManager() const { return zoneManager; }

    // Zone management (delegates to ZoneManager)
    Zone* createZone(const std::string& name, const Point& location, int size);
    Zone* findZone(const std::string& name) const;
    bool placeBuilding(Building* building, Zone* zone);

    // Updates
    void update();

private:
    std::string name;
    ZoneManager* zoneManager;
};

#endif
