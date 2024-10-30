#ifndef CITIZEN_H
#define CITIZEN_H

#include "Observer.h"
#include "string"
#include "Command.h"

class Citizen : Observer {
protected:
	double income;
	int satisfaction;
	std::string housingSituation;
	std::string fullName;
	long id;

public:
	virtual Citizen* clone() = 0;

	virtual void update(Command* cmd) = 0;

	int issueComplaint();
};

#endif
