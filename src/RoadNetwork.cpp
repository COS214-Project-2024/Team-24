#include "RoadNetwork.h"

void RoadNetwork::addRoad(const std::string& name, Road* road) 
{
    roads[name] = road;
}

Road* RoadNetwork::retrieveRoad(const std::string& name) 
{
    auto it = roads.find(name);
    return (it != roads.end()) ? it->second : nullptr;
}

ConcreteIterator* RoadNetwork::spawnIt()
{
	ConcreteIterator* it = new ConcreteIterator(this);
	return it;
}

void RoadNetwork::receiveNotification(const std::string& message) {
    std::cout << "RoadNetwork received: " << message << std::endl;
}

void RoadNetwork::reportEvent(const std::string& event) {
    if (mediator) {
        mediator->notify(event, this);  // Ensure mediator is defined
    } else {
        std::cerr << "Mediator is not set for Road Network." << std::endl;
    }
}
