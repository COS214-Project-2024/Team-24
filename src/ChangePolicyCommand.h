#ifndef CHANGEPOLICYCOMMAND_H
#define CHANGEPOLICYCOMMAND_H

#include "Command.h"
#include "Government.h"
#include <iostream>

class ChangePolicyCommand : public Command {
public:
    // Constructor taking parameters needed for the command
   ChangePolicyCommand(Government* gov, int rate);

    // Execute the change policy command
    void execute() override;

    // Undo the change policy command
    void undo() override;

    ~ChangePolicyCommand();

private:
Government* government;
    int newTaxRate;
    PolicyMemento* previousPolicy;
};

#endif // CHANGEPOLICYCOMMAND_H
