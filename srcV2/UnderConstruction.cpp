#include "UnderConstruction.h"
#include "Operational.h"
#include <iostream>

void UnderConstruction::enter(Building* building) {
    if (building) {
        std::cout << "Building entering construction state" << std::endl;
        building->setCondition(0.0);  // Start with 0 condition
    }
}

void UnderConstruction::exit(Building* building) {
    if (building) {
        std::cout << "Building completed construction" << std::endl;
        building->setCondition(1.0);  // Completed construction is perfect condition
    }
}

void UnderConstruction::update(Building* building) {
    if (!building) return;

    timeRemaining--;
    updateProgress();
    
    if (isConstructionComplete()) {
        std::cout << "Construction complete!" << std::endl;
        building->setState(std::make_unique<Operational>(building));
    } else {
        std::cout << "Construction progress: " 
                  << (constructionProgress * 100.0) << "%" << std::endl;
    }
}

void UnderConstruction::updateProgress() {
    constructionProgress = 1.0 - (static_cast<double>(timeRemaining) / constructionTime);
    if (constructionProgress > 1.0) constructionProgress = 1.0;
    if (constructionProgress < 0.0) constructionProgress = 0.0;
}

bool UnderConstruction::isConstructionComplete() const {
    return timeRemaining <= 0;
} 