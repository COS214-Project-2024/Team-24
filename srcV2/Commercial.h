#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"
#include "BuildingVisitor.h"

/**
 * @class Commercial
 * @brief Represents a commercial building with specific resource consumption and revenue properties.
 *
 * This class provides specific implementations for a commercial building, including
 * methods for updating state, handling customers, and calculating revenue.
 * It also supports the visitor pattern to interact with different building types.
 */
class Commercial : public Building {
public:
    /**
     * @brief Constructs a Commercial building with the given name and location.
     * @param name The name of the commercial building.
     * @param location The location coordinates of the building.
     */
    Commercial(const std::string& name, const Point& location);
    
    /// Updates the building's state each simulation cycle.
    void update() override;

    /// Calculates and consumes resources for the building.
    void consumeResources() override;

    /**
     * @brief Checks if the building has enough resources to operate.
     * @return True if sufficient resources, false otherwise.
     */
    bool hasEnoughResources() const override;

    /// Maintains the building, performing any required upkeep.
    void maintain() override;

    /**
     * @brief Accepts a visitor for the building.
     * @param visitor Pointer to a BuildingVisitor.
     */
    void accept(BuildingVisitor* visitor) override;

    /// Returns the building's current revenue.
    double getRevenue() const { return revenue; }

    /// Returns the retail efficiency of the commercial building.
    double getRetailEfficiency() const { return retailEfficiency; }

    /// Returns the current number of customers in the building.
    int getCurrentCustomers() const { return currentCustomers; }

private:
    /// Handles customer interactions and occupancy.
    void handleCustomers();

    /// Updates the building's revenue based on customer interactions.
    void updateRevenue();

    double powerConsumption{20.0}; ///< Power consumption rate.
    double waterConsumption{10.0}; ///< Water consumption rate.
    double revenue{0.0};           ///< Current revenue of the building.
    double retailEfficiency{0.8};  ///< Efficiency rate for retail operations.
    int maxCustomers{50};          ///< Maximum customer capacity.
    int currentCustomers{0};       ///< Current number of customers.
};

#endif // COMMERCIAL_H
