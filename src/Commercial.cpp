#include "Commercial.h"

Commercial::Commercial(){}

void Commercial::build() {
	BuildingState* newState = new Construction();
	Building::setState(newState);
}

void Commercial::maintain(){
	BuildingState* newState = new Good();
	Building::setState(newState);
}

void Commercial::demolish(){
	BuildingState* newState = new Bad();
	Building::setState(newState);
}

void Commercial::update(Command* cmd){
	cmd->execute();
}
