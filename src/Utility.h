#ifndef UTILITY_H
#define UTILITY_H

#include "ResourceState.h"

class Utility {
private:
	ResourceState* resourceState;
	bool distributed;

public:
	Utility(ResourceState* state);

	void distribute();
};

#endif
