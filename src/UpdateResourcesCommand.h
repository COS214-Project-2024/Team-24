#ifndef UPDATERESOURCESCOMMAND_H
#define UPDATERESOURCESCOMMAND_H

#include "Command.h"
#include "ResourceManager.h"
#include <iostream>

class UpdateResourcesCommand : public Command {
public:
    // Constructor taking parameters needed for the command
   UpdateResourcesCommand(ResourceManager* resMgr, const std::string& type, double delta);

    // Execute the update resources command
    void execute() override;

    // Undo the update resources command
    void undo() override;

private:
ResourceManager* resourceManager;
    std::string resourceType;
    double amountChange;
    double previousAmount;
};

#endif // UPDATERESOURCESCOMMAND_H
