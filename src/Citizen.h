#ifndef CITIZEN_H
#define CITIZEN_H

#include "Observer.h"
#include "Colleague.h"
#include <string>
#include "Command.h"
#include "CityManager.h"

class Citizen : public Colleague, public Observer {
protected:
    double income;
    int satisfaction;
    std::string housingSituation;
    std::string fullName;
    long id;
    int* complaints;
    int* deliveredResources;

public:
    Citizen(CityManager* mediator, double income);
    ~Citizen();
    virtual Citizen* clone() = 0;
    virtual void update(Command* cmd) override;
    void receiveNotification(const std::string& message) override;
    int deliverResources(int water, int elec, int sewage, int waste);
    void resetDelivery();
    int issueComplaint();
    double getSalary();
    int getSatisfaction();
    long getID();
	void Citizen::reportEvent(const std::string& event) override;
};

#endif
