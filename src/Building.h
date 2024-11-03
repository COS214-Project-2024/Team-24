#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include "BuildingAttributes.h"
#include "Zone.h"
#include "ResourceManager.h"
#include "Citizen.h"
#include "BuildingVisitor.h"
#include "Command.h"
#include "BuildingAttributeFactory.h"
#include "BuildingState.h"

class Building {
protected:
    BuildingState* state;                // Current state of the building
    std::string buildingType;            // Type of the building
    Zone* zone;                          // Zone in which the building is located
    ResourceManager* resources;           // Resource manager for the building
    std::vector<Citizen*> citizens;      // List of citizens associated with the building
    BuildingAttributeFactory* attributeFactory; // Factory for shared attributes
    BuildingAttributes* attributes;       // Shared attributes for the building

public:
    // Constructor
    Building(const std::string& type, Zone* zone, ResourceManager* resourceManager);
    Building(const std::string& type, Zone* zone, ResourceManager* resourceManager, BuildingAttributeFactory* factory);

    // Pure virtual methods
    virtual void build() = 0;                     // Method to build the building
    virtual void maintain() = 0;                   // Method to maintain the building
    virtual void demolish() = 0;                   // Method to demolish the building
    virtual void accept(BuildingVisitor* visitor) = 0; // Accept a visitor for the building
    virtual void update(Command* cmd) = 0;        // Update the building based on a command

    // Getters and setters
    void releaseResources();
    void setState(BuildingState* newState);       // Set the current state of the building
    BuildingState* getState() const;               // Get the current state of the building
    std::string getBuildingType() const;           // Get the type of the building
    Zone* getZone() const;                         // Get the zone of the building
    ResourceManager* getResourceManager() const;   // Get the resource manager of the building
    const std::vector<Citizen*>& getCitizens() const; // Get the citizens associated with the building
    BuildingAttributes* getAttributes() const;     // Get the shared attributes
};

#endif // BUILDING_H
