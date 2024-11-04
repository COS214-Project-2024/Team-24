#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include <iostream>
#include "Command.h"
#include "Building.h"

class BuildCommand : public Command {
public:
    // Constructor taking parameters needed for the command
    BuildCommand(Building* bld, Zone* zn);

    // Execute the build command
    void execute() override;

    // Undo the build command
    void undo() override;

private:
    // Member variables related to the build command, e.g., a pointer to the building
    // Building* building;
     Building* building;
    Zone* zone; 
};

#endif // BUILDCOMMAND_H
