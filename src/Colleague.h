#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>
class CityManager;

class Colleague {
protected:
    CityManager* mediator;

public:
    Colleague(CityManager* mediator) : mediator(mediator) {}
    virtual ~Colleague() = default;

    virtual void reportEvent(const std::string& event) = 0;   // Notify the mediator of an event
    virtual void receiveNotification(const std::string& message) = 0;  // Handle notifications from the mediator
};

#endif // COLLEAGUE_H
