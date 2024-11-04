#include "DemolishCommand.h"
#include <iostream>

DemolishCommand::DemolishCommand(Building* building, const Point& position)
    : targetBuilding(building)
    , position(position) {
}

void DemolishCommand::execute() {
    if (targetBuilding) {
        std::cout << "Demolishing building at position ("
                  << position.getX() << "," << position.getY() << ")" << std::endl;
        // Add demolition logic here
    }
}

void DemolishCommand::undo() {
    if (targetBuilding) {
        std::cout << "Undoing demolition at position ("
                  << position.getX() << "," << position.getY() << ")" << std::endl;
        // Add undo demolition logic here
    }
} 