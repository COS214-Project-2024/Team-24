#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(RoadNetwork* network)
    : Iterator(network)
{
    currRoad = NULL;
}

void ConcreteIterator::first()
{
    traversedRoads.clear();
    if(!roadNetwork->roads.empty()) 
    {
        // Set currRoad to the lexicographically smallest road.Map does this automatically
        auto it = roadNetwork->roads.begin();
        currRoad = it->second;
        traversedRoads.push_back(currRoad);
    } 
    else 
    {
        currRoad = nullptr;
    }
}

void ConcreteIterator::next()
{
    if (isDone()) {
        currRoad = roadNetwork->roads.rbegin()->second; // Set to the last road if all are visited
        return;
    }

    bool foundNext = false;
    for (const auto& pair : roadNetwork->roads) 
    {
        Road* road = pair.second;

        // Check if we have reached the current road in traversal
        if(foundNext) 
        {
            currRoad = road;
            traversedRoads.push_back(currRoad);
            return;
        }

       
        if(road == currRoad)
        {
            foundNext = true;
        }
    }

    // If no next road is found, set currRoad to the last road in the map
    currRoad = roadNetwork->roads.rbegin()->second;
}

Road* ConcreteIterator::current()
{
    return currRoad;
}

Road* ConcreteIterator::getRoad()
{
    return currRoad;
}

bool ConcreteIterator::isDone() const
{
    return currRoad == nullptr || traversedRoads.size() == roadNetwork->roads.size();
}
