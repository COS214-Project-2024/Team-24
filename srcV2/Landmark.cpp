#include "Landmark.h"
#include "BuildingVisitor.h"
#include <iostream>
#include <algorithm>

Landmark::Landmark(const std::string& name, const Point& location)
    : Building(name, location) {
    buildingType = "Landmark";
}

void Landmark::update() {
    if (isBuilt() && hasEnoughResources()) {
        consumeResources();
        updateVisitors();
        
        // Decrease condition over time
        setCondition(getCondition() - 0.005);  // Landmarks degrade slower
        if (getCondition() < 0.4) {
            maintain();
        }
    }
}

void Landmark::maintain() {
    if (hasEnoughResources()) {
        resourceManager.consumeResource("power", powerConsumption * 2);
        resourceManager.consumeResource("water", waterConsumption * 2);
        
        setCondition(std::min(1.0, getCondition() + 0.3));
        
        std::cout << "Landmark maintained. New condition: " 
                  << getCondition() << std::endl;
    }
}

void Landmark::updateVisitors() {
    double attractionFactor = getCondition() * (baseTourismValue / 100.0);
    currentVisitors = static_cast<int>(1000 * attractionFactor);
    
    double revenue = currentVisitors * 5.0;  // Each visitor contributes $5
    
    std::cout << "Landmark has " << currentVisitors 
              << " visitors today, generating $" << revenue 
              << " in revenue" << std::endl;
}

void Landmark::consumeResources() {
    resourceManager.consumeResource("power", powerConsumption);
    resourceManager.consumeResource("water", waterConsumption);
}

bool Landmark::hasEnoughResources() const {
    return resourceManager.hasEnoughResource("power", powerConsumption) &&
           resourceManager.hasEnoughResource("water", waterConsumption);
}

void Landmark::accept(BuildingVisitor* visitor) {
    if (visitor) {
        visitor->visitLandmark(this);
    }
}

double Landmark::getTourismValue() const {
    return baseTourismValue * getCondition();
}

std::string Landmark::getLandmarkType() const {
    return landmarkType;
}

int Landmark::getVisitorCount() const {
    return currentVisitors;
}
