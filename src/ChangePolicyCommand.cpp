#include "ChangePolicyCommand.h"

/**
 * @class ChangePolicyCommand
 * @brief Command class to change government policy by adjusting the tax rate.
 * 
 * The ChangePolicyCommand allows for changing a government's policy to a new tax rate
 * and provides an undo feature to revert to the previous rate if necessary.
 */

/**
 * @brief Constructs a ChangePolicyCommand with a target government and new tax rate.
 * @param gov Pointer to the Government entity whose policy will be changed.
 * @param rate The new tax rate to be applied as policy.
 */
ChangePolicyCommand::ChangePolicyCommand(Government *gov, int rate) 
    : government(gov), newTaxRate(rate), previousPolicy(nullptr) {}

/**
 * @brief Executes the policy change by setting a new tax rate and saving the previous policy state.
 * 
 * Creates a policy memento of the current tax rate before changing it to allow for undo functionality.
 */
void ChangePolicyCommand::execute() {
    previousPolicy = new PolicyMemento(newTaxRate);
    government->setPolicy(newTaxRate);
}

/**
 * @brief Undoes the policy change by restoring the government policy to its previous state.
 * 
 * If a previous policy exists, it restores the policy from the memento. Otherwise, outputs an error message.
 */
void ChangePolicyCommand::undo() {
    if (previousPolicy) {
        government->restorePolicy(previousPolicy);
        delete previousPolicy;
        previousPolicy = nullptr;
    } else {
        std::cout << "Cannot undo: No previous policy has been saved or does not exist." << std::endl;
    }
}

/**
 * @brief Destructor for ChangePolicyCommand, ensures cleanup of saved policy memento.
 */
ChangePolicyCommand::~ChangePolicyCommand() {
    delete previousPolicy;
}
