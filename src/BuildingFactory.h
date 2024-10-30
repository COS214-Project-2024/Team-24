#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "BuildingFactoryAbs.h"
#include "Building.h"

class BuildingFactory : BuildingFactoryAbs {
public:
	Building* createBuilding(const std::string& type);
};

#endif
