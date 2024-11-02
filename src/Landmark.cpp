#include "Landmark.h"

Landmark::Landmark(){}

Building* Landmark::build() {
	Building* land = new Landmark();
	return land;
}

void maintain(){
	throw "Not implemented yet";
}

void demolish(){
	throw "Not implemented yet";
}

void update(Command* cmd){
	cmd->execute();
}
