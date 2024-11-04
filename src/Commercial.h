#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "BuildingVisitor.h"
#include "UnderMaintenance.h"

class Commercial : Building {
public:
	void build();
	void accept(BuildingVisitor* visitor);
	void maintain();
	void inspect();
};

#endif
