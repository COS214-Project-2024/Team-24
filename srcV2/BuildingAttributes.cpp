#include "BuildingAttributes.h"
#include <iostream>

BuildingAttributes::BuildingAttributes()
    : width(0.0)
    , height(0.0)
    , buildCost(0.0)
    , maintenanceCost(0.0)
    , maxOccupants(0)
    , category("undefined") {
    
    // Initialize default resource consumption rates
    resourceConsumptionRates["power"] = 0.0;
    resourceConsumptionRates["water"] = 0.0;
    resourceConsumptionRates["waste"] = 0.0;
}

void BuildingAttributes::setSize(double w, double h) {
    width = w;
    height = h;
    
    // Automatically adjust max occupants based on floor area
    // Assuming 1 occupant per 10 square units
    maxOccupants = static_cast<int>((width * height) / 10.0);
    
    std::cout << "Building size set to " << width << "x" << height 
              << " with capacity for " << maxOccupants << " occupants" << std::endl;
}

void BuildingAttributes::setCost(double build, double maintenance) {
    buildCost = build;
    maintenanceCost = maintenance;
    
    std::cout << "Building costs set - Build: " << buildCost 
              << ", Maintenance: " << maintenanceCost << " per day" << std::endl;
}

void BuildingAttributes::setCapacity(int maxOccup) {
    maxOccupants = maxOccup;
    
    std::cout << "Building capacity set to " << maxOccupants << " occupants" << std::endl;
}

void BuildingAttributes::setCategory(const std::string& buildingCategory) {
    category = buildingCategory;
    
    // Set default resource consumption based on category
    if (category == "residential") {
        resourceConsumptionRates["power"] = 1.0;
        resourceConsumptionRates["water"] = 0.8;
        resourceConsumptionRates["waste"] = 0.5;
    } 
    else if (category == "commercial") {
        resourceConsumptionRates["power"] = 2.0;
        resourceConsumptionRates["water"] = 1.0;
        resourceConsumptionRates["waste"] = 1.0;
    }
    else if (category == "industrial") {
        resourceConsumptionRates["power"] = 5.0;
        resourceConsumptionRates["water"] = 3.0;
        resourceConsumptionRates["waste"] = 2.0;
    }
    
    std::cout << "Building category set to " << category << std::endl;
}

void BuildingAttributes::setResourceConsumption(const std::string& resource, double rate) {
    if (rate < 0.0) {
        std::cout << "Warning: Negative resource consumption rate not allowed. Setting to 0." << std::endl;
        rate = 0.0;
    }
    
    resourceConsumptionRates[resource] = rate;
    std::cout << "Set " << resource << " consumption rate to " << rate << std::endl;
}

double BuildingAttributes::getResourceConsumption(const std::string& resource) const {
    auto it = resourceConsumptionRates.find(resource);
    if (it != resourceConsumptionRates.end()) {
        return it->second;
    }
    
    std::cout << "Warning: Resource '" << resource << "' not found. Returning 0." << std::endl;
    return 0.0;
} 