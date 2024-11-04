#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

class Residential : Building {
public:
	void build();
	virtual void accept(BuildingVisitor* visitor) = 0;
	virtual void maintain() = 0;
	virtual void inspect() = 0;
};

#endif
