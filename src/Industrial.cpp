#include "Industrial.h"

Industrial::Industrial(){}

void Industrial::build() {
	BuildingState* newState = new Construction();
	Building::setState(newState);
}

void Industrial::maintain(){
	BuildingState* newState = new Good();
	Building::setState(newState);
}

void Industrial::demolish(){
	BuildingState* newState = new Bad();
	Building::setState(newState);
}

void Industrial::update(Command* cmd){
	cmd->execute();
}
