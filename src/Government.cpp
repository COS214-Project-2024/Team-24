#include "Government.h"

void Government::setPolicy(int rate) {
	// TODO - implement Government::setPolicy
	throw "Not yet implemented";
}

void Government::restorePolicy(PolicyMemento* memento) {
	// TODO - implement Government::restorePolicy
	throw "Not yet implemented";
}

void Government::improveResource(std::string resource) {
	// TODO - implement Government::improveResource
	throw "Not yet implemented";
}

void Government::receiveNotification(const std::string& message) {
    std::cout << "Government received: " << message << std::endl;
}
void Government::reportEvent(const std::string& event) {
    if (mediator) {
        mediator->notify(event, this);
    } else {
        std::cerr << "Mediator is not set for Government." << std::endl;
    }
}

void Government::update(Command* cmd) {
    // Execute the command
    cmd->execute();
}

void Government::handleRequest(const std::string& request) {
    if (handlerChain) {
        handlerChain->handleRequest(request);
    }
}