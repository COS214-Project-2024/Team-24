#ifndef BUILDINGFACTORYABS_H
#define BUILDINGFACTORYABS_H

#include "Building.h"

class BuildingFactoryAbs {
private:
	Building* building;

public:
	virtual Building* createBuilding(const std::string& type) = 0;

	void produce(const std::string& type);
};

#endif
