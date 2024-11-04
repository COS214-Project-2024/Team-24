#ifndef ABANDONED_H
#define ABANDONED_H

#include "BuildingState.h"
#include "Building.h"
#include <iostream>
#include <string>

/**
 * @class Abandoned
 * @brief Represents the "Abandoned" state of a building.
 *
 * This state is applied when a building is no longer in use or maintained.
 * It manages the progression of abandonment, including deterioration
 * and potential salvaging of resources.
 */
class Abandoned : public BuildingState {
public:
    /**
     * @brief Handles specific behavior unique to the abandoned state.
     *
     * Placeholder method to be implemented with behavior specific
     * to the abandoned state, such as decay or alerting nearby entities.
     */
    void handle();

    /**
     * @brief Logic for entering the Abandoned state.
     *
     * Executed when a building transitions to the abandoned state.
     * Typically used to initialize abandonment-related attributes.
     *
     * @param building Pointer to the Building object entering this state.
     */
    void enter(Building* building) override;

    /**
     * @brief Logic for exiting the Abandoned state.
     *
     * Executed when a building transitions out of the abandoned state.
     * Used to finalize or clear abandonment-related attributes.
     *
     * @param building Pointer to the Building object exiting this state.
     */
    void exit(Building* building) override;

    /**
     * @brief Logic to update the Abandoned state.
     *
     * Called periodically to update abandonment progress,
     * check for salvage operations, or monitor deterioration.
     *
     * @param building Pointer to the Building object in this state.
     */
    void update(Building* building) override;

    /**
     * @brief Retrieves the previous state before abandonment.
     *
     * This can be used to revert the building to its prior state
     * if it is restored or reused.
     *
     * @return A pointer to the previous BuildingState before abandonment.
     */
    BuildingState* getPreviousState();

private:
    int daysAbandoned;            ///< Tracks the number of days the building has been abandoned.
    bool resourcesSalvaged;       ///< Flag indicating whether resources have been salvaged from the building.
    std::string condition;        ///< Describes the current condition of the building (e.g., "deteriorating", "stable").
};

#endif // ABANDONED_H
