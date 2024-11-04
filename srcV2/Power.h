#ifndef POWER_H
#define POWER_H

#include "ResourceState.h"

class Power : public ResourceState {
public:
    explicit Power(ResourceManager* manager);
    
    // Core state methods
    void enter() override;
    void exit() override;
    void update() override;

    // State information
    std::string getStateName() const override { return "Power"; }
    double getEfficiency() const override;
    
    // State checks
    bool isStable() const override;
    bool needsMaintenance() const override;

    // Resource management
    bool canDistribute() const override;
    double getConsumptionRate() const override;

private:
    double efficiency{1.0};
    double load{0.0};
    bool stable{true};
};

#endif