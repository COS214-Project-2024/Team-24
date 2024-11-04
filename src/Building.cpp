#include "Building.h"
#include <iostream>

Building::Building(const std::string& type, Zone* zone, ResourceManager* resourceManager) : buildingType(type), this->zone(zone), resources(resourceManager) {}
Building::Building(const std::string& type, Zone* zone, ResourceManager* resourceManager, BuildingAttributeFactory* factory) : buildingType(type), this->zone(zone), resources(resourceManager) attributeFactory(factory) {}

void Building::releaseResources(){
	throw "Not implemented yet";
}

// Define the getType method
std::string Building::getType() const {
    return buildingType;
}

// Define the notify method
void Building::reportEvent(const std::string& event) {
    if (mediator) {
        mediator->notify(event, this);  // Ensure mediator is defined
    } else {
        std::cerr << "Mediator is not set for Building." << std::endl;
    }
}

// Define the receiveNotification method
void Building::receiveNotification(const std::string& message) {
    std::cout << "Building received notification: " << message << std::endl;
}

// Define the update method
void Building::update(Command* cmd) {
    if (cmd) {
        cmd->execute();
    }
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
