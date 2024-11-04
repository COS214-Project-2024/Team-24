#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include "RoadNetwork.h"

class Iterator 
{
    protected:
        RoadNetwork* roadNetwork;
        std::vector<Road*> traversedRoads;
        Road* currRoad;
        int size;
        virtual Road* current() = 0;

    public:

        Iterator(RoadNetwork* network);
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() = 0;
        virtual Road* getRoad();
       
};

#endif
