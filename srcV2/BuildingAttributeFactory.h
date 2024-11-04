#ifndef BUILDINGATTRIBUTEFACTORY_H
#define BUILDINGATTRIBUTEFACTORY_H

#include <map>
#include <memory>
#include "SharedBuildingAttributes.h"

/**
 * @class BuildingAttributeFactory
 * @brief Singleton factory class for managing shared building attributes.
 *
 * The BuildingAttributeFactory class provides a singleton access to shared
 * building attributes, ensuring that each set of attributes is created once and
 * reused across the system. Attributes are stored in a map, with caching handled
 * through smart pointers to optimize memory usage.
 */
class BuildingAttributeFactory {
private:
    /// Singleton instance of the factory.
    static BuildingAttributeFactory* instance;

    /// Map for caching shared building attributes.
    std::map<std::string, std::shared_ptr<SharedBuildingAttributes>> attributesMap;

    /// Private constructor for singleton.
    BuildingAttributeFactory() = default;

public:
    /**
     * @brief Gets the singleton instance of the factory.
     * @return Pointer to the singleton instance.
     */
    static BuildingAttributeFactory* getInstance();
    
    /**
     * @brief Retrieves or creates shared attributes based on a key.
     * @param key Unique identifier for the shared attributes.
     * @return A shared pointer to the requested SharedBuildingAttributes.
     */
    std::shared_ptr<SharedBuildingAttributes> getAttributes(const std::string& key);
    
    /// Delete copy constructor to prevent copying of singleton.
    BuildingAttributeFactory(const BuildingAttributeFactory&) = delete;

    /// Delete assignment operator to prevent copying of singleton.
    BuildingAttributeFactory& operator=(const BuildingAttributeFactory&) = delete;

    /**
     * @brief Creates specific building attributes based on the type provided.
     * @param type The type identifier for the building attributes.
     * @return A pointer to the created BuildingAttributes object.
     */
    virtual BuildingAttributes* createAttributes(const std::string& type) = 0;

    /// Destructor for the factory.
    ~BuildingAttributeFactory() = default;
};

#endif // BUILDINGATTRIBUTEFACTORY_H
