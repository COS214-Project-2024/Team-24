#ifndef CHILD_H
#define CHILD_H

#include "Citizen.h"

class Child : Citizen {
public:
	Citizen* clone();
};

#endif
