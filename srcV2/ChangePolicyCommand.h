#ifndef CHANGEPOLICYCOMMAND_H
#define CHANGEPOLICYCOMMAND_H

#include "Command.h"
#include "Government.h"

class ChangePolicyCommand : public Command {
public:
    ChangePolicyCommand(Government* government, const std::string& newPolicy);
    void execute() override;
    void undo() override;

private:
    Government* government;
    std::string newPolicy;
    bool oldActive;
};

#endif // CHANGEPOLICYCOMMAND_H
