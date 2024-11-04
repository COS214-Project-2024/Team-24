#ifndef WATER_H
#define WATER_H

#include "ResourceState.h"

class Water : public ResourceState {
public:
    explicit Water(ResourceManager* manager);
    
    // Core state methods
    void enter() override;
    void exit() override;
    void update() override;

    // State information
    std::string getStateName() const override { return "Water"; }
    double getEfficiency() const override;
    
    // State checks
    bool isStable() const override;
    bool needsMaintenance() const override;

    // Resource management
    bool canDistribute() const override;
    double getConsumptionRate() const override;

private:
    double efficiency{1.0};
    double pressure{1.0};
    bool stable{true};
};

#endif