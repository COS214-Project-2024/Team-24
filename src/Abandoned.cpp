#include "Abandoned.h"

void Abandoned::handle() {
	// TODO - implement Abandoned::handle
	//this is a test comment
	throw "Not yet implemented";
}

BuildingState* Abandoned::getPreviousState() {
	// TODO - implement Abandoned::getPreviousState
	throw "Not yet implemented";
}



Abandoned::Abandoned() : daysAbandoned(0), resourcesSalvaged(false), condition("stable") {}

    void Abandoned::enter(Building* building) {
        std::cout << "Building: " << building->getBuildingType() << " has been Abandoned" << std::endl;
        building->releaseResources();
        condition = "deteriorating"; // Change condition upon entering the state
    }

    void Abandoned::exit(Building* building) {
        std::cout << "Exiting Abandoned state for building: " << building->getBuildingType() << std::endl;
        if (resourcesSalvaged) {
            std::cout << "Resources salvaged from " << building->getBuildingType() << std::endl;
        } else {
            std::cout << "No resources salvaged from " << building->getBuildingType() << std::endl;
        }
    }

    void Abandoned::update(Building* building) {
        daysAbandoned++;
        std::cout << "Building has been abandoned for " << daysAbandoned << " days." << std::endl;

        // Simulate deterioration
        if (daysAbandoned % 10 == 0) { // Every 10 days
            condition = "deteriorating";
            std::cout << "Condition of " << building->getBuildingType() << " is now: " << condition << std::endl;
        }

        // Check if resources can be salvaged
        if (!resourcesSalvaged && daysAbandoned > 30) { // After 30 days, allow salvaging
            resourcesSalvaged = true;
            std::cout << "Resources can now be salvaged from " << building->getBuildingType() << std::endl;
        }

        // Determine if it should transition to Demolished state after a long period
        if(daysAbandoned >= 90) { // If abandoned for 90 days, transition to Demolished
            std::cout << "Building " << building->getBuildingType() << " has been abandoned for too long. Transitioning to Demolished state." << std::endl;
         DemolishCommand* demolish = new DemolishCommand(building,building->getZone());
         demolish->execute();
        }
    }
