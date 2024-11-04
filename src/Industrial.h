#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"

class Industrial : Building {
public:
	void build();
	virtual void accept(BuildingVisitor* visitor) = 0;
	virtual void maintain() = 0;
	virtual void inspect() = 0;
};

#endif
