#include "UnderMaintenance.h"

/**
 * @class UnderMaintenance
 * @brief Represents the state of a building that is currently under maintenance.
 *
 * The UnderMaintenance class manages the maintenance process of a building,
 * including tracking maintenance progress and handling resource costs.
 */
UnderMaintenance::UnderMaintenance() : maintenanceProgress(0), maintenanceCostPerTick(15) {}

/**
 * @brief Enters the maintenance state for the specified building.
 * 
 * This method initializes the maintenance process and adds resources
 * for maintenance to the resource manager.
 *
 * @param building Pointer to the Building object that is under maintenance.
 */
void UnderMaintenance::enter(Building* building) {
    std::cout << "Building type: " << building->getBuildingType() << " is now under maintenance." << std::endl;
    building->getResourceManager()->addResources("maintenance", maintenanceCostPerTick);
}

/**
 * @brief Exits the maintenance state for the specified building.
 * 
 * This method is called when maintenance is complete and the building
 * transitions to an operational state.
 *
 * @param building Pointer to the Building object that has completed maintenance.
 */
void UnderMaintenance::exit(Building* building) {
    std::cout << "Maintenance complete for building type: " << building->getBuildingType() << std::endl;
}

/**
 * @brief Updates the maintenance progress for the specified building.
 * 
 * This method checks for resource availability, consumes resources, and
 * updates the maintenance progress. If progress reaches 100%, it changes
 * the building's state to operational.
 *
 * @param building Pointer to the Building object being maintained.
 */
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
