#include "UnderMaintenance.h"
#include "Operational.h"
#include <iostream>

void UnderMaintenance::enter(Building* building) {
    if (building) {
        std::cout << "Building entering maintenance state" << std::endl;
        repairProgress = 0.0;
    }
}

void UnderMaintenance::update(Building* building) {
    if (!building) return;

    timeRemaining--;
    updateProgress();
    
    // Gradually improve building condition during maintenance
    double currentCondition = building->getCondition();
    double improvement = (1.0 - currentCondition) / maintenanceDuration;
    building->setCondition(currentCondition + improvement);

    if (isMaintenanceComplete()) {
        std::cout << "Maintenance complete!" << std::endl;
        building->setState(std::make_unique<Operational>(building));
    } else {
        std::cout << "Maintenance progress: " 
                  << (repairProgress * 100.0) << "%" << std::endl;
    }
}

void UnderMaintenance::exit(Building* building) {
    if (building) {
        std::cout << "Building completed maintenance" << std::endl;
        // Ensure building is in good condition after maintenance
        building->setCondition(1.0);
    }
}

void UnderMaintenance::updateProgress() {
    repairProgress = 1.0 - (static_cast<double>(timeRemaining) / maintenanceDuration);
    if (repairProgress > 1.0) repairProgress = 1.0;
    if (repairProgress < 0.0) repairProgress = 0.0;
}

bool UnderMaintenance::isMaintenanceComplete() const {
    return timeRemaining <= 0;
} 
