#ifndef BUILDCOMMAND_H
#define BUILDCOMMAND_H

#include "Command.h"
#include "Building.h"
#include "Point.h"

class BuildCommand : public Command {
public:
    BuildCommand(Building* building, const Point& position)
        : Command("Build " + building->getBuildingType())
        , building(building)
        , position(position) {}

    void execute() override;
    void undo() override;

private:
    Building* building;
    Point position;
};

#endif