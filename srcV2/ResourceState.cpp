#include "ResourceState.h"
#include "ResourceManager.h"
#include <iostream>

void ResourceState::logResourceState(const std::string& message) const {
    std::cout << "Resource State [" << getStateName() << "]: " 
              << message << std::endl;
}

bool ResourceState::checkThresholds(double current, double min, double max) const {
    if (current < min) {
        logResourceState("Below minimum threshold: " + std::to_string(current));
        return false;
    }
    if (current > max) {
        logResourceState("Above maximum threshold: " + std::to_string(current));
        return false;
    }
    return true;
}

// Example of how derived classes might look:
/*
class NormalState : public ResourceState {
    std::string getStateName() const override { return "Normal"; }
    double getEfficiency() const override { return 1.0; }
    bool isStable() const override { return true; }
    bool needsMaintenance() const override { return false; }
    bool canDistribute() const override { return true; }
    double getConsumptionRate() const override { return 1.0; }
};

class CriticalState : public ResourceState {
    std::string getStateName() const override { return "Critical"; }
    double getEfficiency() const override { return 0.5; }
    bool isStable() const override { return false; }
    bool needsMaintenance() const override { return true; }
    bool canDistribute() const override { return false; }
    double getConsumptionRate() const override { return 0.5; }
};
*/ 