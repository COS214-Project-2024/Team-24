#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    resetToDefaults();
}

void ResourceManager::resetToDefaults() {
    resources = {
        {"power", 1000.0},
        {"water", 1000.0},
        {"waste", 0.0}
    };
    
    resourceCapacities = {
        {"power", 2000.0},
        {"water", 2000.0},
        {"waste", 1000.0}
    };
}

void ResourceManager::setResourceAmount(const std::string& resource, double amount) {
    if (resources.count(resource) > 0) {
        resources[resource] = std::min(amount, resourceCapacities[resource]);
    }
}

void ResourceManager::setResourceCapacity(const std::string& resource, double capacity) {
    if (resourceCapacities.count(resource) > 0) {
        resourceCapacities[resource] = capacity;
        // Ensure current amount doesn't exceed new capacity
        if (resources[resource] > capacity) {
            resources[resource] = capacity;
        }
    }
}

double ResourceManager::getResourceAmount(const std::string& resource) const {
    auto it = resources.find(resource);
    return (it != resources.end()) ? it->second : 0.0;
}

double ResourceManager::getResourceCapacity(const std::string& resource) const {
    auto it = resourceCapacities.find(resource);
    return (it != resourceCapacities.end()) ? it->second : 0.0;
}

void ResourceManager::addResource(const std::string& resource, double amount) {
    if (resources.count(resource) > 0) {
        double newAmount = resources[resource] + amount;
        resources[resource] = std::min(newAmount, resourceCapacities[resource]);
    }
}

void ResourceManager::consumeResource(const std::string& resource, double amount) {
    if (resources.count(resource) > 0) {
        resources[resource] = std::max(0.0, resources[resource] - amount);
    }
}

void ResourceManager::updateResource(const std::string& resource, double amount) {
    if (resources.count(resource) > 0) {
        double newAmount = resources[resource] + amount;
        resources[resource] = std::min(newAmount, resourceCapacities[resource]);
    }
}

bool ResourceManager::hasEnoughResource(const std::string& resource, double amount) const {
    auto it = resources.find(resource);
    return (it != resources.end()) && (it->second >= amount);
}