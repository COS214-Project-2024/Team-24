#include "CityManager.h"

CityManager::CityManager(const std::string& name) 
    : name(name), zoneManager(new ZoneManager()) {
}

CityManager::~CityManager() {
    delete zoneManager;
}

Zone* CityManager::createZone(const std::string& name, const Point& location, int size) {
    return zoneManager->createZone(name, location, size);
}

Zone* CityManager::findZone(const std::string& name) const {
    return zoneManager->findZone(name);
}

bool CityManager::placeBuilding(Building* building, Zone* zone) {
    return zoneManager->placeBuilding(building, zone);
}

void CityManager::update() {
    zoneManager->update();
}