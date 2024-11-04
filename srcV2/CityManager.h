#ifndef CITIZENMANAGER_H
#define CITIZENMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "Citizen.h"

/**
 * @brief Manages citizens within the city.
 */
class CitizenManager {
private:
    std::vector<std::unique_ptr<Citizen>> citizens; ///< Collection of citizens.

public:
    /**
     * @brief Default constructor for CitizenManager.
     */
    CitizenManager() = default;

    /**
     * @brief Default destructor for CitizenManager.
     */
    ~CitizenManager() = default;

    // Deleted copy constructor and assignment operator to prevent copying.
    CitizenManager(const CitizenManager&) = delete;
    CitizenManager& operator=(const CitizenManager&) = delete;

    /**
     * @brief Creates a new citizen with the specified name.
     * @param name The name of the citizen to create.
     * @return Unique pointer to the created Citizen.
     */
    std::unique_ptr<Citizen> createCitizen(const std::string& name);

    /**
     * @brief Updates all citizens.
     */
    void updateCitizens();

    /**
     * @brief Handles the needs of all citizens.
     */
    void handleCitizenNeeds();

    /**
     * @brief Calculates the overall happiness of all citizens.
     * @return The calculated happiness value.
     */
    double calculateHappiness() const;

    /**
     * @brief Gets the count of citizens managed.
     * @return The number of citizens.
     */
    size_t getCitizenCount() const { return citizens.size(); }

    /**
     * @brief Removes a citizen by their ID.
     * @param id The ID of the citizen to remove.
     */
    void removeCitizen(long id);

    /**
     * @brief Gets a constant reference to the list of citizens.
     * @return A vector of unique pointers to citizens.
     */
    const std::vector<std::unique_ptr<Citizen>>& getCitizens() const { return citizens; }
};

#endif // CITIZENMANAGER_H
