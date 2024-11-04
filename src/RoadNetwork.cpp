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