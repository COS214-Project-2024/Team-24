#include "BuildingFactoryAbs.h"

void BuildingFactoryAbs::produce(const std::string& type) {
	building = createBuilding(type);
}