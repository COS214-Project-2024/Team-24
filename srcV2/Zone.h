#ifndef ZONE_H
#define ZONE_H

#include <vector>
#include <string>
#include "Building.h"
#include "Point.h"
#include "BuildingVisitor.h"

class Zone {
public:
    Zone(const std::string& name, const Point& location, int size);
    ~Zone();

    // Building management
    bool addBuilding(Building* building);
    bool removeBuilding(Building* building);
    void update();
    void maintain();
    void accept(BuildingVisitor* visitor);

    // Zone state checks
    bool canAcceptBuilding(const Building* building) const;
    bool isFull() const { return buildings.size() >= static_cast<size_t>(size * size); }
    bool isValidPosition(const Point& position) const;

    // Getters
    std::string getName() const { return name; }
    Point getLocation() const { return location; }
    int getSize() const { return size; }
    const std::vector<Building*>& getBuildings() const { return buildings; }

    void setZoneType(const std::string& type) { zoneType = type; }
    std::string getZoneType() const { return zoneType; }
    
    bool isCompatibleWith(const Building* building) const;

private:
    std::string name;
    Point location;
    int size;
    std::vector<Building*> buildings;
    std::string zoneType{"Mixed"};  // Default to mixed zone
};

#endif
