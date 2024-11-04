#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"
#include "ResourceManager.h"

/**
 * @brief Represents an industrial building that produces resources.
 */
class Industrial : public Building {
public:
    /**
     * @brief Constructs an Industrial building with a specified name and location.
     * @param name The name of the industrial building.
     * @param location The location of the industrial building.
     */
    Industrial(const std::string& name, const Point& location);

    /**
     * @brief Default destructor for Industrial building.
     */
    virtual ~Industrial() = default;

    // Getters for industrial building properties

    /**
     * @brief Gets the current production rate.
     * @return The current production rate.
     */
    double getProduction() const { return productionRate; }

    /**
     * @brief Gets the production rate.
     * @return The production rate.
     */
    double getProductionRate() const { return productionRate; }

    /**
     * @brief Gets the base production rate.
     * @return The base production rate.
     */
    double getBaseProductionRate() const { return baseProductionRate; }

    /**
     * @brief Gets the amount of waste produced.
     * @return The waste production value.
     */
    double getWasteProduction() const { return wasteProduction; }

    /**
     * @brief Gets the type of product produced.
     * @return The product type as a string.
     */
    std::string getProductType() const { return productType; }

    /**
     * @brief Gets the pollution level generated by the industrial building.
     * @return The pollution level.
     */
    double getPollutionLevel() const { return pollutionLevel; }

    // Override methods from the Building base class

    /**
     * @brief Updates the state of the industrial building.
     */
    void update() override;

    /**
     * @brief Maintains the industrial building to ensure optimal operation.
     */
    void maintain() override;

    /**
     * @brief Accepts a visitor for the Visitor design pattern.
     * @param visitor Pointer to a BuildingVisitor.
     */
    void accept(BuildingVisitor* visitor) override;

    /**
     * @brief Consumes resources required for production.
     */
    void consumeResources();

    /**
     * @brief Checks if there are enough resources to produce.
     * @return True if enough resources are available, false otherwise.
     */
    bool hasEnoughResources() const;

    /**
     * @brief Produces resources based on current production capabilities.
     */
    void produceResources();

private:
    const double baseProductionRate = 10.0; ///< The base production rate of the building.
    double productionRate = baseProductionRate; ///< The current production rate.
    double productionEfficiency = 1.0; ///< The efficiency of production.
    double powerConsumption = 5.0; ///< The amount of power consumed.
    double waterConsumption = 3.0; ///< The amount of water consumed.
    double wasteProduction = 2.0; ///< The amount of waste produced.
    double pollutionLevel = 5.0; ///< The pollution level generated.
    std::string productType = "Power"; ///< The type of product produced by the building.
};

#endif // INDUSTRIAL_H
