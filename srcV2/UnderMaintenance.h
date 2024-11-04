#ifndef UNDERMAINTENANCE_H
#define UNDERMAINTENANCE_H

#include "BuildingState.h"
#include "Building.h"

class UnderMaintenance : public BuildingState {
private:
    int maintenanceDuration;
    int timeRemaining;
    double repairProgress;

public:
    UnderMaintenance(Building* building, int duration = 5) 
        : BuildingState(building)
        , maintenanceDuration(duration)
        , timeRemaining(duration)
        , repairProgress(0.0) {}

    void enter(Building* building) override;
    void exit(Building* building) override;
    void update(Building* building) override;
    std::string getStateName() const override { return "Under Maintenance"; }

private:
    void updateProgress();
    bool isMaintenanceComplete() const;
};

#endif
