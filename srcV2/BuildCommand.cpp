#include "BuildCommand.h"
#include <iostream>



void BuildCommand::execute() {
    if (!validate()) {
        std::cerr << "Build command validation failed" << std::endl;
        return;
    }

    if (!executed) {
        if (building) {
            building->setLocation(position);
            building->build();
            executed = true;
            std::cout << "Executed: " << description << " at position (" 
                      << position.getX() << "," << position.getY() << ")" << std::endl;
        }
    }
}

void BuildCommand::undo() {
    if (executed && building) {
        building->demolish();
        executed = false;
        std::cout << "Undone: " << description << std::endl;
    }
} 