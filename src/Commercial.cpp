#include "Commercial.h"

Commercial::Commercial(){}

Building* Commercial::build() {
	Building* com = new Commercial();
	return com;
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
