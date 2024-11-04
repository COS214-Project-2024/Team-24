#ifndef ROADNETWORK_H
#define ROADNETWORK_H

#include <map>
#include <string>
#include "Road.h"
#include "Colleague.h"
#include "ConcreteIterator.h"
#include "CityManager.h"

class RoadNetwork : public Colleague {
private:
    std::map<std::string, Road*> roads;

public:
    RoadNetwork(CityManager* mediator);
    void addRoad(const std::string& name, Road* road);
    Road* retrieveRoad(const std::string& name);
    ConcreteIterator* spawnIt();
    void RoadNetwork::reportEvent(const std::string& event) override;

    void receiveNotification(const std::string& message) override;
};

#endif
