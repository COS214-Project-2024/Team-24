#include "Abandoned.h"
#include <iostream>

void Abandoned::enter(Building* building) {
    if (building) {
        std::cout << "Building entering abandoned state" << std::endl;
        // Set building properties for abandoned state
        building->setCondition(0.2);  // Poor condition
    }
}

void Abandoned::exit(Building* building) {
    if (building) {
        std::cout << "Building exiting abandoned state" << std::endl;
        // Clean up or reset any abandoned state specific properties
    }
}

void Abandoned::update(Building* building) {
    if (building) {
        std::cout << "Updating abandoned building" << std::endl;
        // Decrease condition over time
        double currentCondition = building->getCondition();
        building->setCondition(currentCondition * 0.95);  // Deteriorate by 5%
    }
}

std::string Abandoned::getStateName() const {
    return "Abandoned";
} 