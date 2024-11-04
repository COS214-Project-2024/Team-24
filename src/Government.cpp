#include "Government.h"
#include <iostream>
#include <vector>

void Government::setPolicy(int rate) {
	policy = new PolicyMemento(rate);

	for (PolicyMemento* policyMomento : policyHistory){
		if (policy == policyMomento){
			std::cout << "This policy already exists." << std::endl;
			return;
		}
	}

	policyHistory.push_back(policy);
}

void Government::restorePolicy(PolicyMemento* memento) {
	policy = memento;
}

void Government::adjustBudget(){
	// TODO - implement Government::improveResource
	throw "Not yet implemented";
}

void Government::implementPolicy(std::string policy){
	throw "Not yet implemented";
}

void Government::handleCrisis(Crisis* crisis){
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