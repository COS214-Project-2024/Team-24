#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

class Residential : Building {
public:
	Residential();
	void build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
