#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

class Landmark : Building {
public:
	void build();
	virtual void accept(BuildingVisitor* visitor) = 0;
	virtual void maintain() = 0;
	virtual void inspect() = 0;
};

#endif
