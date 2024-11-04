#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>

/**
 * @class Command
 * @brief Abstract base class for representing executable commands with undo functionality.
 *
 * The Command class provides an interface for executing and undoing actions in a system.
 * Derived classes must implement the execute and undo methods to define specific commands.
 * Commands can also have descriptions and support validation.
 */
class Command {
public:
    /// Virtual destructor to ensure proper cleanup in derived classes.
    virtual ~Command() = default;

    /// Executes the command.
    virtual void execute() = 0;

    /// Reverts the command action.
    virtual void undo() = 0;

    /**
     * @brief Checks if the command has been executed.
     * @return True if executed, false otherwise.
     */
    bool isExecuted() const { return executed; }

    /**
     * @brief Gets the description of the command.
     * @return A string containing the command description.
     */
    const std::string& getDescription() const { return description; }

    /**
     * @brief Validates if the command can be executed.
     * @return True if valid, false otherwise.
     */
    virtual bool validate() const { return true; }

    /**
     * @brief Sets the description of the command.
     * @param desc A string containing the new description.
     */
    void setDescription(const std::string& desc) { description = desc; }

protected:
    /**
     * @brief Protected constructor to prevent direct instantiation.
     * @param desc Optional description of the command.
     */
    explicit Command(const std::string& desc = "") 
        : description(desc), executed(false) {}

    std::string description; ///< Description of the command.
    bool executed{false};    ///< Flag indicating if the command has been executed.

private:
    /// Delete copy constructor to prevent copying.
    Command(const Command&) = delete;

    /// Delete assignment operator to prevent copying.
    Command& operator=(const Command&) = delete;
};

#endif // COMMAND_H
