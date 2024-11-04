#include "Sewage.h"
#include "ResourceManager.h"
#include <iostream>

Sewage::Sewage(ResourceManager* manager) : ResourceState(manager) {
    efficiency = 1.0;
    flowRate = 1.0;
    stable = true;
}

void Sewage::enter() {
    std::cout << "Entering Sewage state" << std::endl;
}

void Sewage::exit() {
    std::cout << "Exiting Sewage state" << std::endl;
}

void Sewage::update() {
    // Update flow rate based on consumption
    if (getConsumptionRate() > 0.8) {
        flowRate -= 0.1;
        if (flowRate < 0.3) stable = false;
    } else {
        flowRate = std::min(1.0, flowRate + 0.05);
        stable = true;
    }
    
    // Update efficiency based on flow rate
    efficiency = flowRate;
}

double Sewage::getEfficiency() const {
    return efficiency;
}

bool Sewage::isStable() const {
    return stable;
}

bool Sewage::needsMaintenance() const {
    return flowRate < 0.3 || efficiency < 0.3;
}

bool Sewage::canDistribute() const {
    return flowRate > 0.2 && efficiency > 0.2;
}

double Sewage::getConsumptionRate() const {
    return 1.0 - flowRate;
} 