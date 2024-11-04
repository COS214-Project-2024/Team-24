#include "Commercial.h"


void Commercial::build() 
{
	// TODO - implement Commercial::build
	throw "Not yet implemented";
}

void Commercial::accept(BuildingVisitor* visitor)
{
	visitor->visitCommercial(this);
}

void Commercial::maintain()
{
	if(state)
	{
		delete state;
	}

	this->state = new UnderMaintenance();
}

void Commercial::inspect()
{

}
