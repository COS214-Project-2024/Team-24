#include "Operational.h"



     Operational::Operational() : resourceConsumptionRate(5), maintenanceThreshold(100), wearAndTear(0) {}

    void  Operational::enter(Building* building)  {
        std::cout << "Building type: " << building->getBuildingType() << " is now operational." << std::endl;
    }

    void  Operational::exit(Building* building) {
        std::cout << "Building type: " << building->getBuildingType() << " is no longer operational." << std::endl;
    }

    void  Operational::update(Building* building) {
        if (!building->getResourceManager()->checkResourceAvailability()) {
            std::cerr << "Insufficient resources for operation." << std::endl;
            return;
        }

        building->getResourceManager()->consumeResources();
        wearAndTear += 5;  // Increase wear and tear with each update

        if (wearAndTear >= maintenanceThreshold) {
            building->setState(new UnderMaintenance());
        }
    }

