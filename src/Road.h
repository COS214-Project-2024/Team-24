#ifndef ROAD_H
#define ROAD_H

#include <vector>
#include <string>
#include "Building.h"

class Road {
private:
	std::string roadType;
	std::vector<Building*> connectedBuildings;
	int trafficLevel;
	std::string roadName;

public:
	Road(const std::string& type, int traffic = 0);

	bool connectBuilding(Building* building);

	bool disconnectBuilding(Building* building);

	std::string getRoadType();

	void setTrafficLevel(int level);

	int getTrafficLevel();

	void displayInfo();

	int getNumberOfBuildings();

	std::string getRoadName();
};

#endif
