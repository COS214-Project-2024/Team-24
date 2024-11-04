#include "DemolishCommand.h"

/**
 * @brief Executes the demolish command, removing the building from the zone.
 *
 * This method saves the building's current state before demolition, demolishes 
 * the building, and removes it from the zone.
 */
void DemolishCommand::execute() {
    // Save the building's current state and resources before demolition
    previousState = building->getState();

    // Demolish the building and release resources
    building->demolish();
    zone->removeBuilding(building);
    std::cout << "Building is demolished and it is removed from zone " << zone->getType() << std::endl;
}

/**
 * @brief Destructor to clean up resources used by DemolishCommand.
 *
 * This destructor releases any saved state information, ensuring proper cleanup 
 * after the command is no longer needed.
 */
DemolishCommand::~DemolishCommand() {
    delete previousState;
}

/**
 * @brief Constructor for DemolishCommand, initializing building and zone references.
 * 
 * @param bld Pointer to the building to be demolished.
 * @param zn Pointer to the zone from which the building will be removed.
 * 
 * The constructor initializes pointers to the specified building and zone, and
 * sets up a nullptr for storing the building's previous state.
 */
DemolishCommand::DemolishCommand(Building* bld, Zone* zn) : building(bld), zone(zn), previousState(nullptr) {}

/**
 * @brief Reverts the demolish command, restoring the building's previous state.
 *
 * This method restores the building to its prior state if it exists, re-adding 
 * the building to the zone. If no previous state was found, an error message is displayed.
 */
void DemolishCommand::undo() {
    // Restore the building's previous state and resources
    if (previousState) {
        building->setState(previousState);
        zone->addBuilding(building);
        std::cout << "Building is restored to its previous state in zone " << zone->getType() << std::endl;
    } else {
        std::cerr << "Cannot undo: No previous state found." << std::endl;
    }
}
