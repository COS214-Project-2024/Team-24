#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

class Landmark : Building {
public:
	Landmark();
	Building* build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
