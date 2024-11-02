#include "Industrial.h"

Industrial::Industrial(){}

Building* Industrial::build() {
	Building* ind = new Industrial();
	return ind;
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
