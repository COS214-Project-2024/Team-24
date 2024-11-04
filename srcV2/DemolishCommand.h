#ifndef DEMOLISH_COMMAND_H
#define DEMOLISH_COMMAND_H

#include "Command.h"
#include "Building.h"
#include "Point.h"

class DemolishCommand : public Command {
public:
    DemolishCommand(Building* building, const Point& position);
    void execute() override;
    void undo() override;

private:
    Building* targetBuilding;
    Point position;
};

#endif
