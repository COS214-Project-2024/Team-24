#ifndef ROADNETWORK_H
#define ROADNETWORK_H

#include <map>
#include <string>
#include "Road.h"
#include "Iterator.h"
#include "ConcreteIterator.h"

class RoadNetwork 
{
private:
    std::map<std::string, Road*> roads;

public:

    void addRoad(const std::string& name, Road* road) 
    {
        roads[name] = road;
    }

    Road* retrieveRoad(const std::string& name) const 
    {
        auto it = roads.find(name);
        return (it != roads.end()) ? it->second : nullptr;
    }

    friend class Iterator;
    friend class ConcreteIterator;

};

#endif
