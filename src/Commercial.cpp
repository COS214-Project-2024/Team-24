#include "Commercial.h"

Commercial::Commercial(){}

void Commercial::build() {
	BuildingState* newState = new UnderConstruction();
	Building::setState(newState);
}

void Commercial::maintain(){
	BuildingState* newState = new UnderMaintainence();
	Building::setState(newState);
}

void Commercial::demolish(){
	BuildingState* newState = new Abandoned();
	Building::setState(newState);
}

void Commercial::update(Command* cmd){
	cmd->execute();
}
