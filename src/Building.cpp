#include "Building.h"

// Define the getType method
std::string Building::getType() const {
    return buildingType;
}

// Define the notify method
void Building::reportEvent(const std::string& event) {
    if (mediator) {
        mediator->notify(event, this);  // Ensure mediator is defined
    } else {
        std::cerr << "Mediator is not set for Building." << std::endl;
    }
}

// Define the receiveNotification method
void Building::receiveNotification(const std::string& message) {
    std::cout << "Building received notification: " << message << std::endl;
}

// Define the update method
void Building::update(Command* cmd) {
    if (cmd) {
        cmd->execute();
    }
}
