/**
 * @file Abandoned.h
 * @brief Defines the Abandoned state for buildings, representing a deteriorated state.
 */

#ifndef ABANDONED_H
#define ABANDONED_H

#include "BuildingState.h"
#include "Building.h"
#include <string>

/**
 * @class Abandoned
 * @brief Represents a state where the building is abandoned and deteriorates over time.
 */
class Abandoned : public BuildingState {
public:
    /**
     * @brief Enters the abandoned state, setting building properties accordingly.
     * @param building The building entering the abandoned state.
     */
    void enter(Building* building) override;

    /**
     * @brief Exits the abandoned state, cleaning up abandoned-specific properties.
     * @param building The building exiting the abandoned state.
     */
    void exit(Building* building) override;

    /**
     * @brief Updates the building condition, causing it to deteriorate over time.
     * @param building The building being updated in the abandoned state.
     */
    void update(Building* building) override;

    /**
     * @brief Retrieves the name of the current state.
     * @return A string representing the state name ("Abandoned").
     */
    std::string getStateName() const override;
};

#endif // ABANDONED_H
