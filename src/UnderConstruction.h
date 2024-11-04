#ifndef UNDER_CONSTRUCTION_H
#define UNDER_CONSTRUCTION_H

#include "BuildingState.h"
#include <iostream>
#include <map>
#include "Building.h"
#include "Operational.h"

class UnderConstruction : public BuildingState {
private:
    int constructionProgress;    // Progress percentage (0 - 100)
    int constructionCostPerTick; // Cost per update (resource units)


public:
    UnderConstruction();
    void enter(Building* building) override;
    void exit(Building* building) override;
    void update(Building* building) override;
    

};

#endif // UNDER_CONSTRUCTION_H
