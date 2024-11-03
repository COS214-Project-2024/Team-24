#ifndef BUILDING_H
#define BUILDING_H

#include "Observer.h"
#include "BuildingState.h"
#include "string"
using namespace std;


class BuildingVisitor;
class Building : Observer {
protected:
	BuildingState* state;
	std::string buildingType;

public:
	virtual void build() = 0;
	std::string getType();
	virtual void accept(BuildingVisitor* visitor) = 0;
	virtual void maintain() = 0;
	virtual void inspect() = 0;
};

#endif
