#ifndef RESOURCE_STATE_H
#define RESOURCE_STATE_H

#include <string>
#include <memory>
#include <stdexcept>

class ResourceManager;  // Forward declaration

class ResourceState {
public:
    // Constructor with resource manager reference
    explicit ResourceState(ResourceManager* manager) 
        : m_manager(manager) {
        if (!manager) {
            throw std::runtime_error("ResourceState created with null manager");
        }
    }

    // Virtual destructor
    virtual ~ResourceState() = default;

    // Core state methods
    virtual void enter() = 0;
    virtual void exit() = 0;
    virtual void update() = 0;

    // State information
    virtual std::string getStateName() const = 0;
    virtual double getEfficiency() const = 0;
    
    // State checks
    virtual bool isStable() const = 0;
    virtual bool needsMaintenance() const = 0;

    // Resource management
    virtual bool canDistribute() const = 0;
    virtual double getConsumptionRate() const = 0;

protected:
    ResourceManager* m_manager;

    // Utility methods
    void logResourceState(const std::string& message) const;
    bool checkThresholds(double current, double min, double max) const;

private:
    // Prevent copying
    ResourceState(const ResourceState&) = delete;
    ResourceState& operator=(const ResourceState&) = delete;
};

#endif // RESOURCE_STATE_H