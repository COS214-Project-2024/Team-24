#include "Road.h"

Road::Road(const std::string& type, int traffic) {
	// TODO - implement Road::Road
	throw "Not yet implemented";
}

boolean Road::connectBuilding(Building* building) {
	// TODO - implement Road::connectBuilding
	throw "Not yet implemented";
}

boolean Road::disconnectBuilding(Building* building) {
	// TODO - implement Road::disconnectBuilding
	throw "Not yet implemented";
}

std::string Road::getRoadType() {
	return this->roadType;
}

void Road::setTrafficLevel(int level) {
	this->trafficLevel = level;
}

int Road::getTrafficLevel() {
	return this->trafficLevel;
}

void Road::displayInfo() {
	// TODO - implement Road::displayInfo
	throw "Not yet implemented";
}

int Road::getNumberOfBuildings() {
	// TODO - implement Road::getNumberOfBuildings
	throw "Not yet implemented";
}

string Road::getRoadName() {
	return this->roadName;
}
