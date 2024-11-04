#include "UnderConstruction.h"




        UnderConstruction::UnderConstruction() : constructionProgress(0), constructionCostPerTick(10) {}

    void UnderConstruction::enter(Building* building)  {
        std::cout << "Building type: " << building->getBuildingType() << " is now under construction." << std::endl;
        building->getResourceManager()->addResources("construction", constructionCostPerTick);
    }

    void UnderConstruction::exit(Building* building)  {
        std::cout << "Construction complete for building type: " << building->getBuildingType() << std::endl;
    }

    void UnderConstruction::update(Building* building) {
        if (!building->getResourceManager()->checkResourceAvailability()) {
            std::cerr << "Insufficient resources for construction." << std::endl;
            return;
        }

        building->getResourceManager()->consumeResources();
        constructionProgress += 10; // Progress construction by 10%

        std::cout << "Construction progress: " << constructionProgress << "%" << std::endl;

        if (constructionProgress >= 100) {
            building->setState(new Operational());
        }
    }
    