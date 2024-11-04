#ifndef BUILDING_ATTRIBUTES_H
#define BUILDING_ATTRIBUTES_H

#include <string>
#include <map>

class BuildingAttributes {
public:
    BuildingAttributes();
    
    // Basic attributes
    void setSize(double width, double height);
    void setCost(double buildCost, double maintenanceCost);
    void setCapacity(int maxOccupants);
    void setCategory(const std::string& buildingCategory);
    
    // Getters
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getBuildCost() const { return buildCost; }
    double getMaintenanceCost() const { return maintenanceCost; }
    int getMaxOccupants() const { return maxOccupants; }
    std::string getCategory() const { return category; }
    
    // Resource consumption rates
    void setResourceConsumption(const std::string& resource, double rate);
    double getResourceConsumption(const std::string& resource) const;

private:
    // Physical attributes
    double width{0.0};
    double height{0.0};
    
    // Economic attributes
    double buildCost{0.0};
    double maintenanceCost{0.0};
    
    // Capacity attributes
    int maxOccupants{0};
    
    // Classification
    std::string category;
    
    // Resource consumption rates
    std::map<std::string, double> resourceConsumptionRates;
};

#endif // BUILDING_ATTRIBUTES_H
