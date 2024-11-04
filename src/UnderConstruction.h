#ifndef UNDER_CONSTRUCTION_H
#define UNDER_CONSTRUCTION_H

#include "BuildingState.h"
#include <iostream>
#include <map>
#include "Building.h"
#include "Operational.h"

/**
 * @class UnderConstruction
 * @brief Represents the state of a building that is currently under construction.
 *
 * The UnderConstruction class manages the construction process of a building,
 * including tracking construction progress and handling resource costs.
 */
class UnderConstruction : public BuildingState {
private:
    int constructionProgress;    ///< Progress percentage (0 - 100)
    int constructionCostPerTick; ///< Cost per update in resource units

public:
    /**
     * @brief Constructs an UnderConstruction object with initial progress and cost.
     */
    UnderConstruction();

    /**
     * @brief Enters the under construction state for the specified building.
     * 
     * This method initializes the construction process and adds resources
     * for construction to the resource manager.
     *
     * @param building Pointer to the Building object that is under construction.
     */
    void enter(Building* building) override;

    /**
     * @brief Exits the under construction state for the specified building.
     * 
     * This method is called when the construction is complete and the building
     * transitions to an operational state.
     *
     * @param building Pointer to the Building object that has completed construction.
     */
    void exit(Building* building) override;

    /**
     * @brief Updates the construction progress for the specified building.
     * 
     * This method checks for resource availability, consumes resources, and
     * updates the construction progress. If progress reaches 100%, it changes
     * the building's state to operational.
     *
     * @param building Pointer to the Building object being constructed.
     */
    void update(Building* building) override;
    
};

#endif // UNDER_CONSTRUCTION_H
