#include "Residential.h"

Residential::Residential(){}

Building* Residential::build() {
	Building* res = new Residential();
	return res;
}

void Residential::maintain(){
	throw "Not implemented Yet";
}

void Residential::demolish(){
	throw "Not implemented Yet";
}

void Residential::update(Command* cmd){
	cmd->execute();
}