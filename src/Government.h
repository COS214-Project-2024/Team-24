#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Observer.h"
#include "PolicyMemento.h"
#include "TaxStrategy.h"
#include "Utility.h"
#include "Citizen.h"
#include <vector>

class Government : Observer {
private:
	PolicyMemento* policy;
	TaxStrategy* taxStrategy;
	double reliability;
	Utility* utilities;
	std::vector<Citizen*> citizens;
	int powerValue;
	int waterValue;
	int wasteValue;
	int sewageValue;
	int population;

public:
	void setPolicy(int rate);

	void restorePolicy(PolicyMemento* memento);

	void improveResource(std::string resource);
};

#endif
