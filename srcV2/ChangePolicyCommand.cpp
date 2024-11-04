#include "ChangePolicyCommand.h"
#include <iostream>

ChangePolicyCommand::ChangePolicyCommand(Government* government, const std::string& newPolicy)
    : Command("Change policy")
    , government(government)
    , newPolicy(newPolicy)
    {
     std::cout << "Created policy change command" << std::endl;
}

void ChangePolicyCommand::execute() {
    if (!validate()) {
        std::cerr << "Change policy command validation failed" << std::endl;
        return;
    }

    if (!executed && government) {
        oldActive = government->isPolicyActive(newPolicy);  // Store old state
        government->setPolicy(newPolicy, true);            // Activate new policy
        executed = true;
        std::cout << "Executed: " << description << std::endl;
    }
}

void ChangePolicyCommand::undo() {
    if (executed && government) {
        government->setPolicy(newPolicy, oldActive);  // Restore previous state
        executed = false;
        std::cout << "Undone: " << description << std::endl;
    }
} 