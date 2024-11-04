#ifndef DEMOLISH_COMMAND_H
#define DEMOLISH_COMMAND_H

#include "Command.h"
#include "Building.h"
#include "Point.h"

/**
 * @class DemolishCommand
 * @brief Command for demolishing a specific building at a given location.
 *
 * The DemolishCommand class provides functionality to execute the demolition
 * of a building and undo the action, restoring the building as needed.
 */
class DemolishCommand : public Command {
public:
    /**
     * @brief Constructs a demolish command for a building at a specific position.
     * @param building Pointer to the building targeted for demolition.
     * @param position Location of the building to be demolished.
     */
    DemolishCommand(Building* building, const Point& position);

    /// Executes the demolition of the target building.
    void execute() override;

    /// Reverts the demolition, restoring the building.
    void undo() override;

private:
    Building* targetBuilding; ///< Pointer to the building being demolished.
    Point position;           ///< Location of the building.
};

#endif // DEMOLISH_COMMAND_H
