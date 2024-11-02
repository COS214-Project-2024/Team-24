#ifndef BUILDING_H
#define BUILDING_H

#include "Observer.h"
#include "BuildingState.h"
#include "string"
#include "Zone.h"
#include "ResourceManager.h"
#include "Citizen.h"
#include <iostream>
#include <vector>

class Building : Observer {
protected:
	BuildingState* state;
	std::string buildingType;
	Zone* zone;
	ResourceManager* resources;
	std::vector<Citizen*> citizens;

public:
	Building();

	virtual Building* build() = 0;

	virtual void maintain() = 0;

	virtual void demolish() = 0;

	virtual void update(Command* cmd) = 0;

	std::string getType();
};

#endif
