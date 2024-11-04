#include "DemolishCommand.h"



void DemolishCommand::execute()
{
        building->demolish();
        zone->removeBuilding(building);
        std::cout << "Building is being demolished and removed from zone " << zone->getType() << std::endl;
}


DemolishCommand::~DemolishCommand()
{
    delete previousState;
}


DemolishCommand::DemolishCommand(Building *bld, Zone *zn) : building(bld), zone(zn), previousState(nullptr) {}


void DemolishCommand::execute()
{
    // Save the building's current state and resources before demolition
    previousState = building->getState();
   
    // Demolish the building and release resources
    building->demolish();
    zone->removeBuilding(building);
    std::cout << "Building is demolished and it is removed from zone " << zone->getType() << std::endl;
    }



    // Undo the demolition
    void DemolishCommand::undo()  {
        // Restore the building's previous state and resources
        if (previousState) {
            building->setState(previousState);
            zone->addBuilding(building);
            std::cout << "Building is restored to it's previous state in zone " << zone->getType() << std::endl;
        } else {
            std::cerr << "Cannot undo: No previous state found." << std::endl;
        }
    }

