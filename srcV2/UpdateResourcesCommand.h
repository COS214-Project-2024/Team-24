#ifndef UPDATERESOURCESCOMMAND_H
#define UPDATERESOURCESCOMMAND_H

#include "Command.h"
#include "ResourceManager.h"
#include <string>

class UpdateResourcesCommand : public Command {
public:
    UpdateResourcesCommand(ResourceManager* manager, 
                         const std::string& resourceType,
                         double amount);

    void execute() override;
    void undo() override;

private:
    ResourceManager* resourceManager;
    std::string resourceType;
    double amount;
    double previousAmount;
};

#endif
