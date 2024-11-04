#include "BuildingFactory.h"

Building* BuildingFactory::createBuilding(const std::string& type){
	if (type == "Residential"){
		Residential* res;
		res->build();
		return res;
	}

	else if (type == "Commercial"){
		Commercial* com;
		com->build();
		return com;
	}

	else if (type == "Industrial"){
		Industrial* ind;
		ind->build();
		return ind;
	}

	else if (type == "Landmark"){
		Landmark* land;
		land->build();
		return land;
	}

	else{
		throw "Invalid Building Type.";
	}
}
