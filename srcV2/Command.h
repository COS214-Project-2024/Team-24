#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <memory>

class Command {
public:
    // Virtual destructor for proper cleanup
    virtual ~Command() = default;

    // Pure virtual methods
    virtual void execute() = 0;
    virtual void undo() = 0;

    // Command state
    bool isExecuted() const { return executed; }
    const std::string& getDescription() const { return description; }
    
    // Command validation
    virtual bool validate() const { return true; }

    // Add setter for description
    void setDescription(const std::string& desc) { description = desc; }

protected:
    // Protected constructor to prevent direct instantiation
    explicit Command(const std::string& desc = "") 
        : description(desc), executed(false) {}
    
    // Protected members for derived classes
    std::string description;
    bool executed{false};

private:
    // Prevent copying of commands
    Command(const Command&) = delete;
    Command& operator=(const Command&) = delete;
};

#endif // COMMAND_H
