#ifndef UPDATERESOURCESCOMMAND_H
#define UPDATERESOURCESCOMMAND_H

#include "Command.h"
#include "ResourceManager.h"
#include <iostream>

/**
 * @class UpdateResourcesCommand
 * @brief Command class for managing updates to specific resources in a ResourceManager.
 * 
 * The UpdateResourcesCommand class provides functionality to adjust a resource level
 * (e.g., power, water, waste, money) by a specified amount, with an option to undo the change.
 */
class UpdateResourcesCommand : public Command {
public:
    /**
     * @brief Constructs an UpdateResourcesCommand with parameters for resource manager, type, and amount.
     * @param resMgr Pointer to the ResourceManager handling resources.
     * @param type The type of resource to be modified (e.g., "power", "water").
     * @param delta The amount to adjust the resource by.
     */
    UpdateResourcesCommand(ResourceManager* resMgr, const std::string& type, double delta);

    /**
     * @brief Executes the update resources command, adjusting the specified resource.
     * 
     * Saves the current state of the resource for potential undo functionality.
     */
    void execute() override;

    /**
     * @brief Undoes the resource update, restoring the resource to its prior state.
     */
    void undo() override;

private:
    ResourceManager* resourceManager; ///< Pointer to the ResourceManager managing resources.
    std::string resourceType; ///< The type of resource to be updated.
    double amountChange; ///< The amount by which to adjust the resource.
    double previousAmount; ///< Stores the previous amount for undo purposes.
};

#endif // UPDATERESOURCESCOMMAND_H
