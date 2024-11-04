#include "Residential.h"

Residential::Residential(){}

void Residential::build() {
	BuildingState* newState = new UnderConstruction();
	Building::setState(newState);
}

void Residential::maintain(){
	BuildingState* newState = new UnderMaintainence();
	Building::setState(newState);
}

void Residential::demolish(){
	BuildingState* newState = new Abandoned();
	Building::setState(newState);
}

void Residential::update(Command* cmd){
	cmd->execute();
}
