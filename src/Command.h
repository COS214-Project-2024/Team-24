#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
    // Virtual destructor for proper cleanup of derived classes
    virtual ~Command() {}

    // Execute the command
    virtual void execute() = 0;

    // Undo the command
    virtual void undo() = 0;
};

#endif // COMMAND_H
