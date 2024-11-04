#include "Residential.h"
#include <iostream>
#include <algorithm>

Residential::Residential(const std::string& name, const Point& location)
    : Building(name, location) {
    buildingType = "Residential";
}

void Residential::update() {
    if (isBuilt() && hasEnoughResources()) {
        consumeResources();
        updateComfortLevel();
        updateSatisfaction();
        
        // Decrease condition over time
        setCondition(getCondition() - 0.01);
        if (getCondition() < 0.4) {
            maintain();
        }
    }
}

void Residential::maintain() {
    if (hasEnoughResources()) {
        resourceManager.consumeResource("power", powerConsumption * 2);
        resourceManager.consumeResource("water", waterConsumption * 2);
        
        setCondition(std::min(1.0, getCondition() + 0.2));
        comfortLevel = std::min(1.0, comfortLevel + 0.05);
        
        std::cout << "Residential building maintained. New condition: " 
                  << getCondition() << std::endl;
    }
}

void Residential::consumeResources() {
    resourceManager.consumeResource("power", powerConsumption);
    resourceManager.consumeResource("water", waterConsumption);
}

bool Residential::hasEnoughResources() const {
    return resourceManager.hasEnoughResource("power", powerConsumption) &&
           resourceManager.hasEnoughResource("water", waterConsumption);
}

double Residential::getOccupancyRate() const {
    return maxResidents > 0 ? static_cast<double>(residents.size()) / maxResidents : 0.0;
}

void Residential::updateComfortLevel() {
    // Comfort affected by condition and resources
    double resourceFactor = hasEnoughResources() ? 1.0 : 0.5;
    comfortLevel = getCondition() * resourceFactor;
    
    // Gradually decrease comfort if overcrowded
    if (getOccupancyRate() > 0.9) {
        comfortLevel *= 0.95;
    }
}

void Residential::updateSatisfaction() {
    // Satisfaction based on comfort and resources
    satisfactionLevel = comfortLevel * (hasEnoughResources() ? 1.0 : 0.7);
    
    std::cout << "Residential satisfaction updated: " << (satisfactionLevel * 100.0) 
              << "%" << std::endl;
}

void Residential::accept(BuildingVisitor* visitor) {
    if (visitor) {
        visitor->visitResidential(this);
    }
}