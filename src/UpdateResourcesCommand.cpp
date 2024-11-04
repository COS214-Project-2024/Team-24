#include "UpdateResourcesCommand.h"

/**
 * @class UpdateResourcesCommand
 * @brief Command class to update specific resources managed by a ResourceManager.
 * 
 * This command allows updating the quantity of a specified resource and provides an
 * undo feature to revert to the previous resource level if necessary.
 */

/**
 * @brief Constructs an UpdateResourcesCommand with specified resource manager, resource type, and change amount.
 * @param resMgr Pointer to the ResourceManager that manages resources.
 * @param type Type of resource to update (e.g., "power", "water", "waste", "money").
 * @param delta Amount to change the resource level by.
 */
UpdateResourcesCommand::UpdateResourcesCommand(ResourceManager* resMgr, const std::string& type, double delta)
    : resourceManager(resMgr), resourceType(type), amountChange(delta), previousAmount(0) {}

 /**
 * @brief Executes the resource update command, adjusting the specified resource by a given amount.
 * 
 * Saves the current resource level before applying the change to allow for undo functionality.
 */
void UpdateResourcesCommand::execute() {
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

/**
 * @brief Undoes the resource update, restoring the resource to its previous level.
 * 
 * Uses the saved previous amount to revert the resource back to its original state.
 */
void UpdateResourcesCommand::undo() {
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
