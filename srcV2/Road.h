#ifndef ROAD_H
#define ROAD_H

#include <vector>
#include <string>
#include <memory>
#include "Building.h"

class Road {
private:
    static constexpr int MAX_TRAFFIC = 100;
    static constexpr int TRAFFIC_INCREMENT = 5;
    
    std::string roadType;
    std::vector<std::weak_ptr<Building>> connectedBuildings;
    int trafficLevel;
    std::string roadName;

public:
    // Constructor
    Road(const std::string& type, const std::string& name, int traffic = 0);

    // Building connections
    bool connectBuilding(std::shared_ptr<Building> building);
    bool disconnectBuilding(const std::shared_ptr<Building>& building);

    // Getters
    std::string getRoadType() const { return roadType; }
    int getTrafficLevel() const { return trafficLevel; }
    int getNumberOfBuildings() const;
    std::string getRoadName() const { return roadName; }
    
    // Setters
    void setTrafficLevel(int level);

    // Utility
    void displayInfo() const;
    bool isAtMaxTraffic() const { return trafficLevel >= MAX_TRAFFIC; }
};

#endif