#include "UnderMaintenance.h"


UnderMaintenance::UnderMaintenance() : maintenanceProgress(0), maintenanceCostPerTick(15) {}

    void UnderMaintenance::enter(Building* building) {
        std::cout << "Building type: " << building->getBuildingType() << " is now under maintenance." << std::endl;
        building->getResourceManager()->addResources("maintenance", maintenanceCostPerTick);
    }

    void UnderMaintenance::exit(Building* building) {
        std::cout << "Maintenance complete for building type: " << building->getBuildingType() << std::endl;
    }

    void UnderMaintenance::update(Building* building) {
        if (!building->getResourceManager()->checkResourceAvailability()) {
            std::cout << "Insufficient resources for maintenance." << std::endl;
            return;
        }

        building->getResourceManager()->consumeResources();
        maintenanceProgress += 20; // Progress maintenance by 20%

        if (maintenanceProgress >= 100) {
            building->setState(new Operational());
        }
    }