#ifndef UNDER_MAINTENANCE_H
#define UNDER_MAINTENANCE_H

#include "BuildingState.h"
#include "UnderConstruction.h"
#include "Operational.h"

/**
 * @class UnderMaintenance
 * @brief Represents the state of a building that is currently under maintenance.
 *
 * The UnderMaintenance class manages the maintenance process of a building,
 * including tracking maintenance progress and handling resource costs.
 */
class UnderMaintenance : public BuildingState {
private:
    int maintenanceProgress;      ///< Tracks maintenance progress (0 - 100)
    int maintenanceCostPerTick;   ///< Cost of maintenance per update in resource units

public:
    /**
     * @brief Constructs an UnderMaintenance object with initial progress and cost.
     */
    UnderMaintenance();

    /**
     * @brief Enters the maintenance state for the specified building.
     * 
     * This method initializes the maintenance process and adds resources
     * for maintenance to the resource manager.
     *
     * @param building Pointer to the Building object that is under maintenance.
     */
    void enter(Building* building) override;    // Logic for entering the UnderMaintenance state

    /**
     * @brief Exits the maintenance state for the specified building.
     * 
     * This method is called when maintenance is complete and the building
     * transitions to an operational state.
     *
     * @param building Pointer to the Building object that has completed maintenance.
     */
    void exit(Building* building) override;     // Logic for exiting the UnderMaintenance state

    /**
     * @brief Updates the maintenance progress for the specified building.
     * 
     * This method checks for resource availability, consumes resources, and
     * updates the maintenance progress. If progress reaches 100%, it changes
     * the building's state to operational.
     *
     * @param building Pointer to the Building object being maintained.
     */
    void update(Building* building) override;   // Logic to update the UnderMaintenance state
};

#endif // UNDER_MAINTENANCE_H
