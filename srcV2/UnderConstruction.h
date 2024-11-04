#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "BuildingState.h"
#include "Building.h"

class UnderConstruction : public BuildingState {
private:
    int constructionTime;
    int timeRemaining;
    double constructionProgress;

public:
    UnderConstruction(Building* building, int time = 10) 
        : BuildingState(building)
        , constructionTime(time)
        , timeRemaining(time)
        , constructionProgress(0.0) {}

    void enter(Building* building) override;
    void exit(Building* building) override;
    void update(Building* building) override;
    std::string getStateName() const override { return "Under Construction"; }

private:
    void updateProgress();
    bool isConstructionComplete() const;
};

#endif
