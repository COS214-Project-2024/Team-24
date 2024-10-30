#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

class BuildingState {
public:
	virtual void handle() = 0;

	virtual BuildingState* getPreviousState() = 0;
};

#endif
