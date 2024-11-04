/**
 * @file Citizen.h
 * @brief Defines the abstract Citizen class, representing a resident in the city management system.
 */

#ifndef CITIZEN_H
#define CITIZEN_H

#include "Observer.h"
#include "Colleague.h"
#include <string>
#include "Command.h"
#include "CityManager.h"

/**
 * @class Citizen
 * @brief Abstract class representing a general citizen within the city.
 *
 * Provides basic attributes and methods for handling notifications, resources,
 * and interactions with the City Manager (mediator).
 */
class Citizen : public Colleague, public Observer {
protected:
    double income; /**< The citizen's income level. */
    int satisfaction; /**< Satisfaction level of the citizen. */
    std::string housingSituation; /**< Describes the housing status of the citizen. */
    std::string fullName; /**< Full name of the citizen. */
    long id; /**< Unique ID for the citizen. */
    int* complaints; /**< Count of complaints issued by the citizen. */
    int* deliveredResources; /**< Resources allocated to the citizen. */

public:
    /**
     * @brief Constructs a new Citizen.
     * @param mediator Pointer to the CityManager that mediates citizen requests.
     * @param income Initial income for the citizen.
     */
    Citizen(CityManager* mediator, double income);

    /**
     * @brief Virtual destructor to allow derived class cleanup.
     */
    virtual ~Citizen();

    /**
     * @brief Pure virtual method to clone the citizen object.
     * @return A pointer to the cloned Citizen.
     */
    virtual Citizen* clone() = 0;

    /**
     * @brief Updates the citizen based on a command.
     * @param cmd The command to execute.
     */
    virtual void update(Command* cmd) override;

    /**
     * @brief Receives notifications from other objects.
     * @param message The message received.
     */
    void receiveNotification(const std::string& message) override;

    // Additional methods follow...
};

#endif // CITIZEN_H
