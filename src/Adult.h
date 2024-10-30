#ifndef ADULT_H
#define ADULT_H

#include "Citizen.h"

class Adult : Citizen {
public:
	Citizen* clone();
};

#endif
