#include "Command.h"
#include <iostream>

// Even though most functionality is in the header,
// we might want to add some common utility functions

namespace {
    // Utility function to log command execution
    void logCommand(const std::string& action, const std::string& description) {
        std::cout << "Command " << action << ": " << description << std::endl;
    }
}

// Note: Most of Command's functionality will be implemented by derived classes.
// However, we could add some common functionality here if needed:

/*
Example of how derived classes should implement execute():

void DerivedCommand::execute() {
    if (!validate()) {
        std::cerr << "Command validation failed: " << description << std::endl;
        return;
    }

    if (!executed) {
        logCommand("executing", description);
        // Perform command-specific execution
        executed = true;
    }
}
*/ 