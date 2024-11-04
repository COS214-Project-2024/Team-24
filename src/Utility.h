#ifndef UTILITY_H
#define UTILITY_H

#include "Colleague.h"
#include "CityManager.h"
#include "ResourceState.h"
#include <iostream>

class Utility : public Colleague {
private:
    ResourceState* resourceState;
    bool distributed;

public:
    Utility(CityManager* mediator, ResourceState* state);

    void distribute();
    void Utility::reportEvent(const std::string& event) override;
    void receiveNotification(const std::string& message) override;
};

#endif
