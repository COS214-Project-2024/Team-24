#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <algorithm>
#include <iostream>

class ResourceManager {
public:
    // Singleton access
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }
    
    // Delete copy constructor and assignment operator
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    
    // Resource management
    void setResourceAmount(const std::string& resource, double amount);
    void setResourceCapacity(const std::string& resource, double capacity);
    double getResourceAmount(const std::string& resource) const;
    double getResourceCapacity(const std::string& resource) const;
    
    // Resource operations
    void addResource(const std::string& resource, double amount);
    void consumeResource(const std::string& resource, double amount);
    void updateResource(const std::string& resource, double amount);
    bool hasEnoughResource(const std::string& resource, double amount) const;
    
    // Reset
    void resetToDefaults();

private:
    // Private constructor for singleton
    ResourceManager();
    
    std::map<std::string, double> resources;
    std::map<std::string, double> resourceCapacities;
};

#endif
