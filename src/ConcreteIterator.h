#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "RoadNetwork.h"
#include <map>

class ConcreteIterator : public Iterator 
{

    public:

        ConcreteIterator(RoadNetwork* network);
        void first();
        void next();
        Road* current();
        Road* getRoad();
        bool isDone() const;
};

#endif
