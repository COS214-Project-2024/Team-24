#include "UpdateResourcesCommand.h"



    UpdateResourcesCommand::UpdateResourcesCommand(ResourceManager* resMgr, const std::string& type, double delta)
        : resourceManager(resMgr), resourceType(type), amountChange(delta), previousAmount(0) {}

    void UpdateResourcesCommand::execute()  {
        // Save the current resource level for undo
        if (resourceType == "power") {
            previousAmount = resourceManager->getPower();
        } else if (resourceType == "water") {
            previousAmount = resourceManager->getWater();
        } else if (resourceType == "waste") {
            previousAmount = resourceManager->getWaste();
        } else if (resourceType == "money") {
            previousAmount = resourceManager->getMoney();
        }

        // Update the specified resource
        resourceManager->addResources(resourceType, amountChange);
        std::cout << "Updated " << resourceType << " by " << amountChange << " units." << std::endl;
    }

    void UpdateResourcesCommand::undo()  {
        // Revert to the previous resource level
        if (resourceType == "power") {
            resourceManager->addResources("power", previousAmount - resourceManager->getPower());
        } else if (resourceType == "water") {
            resourceManager->addResources("water", previousAmount - resourceManager->getWater());
        } else if (resourceType == "waste") {
            resourceManager->addResources("waste", previousAmount - resourceManager->getWaste());
        } else if (resourceType == "money") {
            resourceManager->addResources("money", previousAmount - resourceManager->getMoney());
        }
        std::cout << "Reverted " << resourceType << " to previous amount: " << previousAmount << std::endl;
    }