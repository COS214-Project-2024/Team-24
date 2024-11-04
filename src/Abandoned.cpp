#include "Abandoned.h"

/**
 * @brief Placeholder function for handling specific abandoned behavior.
 * Currently not implemented.
 *
 * @throw Throws "Not yet implemented" as a placeholder.
 */
void Abandoned::handle() {
    // TODO - implement Abandoned::handle
    // Placeholder for future abandoned-state-specific behavior.
    throw "Not yet implemented";
}

/**
 * @brief Retrieves the previous state before abandonment.
 * Currently not implemented.
 *
 * @return Pointer to the previous state before abandonment.
 * @throw Throws "Not yet implemented" as a placeholder.
 */
BuildingState* Abandoned::getPreviousState() {
    // TODO - implement Abandoned::getPreviousState
    throw "Not yet implemented";
}

/**
 * @brief Constructs an Abandoned state with default values.
 *
 * Initializes the state with zero days abandoned, no resources salvaged,
 * and a stable condition.
 */
Abandoned::Abandoned() : daysAbandoned(0), resourcesSalvaged(false), condition("stable") {}

/**
 * @brief Logic for entering the Abandoned state.
 *
 * Sets the building's condition to "deteriorating" and releases resources.
 *
 * @param building Pointer to the Building object entering this state.
 */
void Abandoned::enter(Building* building) {
    std::cout << "Building: " << building->getBuildingType() << " has been Abandoned" << std::endl;
    building->releaseResources();
    condition = "deteriorating"; // Set condition to deteriorating when abandoned
}

/**
 * @brief Logic for exiting the Abandoned state.
 *
 * Provides a message indicating if resources were salvaged or not
 * when leaving the abandoned state.
 *
 * @param building Pointer to the Building object exiting this state.
 */
void Abandoned::exit(Building* building) {
    std::cout << "Exiting Abandoned state for building: " << building->getBuildingType() << std::endl;
    if (resourcesSalvaged) {
        std::cout << "Resources salvaged from " << building->getBuildingType() << std::endl;
    } else {
        std::cout << "No resources salvaged from " << building->getBuildingType() << std::endl;
    }
}

/**
 * @brief Updates the building's abandoned state.
 *
 * This function is called periodically to simulate abandonment effects,
 * such as deterioration and salvage availability. After 90 days,
 * the building transitions to a Demolished state.
 *
 * @param building Pointer to the Building object in this state.
 */
void Abandoned::update(Building* building) {
    daysAbandoned++;
    std::cout << "Building has been abandoned for " << daysAbandoned << " days." << std::endl;

    // Simulate building deterioration every 10 days.
    if (daysAbandoned % 10 == 0) {
        condition = "deteriorating";
        std::cout << "Condition of " << building->getBuildingType() << " is now: " << condition << std::endl;
    }

    // Allow resource salvage after 30 days.
    if (!resourcesSalvaged && daysAbandoned > 30) {
        resourcesSalvaged = true;
        std::cout << "Resources can now be salvaged from " << building->getBuildingType() << std::endl;
    }

    // Transition to Demolished state if abandoned for 90 days.
    if (daysAbandoned >= 90) {
        std::cout << "Building " << building->getBuildingType() << " has been abandoned for too long. Transitioning to Demolished state." << std::endl;
        DemolishCommand* demolish = new DemolishCommand(building, building->getZone());
        demolish->execute();
    }
}
