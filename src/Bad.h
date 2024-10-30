#ifndef BAD_H
#define BAD_H

#include "BuildingState.h"

class Bad : BuildingState {
public:
	void handle();

	BuildingState* getPreviousState();
};

#endif
