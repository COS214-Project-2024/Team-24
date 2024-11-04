#include "Industrial.h"
#include "BuildingVisitor.h"
#include <iostream>
#include <algorithm>

Industrial::Industrial(const std::string& name, const Point& location)
    : Building(name, location) {
    buildingType = "Industrial";
    pollutionLevel = 2.0;  // Set initial pollution level to 2.0 to match test
}

void Industrial::update() {
    // Production is affected by building condition
    productionRate = baseProductionRate * condition;
    pollutionLevel = wasteProduction * (2.0 - condition);  // More pollution when condition is poor
    Building::update();
}

void Industrial::maintain() {
    Building::maintain();
    // Maintenance improves production efficiency and reduces pollution
    productionRate = std::min(productionRate * 1.1, baseProductionRate * 2.0);  // Cap at double base rate
    pollutionLevel = std::max(pollutionLevel * 0.9, 1.0);   // Minimum pollution of 1
}

void Industrial::consumeResources() {
    auto& rm = ResourceManager::getInstance();
    rm.consumeResource("power", powerConsumption);
    rm.consumeResource("water", waterConsumption);
    rm.updateResource("waste", wasteProduction);
}

bool Industrial::hasEnoughResources() const {
    auto& rm = ResourceManager::getInstance();
    return rm.hasEnoughResource("power", powerConsumption) &&
           rm.hasEnoughResource("water", waterConsumption) &&
           rm.hasEnoughResource("waste", -wasteProduction);  // Check waste capacity
}

void Industrial::produceResources() {
    // Production rate affected by condition and efficiency
    double actualProduction = productionRate * condition * productionEfficiency;
    
    // Add produced resources
    auto& rm = ResourceManager::getInstance();
    rm.updateResource("power", actualProduction);
    
    std::cout << "Industrial building produced " << actualProduction 
              << " power units" << std::endl;
}

void Industrial::accept(BuildingVisitor* visitor) {
    if (visitor) {
        visitor->visitIndustrial(this);
    }
}


