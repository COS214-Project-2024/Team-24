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
	int* complaints;
	int* deliveredResources;

public:
	Citizen(double income);
	~Citizen();
	virtual Citizen* clone() = 0;
	virtual void update(Command* cmd) = 0;
	//have an array that corresponds to the resource they get, 0-water, 1-electricity, 2-sewage, 3-waste
	int deliverResources(int water,int elec,int sewage,int waste);
	void resetDelivery();
	int issueComplaint();
	double getSalary();
	int getSatisfaction();
	long getID();
};

#endif
