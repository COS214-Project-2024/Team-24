#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "BuildingVisitor.h"

class Commercial : public Building {
public:
    Commercial(const std::string& name, const Point& location);
    
    void update() override;
    void consumeResources() override;
    bool hasEnoughResources() const override;
    void maintain() override;
    void accept(BuildingVisitor* visitor) override;

    double getRevenue() const { return revenue; }
    double getRetailEfficiency() const { return retailEfficiency; }
    int getCurrentCustomers() const { return currentCustomers; }

private:
    void handleCustomers();
    void updateRevenue();
    
    double powerConsumption{20.0};
    double waterConsumption{10.0};
    double revenue{0.0};
    double retailEfficiency{0.8};
    int maxCustomers{50};
    int currentCustomers{0};
};

#endif
