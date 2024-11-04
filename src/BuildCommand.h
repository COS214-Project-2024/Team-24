#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include <iostream>
#include "Command.h"
#include "Building.h"

/**
 * @class BuildCommand
 * @brief Command class for handling the construction and demolition of a building within a zone.
 * 
 * The BuildCommand class provides methods to execute a building operation and to undo it,
 * implementing a command pattern for flexible operation management.
 */
class BuildCommand : public Command {
public:
    /**
     * @brief Constructs a BuildCommand with a specified building and zone.
     * @param bld Pointer to the Building object to be constructed.
     * @param zn Pointer to the Zone object where the building will be constructed.
     */
    BuildCommand(Building* bld, Zone* zn);

    /**
     * @brief Executes the build command by attempting to add and construct the building in the zone.
     * 
     * If the zone has available capacity and is compatible, the building is added and constructed.
     */
    void execute() override;

    /**
     * @brief Undoes the build command, removing and demolishing the building from the zone.
     */
    void undo() override;

private:
    Building* building; ///< Pointer to the building that will be constructed or demolished.
    Zone* zone; ///< Pointer to the zone where the building operation occurs.
};

#endif // BUILDCOMMAND_H
