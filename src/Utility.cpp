#include "Utility.h"

Utility::Utility(ResourceState* state) {
	// TODO - implement Utility::Utility
	throw "Not yet implemented";
}

void Utility::distribute() {
	// TODO - implement Utility::distribute
	throw "Not yet implemented";
}

void Utility::reportEvent(const std::string& event) {
    if (mediator) {
        mediator->notify(event, this);  // Ensure mediator is defined
    } else {
        std::cerr << "Mediator is not set for Utility." << std::endl;
    }
}

void Utility::receiveNotification(const std::string& message) {
	std::cout << "Utility received: " << message << std::endl;
}
