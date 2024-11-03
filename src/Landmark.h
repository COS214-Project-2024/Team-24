#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

class Landmark : Building {
public:
	Landmark();
	void build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
