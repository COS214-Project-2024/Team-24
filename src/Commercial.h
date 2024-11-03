#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

class Commercial : Building {
public:
	Commercial();
	void build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
