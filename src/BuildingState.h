#ifndef BUILDING_STATE_H
#define BUILDING_STATE_H

/**
 * @class BuildingState
 * @brief Abstract base class representing the state of a Building.
 * 
 * The BuildingState class defines the interface for various states a building can be in, 
 * allowing specific behaviors to be implemented in derived classes for each state.
 */
class BuildingState {
public:
    /**
     * @brief Called when a building enters this state.
     * @param building Pointer to the Building object entering the state.
     * 
     * This pure virtual function must be implemented in derived classes to specify 
     * actions taken when a building transitions into this state.
     */
    virtual void enter(Building* building) = 0;

    /**
     * @brief Called when a building exits this state.
     * @param building Pointer to the Building object exiting the state.
     * 
     * This pure virtual function must be implemented in derived classes to specify 
     * actions taken when a building transitions out of this state.
     */
    virtual void exit(Building* building) = 0;

    /**
     * @brief Updates the current state of the building.
     * @param building Pointer to the Building object being updated.
     * 
     * This pure virtual function must be implemented in derived classes to specify 
     * actions taken to update the building's status in this state.
     */
    virtual void update(Building* building) = 0;

    /**
     * @brief Virtual destructor to ensure proper cleanup of derived class objects.
     */
    virtual ~BuildingState() {}
};

#endif // BUILDING_STATE_H
