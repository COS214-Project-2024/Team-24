#ifndef WASTE_H
#define WASTE_H

#include "ResourceState.h"

class Waste : ResourceState {
public:
	void distributeResources();

	ResourceState* getNextState();
};

#endif
