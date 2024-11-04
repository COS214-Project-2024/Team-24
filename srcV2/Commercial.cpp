#include "Commercial.h"
#include "BuildingVisitor.h"
#include <iostream>
#include <algorithm>

Commercial::Commercial(const std::string& name, const Point& location)
    : Building(name, location) {
    buildingType = "Commercial";
}

void Commercial::update() {
    if (isBuilt() && hasEnoughResources()) {
        consumeResources();
        
        // Update retail efficiency based on condition
        retailEfficiency = getCondition() * 0.8;  // base efficiency is 0.8
        
        handleCustomers();
        updateRevenue();
        
        // Decrease condition over time
        setCondition(getCondition() - 0.01);
        if (getCondition() < 0.4) {
            maintain();
        }
    }
}

void Commercial::maintain() {
    if (hasEnoughResources()) {
        resourceManager.consumeResource("power", powerConsumption * 2);
        resourceManager.consumeResource("water", waterConsumption * 2);
        
        setCondition(std::min(1.0, getCondition() + 0.2));
        // Retail efficiency will be updated in next update() call
        
        std::cout << "Commercial building maintained. New condition: " 
                  << getCondition() << std::endl;
    }
}

void Commercial::consumeResources() {
    resourceManager.consumeResource("power", powerConsumption);
    resourceManager.consumeResource("water", waterConsumption);
}

bool Commercial::hasEnoughResources() const {
    return resourceManager.hasEnoughResource("power", powerConsumption) &&
           resourceManager.hasEnoughResource("water", waterConsumption);
}

void Commercial::handleCustomers() {
    // Simulate customer traffic based on condition and efficiency
    double attractionFactor = getCondition() * retailEfficiency;
    currentCustomers = static_cast<int>(maxCustomers * attractionFactor);
    
    std::cout << "Commercial building has " << currentCustomers 
              << " customers" << std::endl;
}

void Commercial::updateRevenue() {
    // Generate revenue based on customer count
    double baseRevenuePerCustomer = 10.0;
    revenue = currentCustomers * baseRevenuePerCustomer * retailEfficiency;
    
    std::cout << "Commercial building generated " << revenue 
              << " revenue" << std::endl;
}

void Commercial::accept(BuildingVisitor* visitor) {
    if (visitor) {
        visitor->visitCommercial(this);
    }
}
