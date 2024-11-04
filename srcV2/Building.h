#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <memory>
#include <vector>
#include "Point.h"
#include "BuildingState.h"
#include "ResourceManager.h"

class Zone;
class Citizen;
class BuildingVisitor;

class Building {
public:
    // Constructor & Destructor
    Building(const std::string& buildingType, const Point& loc, int maxRes = 10);
    virtual ~Building() = 0;

    // Pure virtual methods
    virtual void update();
    virtual void consumeResources() = 0;
    virtual bool hasEnoughResources() const = 0;
    virtual void maintain();
    virtual void accept(BuildingVisitor* visitor) = 0;

    // Building lifecycle methods
    virtual void build();
    virtual void demolish();
    bool isBuilt() const { return built; }

    // State management
    void setState(std::unique_ptr<BuildingState> newState);
    BuildingState* getState() const { return currentState.get(); }

    // Getters and setters
    std::string getBuildingType() const { return buildingType; }
    Point getLocation() const { return location; }
    void setLocation(const Point& newLocation) { location = newLocation; }
    double getCondition() const { return condition; }
    void setCondition(double value) { condition = value; }
    Zone* getZone() const { return zone; }
    void setZone(Zone* newZone) { zone = newZone; }

    // Resident management
    bool canAcceptResident() const;
    bool addResident(Citizen* citizen);
    void removeResident(Citizen* citizen);
    const std::vector<Citizen*>& getResidents() const { return residents; }

protected:
    std::string buildingType;
    Point location;
    double condition{1.0};
    Zone* zone{nullptr};
    ResourceManager& resourceManager;
    std::vector<Citizen*> residents;
    std::unique_ptr<BuildingState> currentState;
    int maxResidents;
    bool built{false};  // Track if building is constructed

    void validateCondition();
    void notifyResidents();
};

// Implement pure virtual destructor
inline Building::~Building() = default;

#endif
