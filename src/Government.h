#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Observer.h"
#include "PolicyMemento.h"
#include "TaxStrategy.h"
#include "Utility.h"
#include "Citizen.h"
#include "Crisis.h"
#include "Budget.h"
#include <vector>

class Government : Observer {
private:
	PolicyMemento* policy;
	TaxStrategy* taxStrategy;
	Budget* budget;
	std::vector<PolicyMemento*> policyHistory;

public:
	void setPolicy(int rate);

	void restorePolicy(PolicyMemento* memento);

	void adjustBudget();

	void implementPolicy(std::string policy);

	void handleCrisis(Crisis* crisis);
};

#endif
