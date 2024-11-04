#include "Waste.h"
#include "ResourceManager.h"
#include <iostream>

Waste::Waste(ResourceManager* manager) : ResourceState(manager) {
    efficiency = 1.0;
    capacity = 1.0;
    stable = true;
}

void Waste::enter() {
    std::cout << "Entering Waste state" << std::endl;
}

void Waste::exit() {
    std::cout << "Exiting Waste state" << std::endl;
}

void Waste::update() {
    // Update capacity based on consumption
    if (getConsumptionRate() > 0.8) {
        capacity -= 0.1;
        if (capacity < 0.2) stable = false;
    } else {
        capacity = std::min(1.0, capacity + 0.05);
        stable = true;
    }
    
    // Update efficiency based on capacity
    efficiency = capacity;
}

double Waste::getEfficiency() const {
    return efficiency;
}

bool Waste::isStable() const {
    return stable;
}

bool Waste::needsMaintenance() const {
    return capacity < 0.3 || efficiency < 0.3;
}

bool Waste::canDistribute() const {
    return capacity > 0.1 && efficiency > 0.2;
}

double Waste::getConsumptionRate() const {
    return 1.0 - capacity;
} 