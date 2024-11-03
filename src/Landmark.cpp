#include "Landmark.h"

Landmark::Landmark(){}

void Landmark::build() {
	BuildingState* newState = new Construction();
	Building::setState(newState);
}

void Landmark::maintain(){
	BuildingState* newState = new Good();
	Building::setState(newState);
}

void Landmark::demolish(){
	BuildingState* newState = new Bad();
	Building::setState(newState);
}

void Landmark::update(Command* cmd){
	cmd->execute();
}
