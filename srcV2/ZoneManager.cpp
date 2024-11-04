#include "ZoneManager.h"
#include <algorithm>

ZoneManager::ZoneManager() {}

ZoneManager::~ZoneManager() {
    for (Zone* zone : zones) {
        delete zone;
    }
    zones.clear();
}

Zone* ZoneManager::createZone(const std::string& name, const Point& location, int size) {
    Zone* zone = new Zone(name, location, size);
    zones.push_back(zone);
    return zone;
}

bool ZoneManager::removeZone(Zone* zone) {
    auto it = std::find(zones.begin(), zones.end(), zone);
    if (it != zones.end()) {
        delete *it;
        zones.erase(it);
        return true;
    }
    return false;
}

Zone* ZoneManager::findZone(const std::string& name) const {
    for (Zone* zone : zones) {
        if (zone->getName() == name) {
            return zone;
        }
    }
    return nullptr;
}

Zone* ZoneManager::findCompatibleZone(const Building* building) const {
    for (Zone* zone : zones) {
        if (zone && zone->canAcceptBuilding(building)) {
            return zone;
        }
    }
    return nullptr;
}

bool ZoneManager::placeBuilding(Building* building, Zone* zone) {
    if (!building || !zone) {
        return false;
    }
    return zone->addBuilding(building);
}

void ZoneManager::update() {
    for (Zone* zone : zones) {
        zone->update();
    }
}