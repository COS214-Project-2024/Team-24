#ifndef ROADNETWORK_H
#define ROADNETWORK_H

#include <map>
#include <string>
#include "Road.h"

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

    
    std::map<std::string, Road*>::iterator getIterator() 
	{
        return roads.begin();
    }

   
    std::map<std::string, Road*>::const_iterator getConstIterator() const 
	{
        return roads.cbegin();
    }
};

#endif
