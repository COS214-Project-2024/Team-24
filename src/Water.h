#ifndef WATER_H
#define WATER_H

#include "ResourceState.h"

class Water : ResourceState {
public:
	void distributeResources();

	ResourceState* getNextState();
};

#endif
