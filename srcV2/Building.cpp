#include "Building.h"
#include "Zone.h"
#include "Citizen.h"
#include <algorithm>
#include <iostream>

Building::Building(const std::string& type, const Point& loc, int maxRes)
    : buildingType(type)
    , location(loc)
    , condition(1.0)
    , zone(nullptr)
    , resourceManager(ResourceManager::getInstance())
    , maxResidents(maxRes) {
}

void Building::setState(std::unique_ptr<BuildingState> newState) {
    if (currentState) {
        currentState->exit(this);
    }
    currentState = std::move(newState);
    if (currentState) {
        currentState->enter(this);
    }
}

bool Building::canAcceptResident() const {
    return residents.size() < static_cast<size_t>(maxResidents);
}


bool Building::addResident(Citizen* citizen) {
    if (!citizen || !canAcceptResident()) return false;
    
    residents.push_back(citizen);
    citizen->setResidence(this);
    return true;
}


void Building::removeResident(Citizen* citizen) {
    if (!citizen) return;
    
    auto it = std::find(residents.begin(), residents.end(), citizen);
    if (it != residents.end()) {
        (*it)->setResidence(nullptr);
        residents.erase(it);
    }
}

void Building::validateCondition() {
    if (condition < 0.0) condition = 0.0;
    if (condition > 1.0) condition = 1.0;
}

void Building::notifyResidents() {
    for (auto* resident : residents) {
        if (resident) {
            resident->notifyBuildingConditionChanged(this);
        }
    }
}

void Building::build() {
    if (!built) {
        built = true;
        condition = 1.0;
        std::cout << "Building constructed at (" 
                  << location.getX() << "," << location.getY() << ")" << std::endl;
    }
}

void Building::demolish() {
    if (built) {
        // Remove all residents
        for (auto* resident : residents) {
            if (resident) {
                resident->setResidence(nullptr);
            }
        }
        residents.clear();

        // Clear zone reference
        if (zone) {
            zone->removeBuilding(this);
        }
        zone = nullptr;

        built = false;
        condition = 0.0;
        std::cout << "Building demolished at (" 
                  << location.getX() << "," << location.getY() << ")" << std::endl;
    }
}

void Building::update() {
    if (built) {
        // Deteriorate condition over time
        condition = std::max(0.0, condition - 0.01);
    }
}

void Building::maintain() {
    // Improve condition through maintenance
    condition = std::min(1.0, condition + 0.1);
}