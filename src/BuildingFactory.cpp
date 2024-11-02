#include "BuildingFactory.h"

Building* BuildingFactory::createBuilding(const std::string& type) {
	if (type == "Residential"){
		Residential* res;
		return res->build();
	}

	else if (type == "Commercial"){
		Commercial* com;
		return com->build();
	}

	else if (type == "Industrial"){
		Industrial* ind;
		return ind->build();
	}

	else if (type == "Landmark"){
		Landmark* land;
		return land->build();
	}

	else{
		throw "Invalid Building Type.";
	}
}
