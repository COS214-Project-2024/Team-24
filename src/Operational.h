#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "Building.h"
#include "UnderMaintenance.h"
#include "UnderConstruction.h"
#include "BuildingState.h"
#include <iostream>
#include <vector>

/**
 * @class Operational
 * @brief Represents the operational state of a building.
 *
 * The Operational state manages resource consumption, monitors the building's
 * wear and tear, and triggers maintenance when thresholds are reached.
 */
class Operational : public BuildingState {
private:
    int resourceConsumptionRate;  ///< The rate at which resources are consumed per update.
    int maintenanceThreshold;     ///< The wear threshold at which maintenance is required.
    int wearAndTear;              ///< Tracks the wear level of the building.

public:
    /**
     * @brief Constructs an Operational state with default values for resource consumption and maintenance thresholds.
     */
    Operational();

    /**
     * @brief Defines logic for entering the Operational state.
     * @param building Pointer to the Building entering this state.
     *
     * Sets up the building to begin normal operation, consuming resources as required.
     */
    void enter(Building* building) override;

    /**
     * @brief Defines logic for exiting the Operational state.
     * @param building Pointer to the Building exiting this state.
     *
     * Prepares the building for transitioning out of the operational state.
     */
    void exit(Building* building) override;

    /**
     * @brief Updates the building's state while operational.
     * @param building Pointer to the Building being updated.
     *
     * Consumes resources based on the consumption rate, increases wear and tear, 
     * and transitions to maintenance if wear exceeds the threshold.
     */
    void update(Building* building) override;
};

#endif // OPERATIONAL_H
