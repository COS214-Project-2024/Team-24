#ifndef OBSERVER_H
#define OBSERVER_H

#include "Command.h"

class Observer {
public:
	virtual void update(Command* cmd) = 0;
};

#endif
