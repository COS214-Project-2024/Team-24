#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "BuildingFactoryAbs.h"
#include "Building.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"

class BuildingFactory : BuildingFactoryAbs {
public:
	Building* createBuilding(const std::string& type);
};

#endif
