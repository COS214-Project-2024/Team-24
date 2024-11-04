#ifndef UNDER_MAINTENANCE_H
#define UNDER_MAINTENANCE_H

#include "BuildingState.h"
#include "UnderMaintenance.h"
#include "UnderConstruction.h"
#include "Operational.h"

class UnderMaintenance : public BuildingState {


    private:
    int maintenanceProgress;      // Tracks maintenance progress
    int maintenanceCostPerTick;   // Cost of maintenance per update



public:
    UnderMaintenance();
    void enter(Building* building);    // Logic for entering the UnderMaintenance state
    void exit(Building* building);     // Logic for exiting the UnderMaintenance state
    void update(Building* building);   // Logic to update the UnderMaintenance state
};

#endif // UNDER_MAINTENANCE_H
