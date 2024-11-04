#include "Zone.h"
#include <iostream>
#include <vector>

bool Zone::addBuilding(Building* building){
    for (Building* build : buildings){
		if (building == build){
			std::cout << "This building already exists." << std::endl;
			return false;
		}
	}

	buildings.push_back(building);
    return true;
}

void Zone::removeBuilding(Building* building){
    auto it = std::find(buildings.begin(), buildings.end(),building);

    if (it != buildings.end()){
        buildings.erase(it);
    }

    else{
        std::cout<<"This building does not exist."<<std::endl;
    }
}

bool Zone::isCompatible(Building* building){
    throw "Not implemented yet.";
}