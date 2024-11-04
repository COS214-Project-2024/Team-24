#include "Operational.h"

/**
 * @brief Constructs an Operational state with default values.
 *
 * Initializes resource consumption rate to 5, maintenance threshold to 100,
 * and wear and tear to 0.
 */
Operational::Operational() : resourceConsumptionRate(5), maintenanceThreshold(100), wearAndTear(0) {}

/**
 * @brief Enters the Operational state for a building.
 * @param building Pointer to the Building entering this state.
 *
 * Outputs a message indicating the building type and that it is now operational.
 */
void Operational::enter(Building* building) {
    std::cout << "Building type: " << building->getBuildingType() << " is now operational." << std::endl;
}

/**
 * @brief Exits the Operational state for a building.
 * @param building Pointer to the Building exiting this state.
 *
 * Outputs a message indicating the building type and that it is no longer operational.
 */
void Operational::exit(Building* building) {
    std::cout << "Building type: " << building->getBuildingType() << " is no longer operational." << std::endl;
}

/**
 * @brief Updates the Operational state of the building.
 * @param building Pointer to the Building being updated.
 *
 * Checks if resources are available; if so, consumes resources and increases wear and tear.
 * Transitions to UnderMaintenance state if wear and tear reaches the maintenance threshold.
 */
void Operational::update(Building* building) {
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
