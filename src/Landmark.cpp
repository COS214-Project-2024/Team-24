#include "Landmark.h"

Landmark::Landmark(){}

void Landmark::build(){
	BuildingState* newState = new UnderConstruction();
	Building::setState(newState);
}

void Landmark::maintain(){
	BuildingState* newState = new UnderMaintainence();
	Building::setState(newState);
}

void Landmark::demolish(){
	BuildingState* newState = new Abandoned();
	Building::setState(newState);
}

void Landmark::update(Command* cmd){
	cmd->execute();
}
