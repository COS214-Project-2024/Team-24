#ifndef ABANDONED_H
#define ABANDONED_H


#include "BuildingState.h"
#include "Building.h"
#include <iostream>
#include <string>

class Abandoned : BuildingState {
public:
	void handle();
	void enter(Building* building) override;    // Logic for entering the Abandoned state
    void exit(Building* building) override;     // Logic for exiting the Abandoned state
    void update(Building* building) override;   // Logic to update the Abandoned state
	BuildingState* getPreviousState();

	 private:
    int daysAbandoned;            
    bool resourcesSalvaged;       // Flag to check if resources have been salvaged
    std::string condition;         // Condition of the building (e.g., "deteriorating", "stable")

};

#endif
