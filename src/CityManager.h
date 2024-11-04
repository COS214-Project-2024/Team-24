#ifndef CITYMANAGER_H
#define CITYMANAGER_H

#include <string>
class Colleague;

class CityManager {
public:
    virtual ~CityManager() = default;

    // Notify method used by colleagues to communicate events to the mediator
    virtual void notify(const std::string& event, Colleague* sender) = 0;
};

#endif // CITYMANAGER_H
