#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

class Commercial : Building {
public:
	Commercial();
	Building* build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
