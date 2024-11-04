#include "Water.h"
#include "ResourceManager.h"
#include <iostream>

Water::Water(ResourceManager* manager) : ResourceState(manager) {
    efficiency = 1.0;
    pressure = 1.0;
    stable = true;
}

void Water::enter() {
    std::cout << "Entering Water state" << std::endl;
}

void Water::exit() {
    std::cout << "Exiting Water state" << std::endl;
}

void Water::update() {
    // Update pressure based on consumption
    if (getConsumptionRate() > 0.8) {
        pressure -= 0.1;
        if (pressure < 0.5) stable = false;
    } else {
        pressure = std::min(1.0, pressure + 0.05);
        stable = true;
    }
    
    // Update efficiency based on pressure
    efficiency = pressure;
}

double Water::getEfficiency() const {
    return efficiency;
}

bool Water::isStable() const {
    return stable;
}

bool Water::needsMaintenance() const {
    return pressure < 0.3 || efficiency < 0.3;
}

bool Water::canDistribute() const {
    return pressure > 0.2 && efficiency > 0.2;
}

double Water::getConsumptionRate() const {
    return 1.0 - efficiency;  // Higher efficiency means lower consumption
} 