#ifndef ROADNETWORK_H
#define ROADNETWORK_H

#include <vector>
#include "Road.h"

class RoadNetwork {
private:
	std::vector<Road*> roads;

public:
	std::vector<Road*>::iterator getIterator();
};

#endif
