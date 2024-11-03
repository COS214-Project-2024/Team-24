#include "ChangePolicyCommand.h"

ChangePolicyCommand::ChangePolicyCommand(Government *gov, int rate):government(gov), newTaxRate(rate), previousPolicy(nullptr) {}

void ChangePolicyCommand::execute() {
        previousPolicy = new PolicyMemento(newTaxRate);
        government->setPolicy(newTaxRate);
    }

    void ChangePolicyCommand::undo() {
        if (previousPolicy) {
            government->restorePolicy(previousPolicy);
            delete previousPolicy;
            previousPolicy = nullptr;
        } else {
            std::cout << "Cannot undo: No previous policy has been saved or does not exist." << std::endl;
        }
    }

    ChangePolicyCommand::~ChangePolicyCommand()
    {
         delete previousPolicy;
    }
