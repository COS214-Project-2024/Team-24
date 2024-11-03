#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "RoadNetwork.h"
#include <map>

class ConcreteIterator : public Iterator 
{

    public:

       
        void first()
        {
            traversedRoads.clear();
            currentIt = roadNetwork->getIterator();
            size = roadNetwork->getIterator() == roadNetwork->getConstIterator() ? 0 : roadNetwork->getIterator()->size();
        }

        void next() 
        {
            if (currentIt != roadNetwork->getConstIterator()) {
                traversedRoads.push_back(currentIt->second);
                ++currentIt;
            }
        }

        Road* current() const 
        {
            return currentIt != roadNetwork->getConstIterator() ? currentIt->second : nullptr;
        }

        bool isDone() const
        {
            return currentIt == roadNetwork->getConstIterator();
        }
};

#endif
