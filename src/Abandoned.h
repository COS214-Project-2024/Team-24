#ifndef ABANDONED_H
#define ABANDONED_H

#include "BuildingState.h"

class Abandoned : BuildingState {
public:
	void handle();

	BuildingState* getPreviousState();
};

#endif
