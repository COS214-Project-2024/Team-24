#include "BuildCommand.h"


  BuildCommand::BuildCommand(Building *bld, Zone *zn):building(bld), zone(zn){}

    void BuildCommand::undo() {
        building->demolish();
        zone->removeBuilding(building);
        std::cout << "Building is removed from zone " << zone->getType() << std::endl;
    }

   

    void BuildCommand::execute()
    {
            if (zone->addBuilding(building)) {
            building->build();
            std::cout << "Building constructed in zone " << zone->getType() << std::endl;
        } else {
            std::cerr << "Failed to construct the Building: The Zone capacity is full or incompatible." << std::endl;
        }
    }
