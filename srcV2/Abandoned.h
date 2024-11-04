#ifndef ABANDONED_H
#define ABANDONED_H

#include "BuildingState.h"
#include "Building.h"
#include <string>

class Abandoned : public BuildingState {
public:
    void enter(Building* building) override;
    void exit(Building* building) override;
    void update(Building* building) override;
    std::string getStateName() const override;
};

#endif


