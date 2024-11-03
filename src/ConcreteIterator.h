#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "RoadNetwork.h"
#include <map>

class ConcreteIterator : public Iterator 
{


    protected:
        Road* current();
    public:
        ConcreteIterator(RoadNetwork* network);
        void first();
        void next();
        Road* getRoad();
        bool isDone() const;
};

#endif
