#ifndef DEMOLISHCOMMAND_H
#define DEMOLISHCOMMAND_H

#include "Command.h"
#include "Building.h"
#include <iostream>

class DemolishCommand : public Command {
public:
    // Constructor taking parameters needed for the command
    DemolishCommand(Building* bld, Zone* zn);

    // Execute the demolish command
    void execute() override;

    // Undo the demolish command
    void undo() override;

~DemolishCommand();
private:
    Building* building;
    Zone* zone;
    BuildingState* previousState;  // we saving the old state so that when we want to undo we can get the building and zone back(use State Pattern)
};

#endif // DEMOLISHCOMMAND_H
