#include "UnderConstruction.h"

/**
 * @class UnderConstruction
 * @brief Represents the under construction state of a building.
 *
 * This class manages the construction process of a building,
 * tracking the progress and cost associated with construction.
 */
UnderConstruction::UnderConstruction() : constructionProgress(0), constructionCostPerTick(10) {}

/**
 * @brief Enters the under construction state for the specified building.
 * 
 * This method initializes the construction process for a given building.
 * It informs the resource manager to add resources for construction.
 * 
 * @param building Pointer to the Building object that is under construction.
 */
void UnderConstruction::enter(Building* building)  {
    std::cout << "Building type: " << building->getBuildingType() << " is now under construction." << std::endl;
    building->getResourceManager()->addResources("construction", constructionCostPerTick);
}

/**
 * @brief Exits the under construction state for the specified building.
 * 
 * This method is called when the construction of a building is complete,
 * transitioning the building state to operational.
 * 
 * @param building Pointer to the Building object that has completed construction.
 */
void UnderConstruction::exit(Building* building)  {
    std::cout << "Construction complete for building type: " << building->getBuildingType() << std::endl;
}

/**
 * @brief Updates the construction progress for the specified building.
 * 
 * This method checks for resource availability, consumes resources,
 * and updates the construction progress. If the progress reaches 100%,
 * it transitions the building state to operational.
 * 
 * @param building Pointer to the Building object being constructed.
 */
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
