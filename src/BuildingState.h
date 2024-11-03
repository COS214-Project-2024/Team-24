#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

class BuildingState {
public:
	virtual void handle() = 0;
    virtual void enter(Building* building) = 0;   // Called when entering the state
    virtual void exit(Building* building) = 0;    // Called when exiting the state
    virtual void update(Building* building) = 0;  // Called to update the state
    virtual ~BuildingState() {}
	virtual BuildingState* getPreviousState() = 0;
};

#endif
