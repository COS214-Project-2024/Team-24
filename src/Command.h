#ifndef COMMAND_H
#define COMMAND_H

/**
 * @class Command
 * @brief Abstract base class for command pattern, providing a blueprint for commands with execute and undo functionality.
 * 
 * The Command class serves as an interface for all commands, enforcing the implementation of `execute` and `undo` methods
 * to support flexible command execution and reversal in derived classes.
 */
class Command {
public:
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived class objects.
     */
    virtual ~Command() {}

    /**
     * @brief Executes the command.
     * 
     * This pure virtual function must be overridden in derived classes to perform the specific command action.
     */
    virtual void execute() = 0;

    /**
     * @brief Undoes the command.
     * 
     * This pure virtual function must be overridden in derived classes to reverse the command action.
     */
    virtual void undo() = 0;
};

#endif // COMMAND_H
