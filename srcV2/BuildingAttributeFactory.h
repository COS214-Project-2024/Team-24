#ifndef BUILDINGATTRIBUTEFACTORY_H
#define BUILDINGATTRIBUTEFACTORY_H

#include <map>
#include <memory>
#include "SharedBuildingAttributes.h"

class BuildingAttributeFactory {
private:
    // Singleton instance
    static BuildingAttributeFactory* instance;
    
    // Cache using smart pointers
    std::map<std::string, std::shared_ptr<SharedBuildingAttributes>> attributesMap;
    
    // Private constructor for singleton
    BuildingAttributeFactory() = default;

public:
    // Singleton access
    static BuildingAttributeFactory* getInstance();
    
    // Get shared attributes
    std::shared_ptr<SharedBuildingAttributes> getAttributes(const std::string& key);
    
    // Prevent copying
    BuildingAttributeFactory(const BuildingAttributeFactory&) = delete;
    BuildingAttributeFactory& operator=(const BuildingAttributeFactory&) = delete;
    virtual BuildingAttributes* createAttributes(const std::string& type) = 0;
    ~BuildingAttributeFactory() = default;
};

#endif // BUILDINGATTRIBUTEFACTORY_H
