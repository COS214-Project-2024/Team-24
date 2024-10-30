#ifndef SEWAGE_H
#define SEWAGE_H

#include "ResourceState.h"

class Sewage : ResourceState {
public:
	void distributeResources();

	ResourceState* getNextState();
};

#endif
