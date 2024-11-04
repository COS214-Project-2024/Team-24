#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <string>

class Building;  // Forward declaration

class BuildingState {
public:
    BuildingState(Building* building) : ownerBuilding(building) {}
    virtual ~BuildingState();

    virtual void enter(Building* building) = 0;
    virtual void exit(Building* building) = 0;
    virtual void update(Building* building) = 0;
    virtual std::string getStateName() const = 0;

protected:
    Building* ownerBuilding;
};

#endif
