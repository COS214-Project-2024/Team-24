#ifndef CITY_MANAGER_H
#define CITY_MANAGER_H

#include <string>
#include "ZoneManager.h"

/**
 * @brief Manages city operations including zone management.
 */
class CityManager {
public:
    /**
     * @brief Constructs a CityManager with the specified name.
     * @param name The name of the city manager.
     */
    CityManager(const std::string& name);

    /**
     * @brief Destructor for CityManager.
     */
    ~CityManager();

    // Basic getters

    /**
     * @brief Gets the name of the city manager.
     * @return The name of the city manager.
     */
    std::string getName() const { return name; }

    /**
     * @brief Gets the associated ZoneManager.
     * @return Pointer to the ZoneManager.
     */
    ZoneManager* getZoneManager() const { return zoneManager; }

    // Zone management (delegates to ZoneManager)

    /**
     * @brief Creates a new zone with the given parameters.
     * @param name The name of the zone.
     * @param location The location of the zone.
     * @param size The size of the zone.
     * @return Pointer to the created Zone.
     */
    Zone* createZone(const std::string& name, const Point& location, int size);

    /**
     * @brief Finds a zone by its name.
     * @param name The name of the zone to find.
     * @return Pointer to the found Zone, or nullptr if not found.
     */
    Zone* findZone(const std::string& name) const;

    /**
     * @brief Places a building in the specified zone.
     * @param building Pointer to the Building to place.
     * @param zone Pointer to the Zone where the building will be placed.
     * @return True if the building was placed successfully, false otherwise.
     */
    bool placeBuilding(Building* building, Zone* zone);

    /**
     * @brief Updates the city manager state.
     */
    void update();

private:
    std::string name; ///< The name of the city manager.
    ZoneManager* zoneManager; ///< Pointer to the ZoneManager.
};

#endif // CITY_MANAGER_H
