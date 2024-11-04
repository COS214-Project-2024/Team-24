#include "Operational.h"
#include "UnderMaintenance.h"
#include <iostream>

void Operational::enter(Building* building) {
    if (building) {
        std::cout << "Building entering operational state" << std::endl;
    }
}

void Operational::exit(Building* building) {
    if (building) {
        std::cout << "Building exiting operational state" << std::endl;
    }
}

void Operational::update(Building* building) {
    if (needsMaintenance() && building) {
        std::cout << "Building needs maintenance" << std::endl;
        building->setState(std::make_unique<UnderMaintenance>(building, 5));
    }
}

bool Operational::needsMaintenance() const {
    if (!ownerBuilding) return false;
    return ownerBuilding->getCondition() < maintenanceThreshold;
}