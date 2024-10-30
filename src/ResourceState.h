#ifndef RESOURCESTATE_H
#define RESOURCESTATE_H

class ResourceState {
public:
	virtual void distributeResources() = 0;

	virtual ResourceState* getNextState() = 0;
};

#endif
