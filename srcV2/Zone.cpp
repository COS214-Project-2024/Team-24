#include "Zone.h"
#include <iostream>
#include <algorithm>

Zone::Zone(const std::string& name, const Point& location, int size)
    : name(name), location(location), size(size) {}

Zone::~Zone() {
    for (Building* building : buildings) {
        delete building;
    }
    buildings.clear();
}

bool Zone::addBuilding(Building* building) {
    if (!canAcceptBuilding(building)) {
        return false;
    }
    
    buildings.push_back(building);
    return true;
}

bool Zone::removeBuilding(Building* building) {
    auto it = std::find(buildings.begin(), buildings.end(), building);
    if (it != buildings.end()) {
        buildings.erase(it);
        return true;
    }
    return false;
}

void Zone::update() {
    for (Building* building : buildings) {
        building->update();
    }
}

void Zone::maintain() {
    for (Building* building : buildings) {
        building->maintain();
    }
}

void Zone::accept(BuildingVisitor* visitor) {
    for (Building* building : buildings) {
        building->accept(visitor);
    }
}

bool Zone::canAcceptBuilding(const Building* building) const {
    if (!building) {
        return false;
    }

    // Check zone type compatibility first
    if (!isCompatibleWith(building)) {
        return false;
    }

    // Then check position and capacity
    if (!isValidPosition(building->getLocation())) {
        return false;
    }

    if (isFull()) {
        return false;
    }

    // Check for overlapping buildings
    const Point& newLocation = building->getLocation();
    for (const Building* existingBuilding : buildings) {
        const Point& existingLocation = existingBuilding->getLocation();
        if (existingLocation.getX() == newLocation.getX() &&
            existingLocation.getY() == newLocation.getY()) {
            return false;
        }
    }

    return true;
}

bool Zone::isValidPosition(const Point& position) const {
    return position.getX() >= 0 && position.getX() < size &&
           position.getY() >= 0 && position.getY() < size;
}

bool Zone::isCompatibleWith(const Building* building) const {
    if (!building) return false;
    
    // If it's a mixed zone, accept any building
    if (zoneType == "Mixed") return true;
    
    // Check building type matches zone type
    if (building->getBuildingType() == "Residential" && zoneType == "Residential") return true;
    if (building->getBuildingType() == "Commercial" && zoneType == "Commercial") return true;
    if (building->getBuildingType() == "Industrial" && zoneType == "Industrial") return true;
    if (building->getBuildingType() == "Landmark") return true;  // Landmarks can go anywhere
    
    return false;
}