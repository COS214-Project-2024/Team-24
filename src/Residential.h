#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"

class Residential : Building {
public:
	Residential();
	Building* build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
