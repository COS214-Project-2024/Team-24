#ifndef SEWAGE_H
#define SEWAGE_H

#include "ResourceState.h"

class Sewage : public ResourceState {
public:
    explicit Sewage(ResourceManager* manager);
    
    // Core state methods
    void enter() override;
    void exit() override;
    void update() override;

    // State information
    std::string getStateName() const override { return "Sewage"; }
    double getEfficiency() const override;
    
    // State checks
    bool isStable() const override;
    bool needsMaintenance() const override;

    // Resource management
    bool canDistribute() const override;
    double getConsumptionRate() const override;

private:
    double efficiency{1.0};
    double flowRate{1.0};
    bool stable{true};
};

#endif