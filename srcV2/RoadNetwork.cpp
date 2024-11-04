#include "RoadNetwork.h"
#include <numeric>

void RoadNetwork::update() {
    for (auto& road : roads) {
        if (road) {
            // Update traffic levels based on connected buildings
            int trafficLevel = road->getTrafficLevel();
            int buildingCount = road->getNumberOfBuildings();
            
            // Adjust traffic based on building count
            road->setTrafficLevel(trafficLevel + (buildingCount * 2));
        }
    }
}

void RoadNetwork::addRoad(std::shared_ptr<Road> road) {
    if (road) {
        roads.push_back(std::move(road));
    }
}

bool RoadNetwork::removeRoad(const Road* road) {
    if (!road) return false;

    auto it = std::find_if(roads.begin(), roads.end(),
        [road](const std::shared_ptr<Road>& ptr) {
            return ptr.get() == road;
        });

    if (it != roads.end()) {
        roads.erase(it);
        return true;
    }
    return false;
}

bool RoadNetwork::isConnected() const {
    if (roads.empty()) return true;
    
    // Count roads with active building connections
    size_t connectedRoads = std::count_if(roads.begin(), roads.end(),
        [](const std::shared_ptr<Road>& road) {
            return road && road->getNumberOfBuildings() > 0;
        });
    
    // Network is connected if at least 75% of roads have buildings
    return (connectedRoads >= roads.size() * 0.75);
}

void RoadNetwork::optimizeTraffic() {
    if (roads.empty()) return;

    double avgTraffic = getAverageTraffic();

    // Adjust traffic levels to balance network
    for (auto& road : roads) {
        if (road) {
            int currentTraffic = road->getTrafficLevel();
            if (currentTraffic > avgTraffic * 1.5) {
                // Reduce high traffic
                road->setTrafficLevel(static_cast<int>(avgTraffic * 1.2));
            } else if (currentTraffic < avgTraffic * 0.5) {
                // Increase low traffic
                road->setTrafficLevel(static_cast<int>(avgTraffic * 0.8));
            }
        }
    }
}

double RoadNetwork::getAverageTraffic() const {
    if (roads.empty()) return 0.0;

    int totalTraffic = std::accumulate(roads.begin(), roads.end(), 0,
        [](int sum, const std::shared_ptr<Road>& road) {
            return sum + (road ? road->getTrafficLevel() : 0);
        });

    return static_cast<double>(totalTraffic) / roads.size();
} 