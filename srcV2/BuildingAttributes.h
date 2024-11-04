#ifndef BUILDING_ATTRIBUTES_H
#define BUILDING_ATTRIBUTES_H

#include <string>
#include <map>

/**
 * @class BuildingAttributes
 * @brief Represents the attributes of a building, including size, cost, capacity, category, and resource consumption rates.
 *
 * This class provides an interface for setting and retrieving various building
 * attributes. It includes methods to configure physical dimensions, cost metrics,
 * maximum occupancy, and resource consumption rates.
 */
class BuildingAttributes {
public:
    /// Default constructor initializing the attributes to default values.
    BuildingAttributes();
    
    /**
     * @brief Sets the size of the building.
     * @param width Width of the building.
     * @param height Height of the building.
     */
    void setSize(double width, double height);

    /**
     * @brief Sets the build and maintenance costs of the building.
     * @param buildCost Cost to construct the building.
     * @param maintenanceCost Daily maintenance cost of the building.
     */
    void setCost(double buildCost, double maintenanceCost);

    /**
     * @brief Sets the maximum number of occupants for the building.
     * @param maxOccupants The maximum occupancy capacity.
     */
    void setCapacity(int maxOccupants);

    /**
     * @brief Sets the building's category (e.g., residential, commercial).
     * @param buildingCategory Category classification of the building.
     */
    void setCategory(const std::string& buildingCategory);

    // Getters
    /**
     * @brief Gets the width of the building.
     * @return Width of the building.
     */
    double getWidth() const { return width; }

    /**
     * @brief Gets the height of the building.
     * @return Height of the building.
     */
    double getHeight() const { return height; }

    /**
     * @brief Gets the build cost of the building.
     * @return Build cost of the building.
     */
    double getBuildCost() const { return buildCost; }

    /**
     * @brief Gets the maintenance cost of the building.
     * @return Daily maintenance cost of the building.
     */
    double getMaintenanceCost() const { return maintenanceCost; }

    /**
     * @brief Gets the maximum occupancy of the building.
     * @return Maximum number of occupants.
     */
    int getMaxOccupants() const { return maxOccupants; }

    /**
     * @brief Gets the category of the building.
     * @return Building category as a string.
     */
    std::string getCategory() const { return category; }

    /**
     * @brief Sets the consumption rate for a specific resource.
     * @param resource The type of resource (e.g., power, water).
     * @param rate The rate of consumption for the resource.
     */
    void setResourceConsumption(const std::string& resource, double rate);

    /**
     * @brief Gets the consumption rate for a specified resource.
     * @param resource The type of resource to query.
     * @return The consumption rate of the resource.
     */
    double getResourceConsumption(const std::string& resource) const;

private:
    // Physical attributes
    double width{0.0};    ///< Width of the building.
    double height{0.0};   ///< Height of the building.
    
    // Economic attributes
    double buildCost{0.0};      ///< Cost to build the structure.
    double maintenanceCost{0.0}; ///< Daily maintenance cost.
    
    // Capacity attributes
    int maxOccupants{0};        ///< Maximum occupancy of the building.
    
    // Classification
    std::string category;       ///< Category of the building (e.g., residential).
    
    // Resource consumption rates
    std::map<std::string, double> resourceConsumptionRates; ///< Consumption rates for various resources.
};

#endif // BUILDING_ATTRIBUTES_H
