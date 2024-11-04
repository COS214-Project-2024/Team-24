#ifndef CHANGEPOLICYCOMMAND_H
#define CHANGEPOLICYCOMMAND_H

#include "Command.h"
#include "Government.h"

/**
 * @class ChangePolicyCommand
 * @brief Command class for changing government policy in a simulation.
 *
 * This command changes a policy in the Government class and supports undo functionality.
 * It implements the Command pattern, allowing policy changes to be executed and reversed.
 */
class ChangePolicyCommand : public Command {
public:
    /**
     * @brief Constructs a command to change policy in the given government.
     * @param government Pointer to the Government where the policy will be changed.
     * @param newPolicy The new policy to be set.
     */
    ChangePolicyCommand(Government* government, const std::string& newPolicy);

    /// Executes the policy change.
    void execute() override;

    /// Reverts the policy change to the previous state.
    void undo() override;

private:
    Government* government; ///< Pointer to the government affected by the policy change.
    std::string newPolicy;  ///< New policy to be applied.
    bool oldActive;         ///< Stores the old policy state for undo functionality.
};

#endif // CHANGEPOLICYCOMMAND_H
