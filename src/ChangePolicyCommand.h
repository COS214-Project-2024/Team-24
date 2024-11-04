#ifndef CHANGEPOLICYCOMMAND_H
#define CHANGEPOLICYCOMMAND_H

#include "Command.h"
#include "Government.h"
#include <iostream>

/**
 * @class ChangePolicyCommand
 * @brief Command class to handle policy changes in a government entity.
 * 
 * This command allows changing the tax rate in a Government object and provides an
 * undo function to restore the previous tax rate if necessary.
 */
class ChangePolicyCommand : public Command {
public:
    /**
     * @brief Constructs a ChangePolicyCommand with a government and tax rate.
     * @param gov Pointer to the Government entity where the policy change will be applied.
     * @param rate The new tax rate to set as part of the policy change.
     */
    ChangePolicyCommand(Government* gov, int rate);

    /**
     * @brief Executes the policy change, setting a new tax rate for the government.
     * 
     * This method saves the previous tax rate as a memento, allowing the change to be undone later.
     */
    void execute() override;

    /**
     * @brief Undoes the policy change, restoring the previous tax rate.
     * 
     * If a previous policy memento exists, it restores the government’s tax rate to the saved value.
     */
    void undo() override;

    /**
     * @brief Destructor for ChangePolicyCommand, cleans up any saved policy memento.
     */
    ~ChangePolicyCommand();

private:
    Government* government; ///< Pointer to the Government entity where the policy change is applied.
    int newTaxRate; ///< The new tax rate to set for the policy.
    PolicyMemento* previousPolicy; ///< Stores the previous policy as a memento for undo functionality.
};

#endif // CHANGEPOLICYCOMMAND_H
