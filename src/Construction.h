#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include "BuildingState.h"

class Construction : BuildingState {
public:
	void handle();

	BuildingState* getPreviousState();
};

#endif
