#include "Industrial.h"

Industrial::Industrial(){}

void Industrial::build(){
	BuildingState* newState = new UnderConstruction();
	Building::setState(newState);
}

void Industrial::maintain(){
	BuildingState* newState = new UnderMaintainence();
	Building::setState(newState);
}

void Industrial::demolish(){
	BuildingState* newState = new Abandoned();
	Building::setState(newState);
}

void Industrial::update(Command* cmd){
	cmd->execute();
}
