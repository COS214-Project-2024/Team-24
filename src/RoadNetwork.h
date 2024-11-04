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

        void addRoad(const std::string& name, Road* road);
        Road* retrieveRoad(const std::string& name);
        ConcreteIterator* spawnIt();

        friend class Iterator;
        friend class ConcreteIterator;

};

#endif
