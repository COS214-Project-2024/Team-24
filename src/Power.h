#ifndef POWER_H
#define POWER_H

#include "ResourceState.h"

class Power : ResourceState {
public:
	void distributeResources();

	ResourceState* getNextState();
};

#endif
