#include "Road.h"
#include <algorithm>
#include <iostream>

Road::Road(const std::string& type, const std::string& name, int traffic)
    : roadType(type)
    , roadName(name)
    , trafficLevel(std::clamp(traffic, 0, MAX_TRAFFIC)) {}

bool Road::connectBuilding(std::shared_ptr<Building> building) {
    if (!building) return false;

    // Remove expired connections first
    connectedBuildings.erase(
        std::remove_if(connectedBuildings.begin(), connectedBuildings.end(),
            [](const std::weak_ptr<Building>& ptr) { return ptr.expired(); }),
        connectedBuildings.end()
    );

    // Check if building is already connected
    auto it = std::find_if(connectedBuildings.begin(), connectedBuildings.end(),
        [&building](const std::weak_ptr<Building>& ptr) {
            return !ptr.expired() && ptr.lock() == building;
        });

    if (it == connectedBuildings.end()) {
        connectedBuildings.push_back(building);
        trafficLevel = std::clamp(trafficLevel + TRAFFIC_INCREMENT, 0, MAX_TRAFFIC);
        return true;
    }
    return false;
}

bool Road::disconnectBuilding(const std::shared_ptr<Building>& building) {
    if (!building) return false;

    auto it = std::find_if(connectedBuildings.begin(), connectedBuildings.end(),
        [&building](const std::weak_ptr<Building>& ptr) {
            return !ptr.expired() && ptr.lock() == building;
        });

    if (it != connectedBuildings.end()) {
        connectedBuildings.erase(it);
        trafficLevel = std::clamp(trafficLevel - TRAFFIC_INCREMENT, 0, MAX_TRAFFIC);
        return true;
    }
    return false;
}

int Road::getNumberOfBuildings() const {
    // Count only non-expired connections
    return std::count_if(connectedBuildings.begin(), connectedBuildings.end(),
        [](const std::weak_ptr<Building>& ptr) { return !ptr.expired(); });
}

void Road::setTrafficLevel(int level) {
    trafficLevel = std::clamp(level, 0, MAX_TRAFFIC);
}

void Road::displayInfo() const {
    std::cout << "Road Information:\n"
              << "Name: " << roadName << "\n"
              << "Type: " << roadType << "\n"
              << "Traffic Level: " << trafficLevel << "/" << MAX_TRAFFIC << "\n"
              << "Connected Buildings: " << getNumberOfBuildings() << "\n";
} 