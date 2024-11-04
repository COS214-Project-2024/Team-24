#include "BuildCommand.h"

/**
 * @class BuildCommand
 * @brief Implements a command to build or demolish a structure within a specific zone.
 * 
 * The BuildCommand class allows constructing a building within a designated zone
 * and provides functionality to undo the construction by demolishing the building.
 */

/**
 * @brief Constructs a BuildCommand with a target building and zone.
 * @param bld Pointer to the Building to be constructed.
 * @param zn Pointer to the Zone where the building will be placed.
 */
BuildCommand::BuildCommand(Building *bld, Zone *zn) : building(bld), zone(zn) {}

/**
 * @brief Reverts the build action, demolishing the building and removing it from the zone.
 * 
 * This method undoes the build command by calling the demolish method on the building
 * and removing the building from the specified zone.
 */
void BuildCommand::undo() {
    building->demolish();
    zone->removeBuilding(building);
    std::cout << "Building is removed from zone " << zone->getType() << std::endl;
}

/**
 * @brief Executes the build action, attempting to place and construct the building within the zone.
 * 
 * If the zone can accommodate the building, the building is constructed, and a confirmation message is printed.
 * If not, an error is displayed indicating failure due to capacity or compatibility issues.
 */
void BuildCommand::execute() {
    if (zone->addBuilding(building)) {
        building->build();
        std::cout << "Building constructed in zone " << zone->getType() << std::endl;
    } else {
        std::cerr << "Failed to construct the Building: The Zone capacity is full or incompatible." << std::endl;
    }
}
