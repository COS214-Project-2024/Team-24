#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
#include "BuildingVisitor.h"

class Residential : public Building {
public:
    Residential(const std::string& name, const Point& location);
    
    void update() override;
    void consumeResources() override;
    bool hasEnoughResources() const override;
    void maintain() override;
    void accept(BuildingVisitor* visitor) override;

    double getOccupancyRate() const;
    double getComfortLevel() const { return comfortLevel; }
    double getSatisfactionLevel() const { return satisfactionLevel; }
    bool hasAvailableParking() const { return parkingAvailable; }
    bool hasResources() const { return hasResourcesFlag; }
    void setHasResources(bool has) { hasResourcesFlag = has; }

private:
    void updateComfortLevel();
    void updateSatisfaction();
    
    double powerConsumption{10.0};
    double waterConsumption{15.0};
    double comfortLevel{0.8};
    double satisfactionLevel{0.8};
    bool parkingAvailable{true};
    bool hasResourcesFlag = false;
};

#endif
