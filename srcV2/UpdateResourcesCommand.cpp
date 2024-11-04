#include "UpdateResourcesCommand.h"
#include <iostream>

UpdateResourcesCommand::UpdateResourcesCommand(ResourceManager* manager,
                                             const std::string& type,
                                             double value)
    : Command("Update " + type + " resource")
    , resourceManager(manager)
    , resourceType(type)
    , amount(value)
    , previousAmount(0.0) {
}

void UpdateResourcesCommand::execute() {
    if (!resourceManager) return;

    // Store previous amount for undo
    previousAmount = resourceManager->getResourceAmount(resourceType);
    
    // First ensure the resource exists
    if (previousAmount == 0.0) {
        resourceManager->addResource(resourceType, 0.0);
    }
    
    // Update resource by adding the amount
    resourceManager->setResourceAmount(resourceType, previousAmount + amount);
    
    executed = true;
    
    std::cout << "UpdateResourcesCommand::execute - Previous: " << previousAmount 
              << ", Amount added: " << amount 
              << ", New total: " << resourceManager->getResourceAmount(resourceType) << std::endl;
}

void UpdateResourcesCommand::undo() {
    if (!resourceManager || !executed) return;

    resourceManager->setResourceAmount(resourceType, previousAmount);
    executed = false;
    
    std::cout << "UpdateResourcesCommand::undo - Restored to: " << previousAmount << std::endl;
}