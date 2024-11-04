#ifndef BUILDING_H
#define BUILDING_H

#include "Observer.h"
#include "BuildingState.h"
#include "Colleague.h"
#include "CityManager.h"
#include <string>
#include <iostream>

class Building : public Colleague, public Observer {
protected:
    BuildingState* state;
    std::string buildingType;
    

public:
    Building(CityManager* mediator, const std::string& type) 
        : Colleague(mediator), buildingType(type), state(nullptr) {}

    virtual void build() = 0;

    std::string getType() const;

    void Building::reportEvent(const std::string& event);

    void receiveNotification(const std::string& message) override;

    void update(Command* cmd) override;
};

#endif
