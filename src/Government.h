#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Observer.h"
#include "PolicyMemento.h"
#include "TaxStrategy.h"
#include "Utility.h"
#include "Citizen.h"
#include "Colleague.h"
#include <vector>
#include <string>

class Government : public Colleague, public Observer {
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
    Government(CityManager* mediator);
    void setPolicy(int rate);
    void restorePolicy(PolicyMemento* memento);
    void Government::improveResource(std::string resource);
    void receiveNotification(const std::string& message) override;
    void update(Command* cmd) override;
    void Government::reportEvent(const std::string& event) override;
};

#endif
