#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "Building.h"
#include "UnderMaintenance.h"
#include "UnderConstruction.h"
#include "BuildingState.h"
#include <iostream>
#include <vector>

class Operational : public BuildingState {


private:
    int resourceConsumptionRate;  // Resources consumed per update
    int maintenanceThreshold;     // Threshold at which maintenance is required
    int wearAndTear;              // Tracks the wear of the building



public:
    Operational();
    void enter(Building* building) override;    // Logic for entering the Operational state
    void exit(Building* building) override;     // Logic for exiting the Operational state
    void update(Building* building) override;   // Logic to update the Operational state
};

#endif // OPERATIONAL_H
