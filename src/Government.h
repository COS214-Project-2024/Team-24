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
#include "RequestHandler.h"

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
    RequestHandler* handlerChain;

public:
    Government(CityManager* mediator, RequestHandler* handler);
    void setPolicy(int rate);
    void restorePolicy(PolicyMemento* memento);
    void improveResource(const std::string& resource);
    void receiveNotification(const std::string& message) override;
    void update(Command* cmd) override;
    void reportEvent(const std::string& event) override;
    void handleRequest(const std::string& request);
};

#endif // GOVERNMENT_H
