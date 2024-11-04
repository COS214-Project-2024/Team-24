#include "Power.h"
#include "ResourceManager.h"
#include <iostream>

Power::Power(ResourceManager* manager) : ResourceState(manager) {
    efficiency = 1.0;
    load = 0.0;
    stable = true;
}

void Power::enter() {
    std::cout << "Entering Power state" << std::endl;
}

void Power::exit() {
    std::cout << "Exiting Power state" << std::endl;
}

void Power::update() {
    // Update load based on consumption
    if (getConsumptionRate() > 0.8) {
        load += 0.1;
        if (load > 0.9) stable = false;
    } else {
        load = std::max(0.0, load - 0.05);
        stable = true;
    }
    
    // Update efficiency based on load
    efficiency = 1.0 - (load * 0.5);
}

double Power::getEfficiency() const {
    return efficiency;
}

bool Power::isStable() const {
    return stable;
}

bool Power::needsMaintenance() const {
    return load > 0.8 || efficiency < 0.3;
}

bool Power::canDistribute() const {
    return load < 0.9 && efficiency > 0.2;
}

double Power::getConsumptionRate() const {
    return load;
} 