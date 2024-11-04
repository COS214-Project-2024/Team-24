#ifndef DEMOLISHCOMMAND_H
#define DEMOLISHCOMMAND_H

#include "Command.h"
#include "Building.h"
#include <iostream>

/**
 * @class DemolishCommand
 * @brief Command to demolish a building within a specified zone, with undo functionality.
 *
 * The DemolishCommand class handles the demolition of a building, updating 
 * the zone accordingly and allowing the operation to be undone by restoring 
 * the building's previous state.
 */
class DemolishCommand : public Command {
public:
    /**
     * @brief Constructs a DemolishCommand with the given building and zone.
     * @param bld Pointer to the Building to be demolished.
     * @param zn Pointer to the Zone where the building is located.
     *
     * Initializes the command with a target building and its associated zone.
     * Saves the previous state of the building to allow the operation to be undone.
     */
    DemolishCommand(Building* bld, Zone* zn);

    /**
     * @brief Executes the demolish command.
     *
     * Demolishes the building, removes it from the specified zone, 
     * and prints a message confirming the operation.
     */
    void execute() override;

    /**
     * @brief Undoes the demolish command.
     *
     * Restores the building to its previous state, re-adding it to the zone 
     * and printing a message confirming the restoration. If no previous state 
     * is found, an error message is displayed.
     */
    void undo() override;

    /**
     * @brief Destructor to clean up resources, including previous state.
     */
    ~DemolishCommand();

private:
    Building* building;           ///< Pointer to the building being demolished.
    Zone* zone;                   ///< Pointer to the zone containing the building.
    BuildingState* previousState; ///< Saves the building's previous state to enable undo functionality.
};

#endif // DEMOLISHCOMMAND_H
