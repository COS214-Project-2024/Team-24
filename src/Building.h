#ifndef BUILDING_H
#define BUILDING_H

#include "Observer.h"
#include "BuildingState.h"
#include "string"

class Building : Observer {
protected:
	BuildingState* state;
	std::string buildingType;

public:
	virtual void build() = 0;
	std::string getType();
};

#endif
