#ifndef GOOD_H
#define GOOD_H

#include "BuildingState.h"

class Good : BuildingState {
public:
	void handle();

	BuildingState* getPreviousState();
};

#endif
