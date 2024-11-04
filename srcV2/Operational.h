#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "BuildingState.h"
#include "Building.h"

class Operational : public BuildingState {
public:
    explicit Operational(Building* building) : BuildingState(building) {}

    void enter(Building* building) override;
    void exit(Building* building) override;
    void update(Building* building) override;
    std::string getStateName() const override { return "Operational"; }

private:
    bool needsMaintenance() const;
    double maintenanceThreshold{0.4};
};

#endif
