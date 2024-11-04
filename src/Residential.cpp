#include "Residential.h"

Residential::Residential(){}

void Residential::build(){
	BuildingState* newState = new Construction();
	Building::setState(newState);
}

void Residential::maintain(){
	BuildingState* newState = new Good();
	Building::setState(newState);
}

void Residential::demolish(){
	BuildingState* newState = new Bad();
	Building::setState(newState);
}

void Residential::update(Command* cmd){
	cmd->execute();
}
