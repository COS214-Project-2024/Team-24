#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include "RoadNetwork.h"

class Iterator 
{
    protected:
        RoadNetwork* roadNetwork;
        std::vector<Road*> traversedRoads;
        int size;

    public:
        Iterator(RoadNetwork* network) : roadNetwork(network), size(0) {}
        
        virtual void first() = 0;
        virtual void next() = 0;
        virtual Road* current() const = 0;
        virtual bool isDone() const = 0;
        virtual ~Iterator() = default;
};

#endif
