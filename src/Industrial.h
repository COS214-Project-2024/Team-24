#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"

class Industrial : Building {
public:
	Industrial();
	void build();
	void maintain();
	void demolish();
	void update(Command* cmd);
};

#endif
