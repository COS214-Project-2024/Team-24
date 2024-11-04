#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "BuildingVisitor.h"

class Landmark : public Building {
public:
    Landmark(const std::string& name, const Point& location);
    
    // Override Building virtual methods
    void update() override;
    void consumeResources() override;
    bool hasEnoughResources() const override;
    void maintain() override;
    void accept(BuildingVisitor* visitor) override;

    // Landmark-specific methods
    double getTourismValue() const;
    std::string getLandmarkType() const;
    int getVisitorCount() const;

private:
    void updateVisitors();
    
    double powerConsumption{15.0};
    double waterConsumption{10.0};
    double baseTourismValue{100.0};
    int currentVisitors{0};
    std::string landmarkType{"Historical"};
};

#endif
