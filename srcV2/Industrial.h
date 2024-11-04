#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "ResourceManager.h"

class Industrial : public Building {
public:
    Industrial(const std::string& name, const Point& location);
    virtual ~Industrial() = default;

    double getProduction() const { return productionRate; }
    double getProductionRate() const { return productionRate; }
    double getBaseProductionRate() const { return baseProductionRate; }
    double getWasteProduction() const { return wasteProduction; }
    std::string getProductType() const { return productType; }
    double getPollutionLevel() const { return pollutionLevel; }

    void update() override;
    void maintain() override;
    void accept(BuildingVisitor* visitor) override;

    void consumeResources();
    bool hasEnoughResources() const;
    void produceResources();

private:
    const double baseProductionRate = 10.0;
    double productionRate = baseProductionRate;
    double productionEfficiency = 1.0;
    double powerConsumption = 5.0;
    double waterConsumption = 3.0;
    double wasteProduction = 2.0;
    double pollutionLevel = 5.0;
    std::string productType = "Power";
};

#endif
