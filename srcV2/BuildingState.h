#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <string>

class Building;  // Forward declaration

/**
 * @class BuildingState
 * @brief Abstract base class for representing different states of a Building.
 *
 * This class provides a framework for defining the behavior of a Building object
 * in various states. Derived classes should implement specific states with
 * behaviors defined for enter, exit, and update functions.
 */
class BuildingState {
public:
    /**
     * @brief Constructs a BuildingState for a given building.
     * @param building Pointer to the Building object owning this state.
     */
    BuildingState(Building* building) : ownerBuilding(building) {}

    /// Virtual destructor for cleanup in derived classes.
    virtual ~BuildingState();

    /**
     * @brief Enters the state and initializes any required data or settings.
     * @param building Pointer to the Building transitioning to this state.
     */
    virtual void enter(Building* building) = 0;

    /**
     * @brief Exits the state, performing any necessary cleanup.
     * @param building Pointer to the Building transitioning out of this state.
     */
    virtual void exit(Building* building) = 0;

    /**
     * @brief Updates the state logic based on the building's conditions.
     * @param building Pointer to the Building being updated.
     */
    virtual void update(Building* building) = 0;

    /**
     * @brief Gets the name of the current state.
     * @return A string representing the state's name.
     */
    virtual std::string getStateName() const = 0;

protected:
    Building* ownerBuilding; ///< Pointer to the Building that owns this state.
};

#endif // BUILDINGSTATE_H
