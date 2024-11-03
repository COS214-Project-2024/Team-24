#include "Building.h"
#include <iostream>

Building::Building(const std::string& type, Zone* zone, ResourceManager* resourceManager) : buildingType(type), this->zone(zone), resources(resourceManager) {}
Building::Building(const std::string& type, Zone* zone, ResourceManager* resourceManager, BuildingAttributeFactory* factory) : buildingType(type), this->zone(zone), resources(resourceManager) attributeFactory(factory) {}

void Building::releaseResources(){
	throw "Not implemented yet";
}

void Building::setState(BuildingState* newState){
	state = newState;
}      

BuildingState* getState() const{
	return state;
}        

std::string getBuildingType() const{
	return buildingType;
}           

Zone* getZone() const{
	return zone;
}                       

ResourceManager* getResourceManager() const{
	return resources;
}   

const std::vector<Citizen*>& getCitizens() const{
	throw "Not implemented yet";
} 

BuildingAttributes* getAttributes() const{
	return attributes;
} 
