#ifndef ROADNETWORK_H
#define ROADNETWORK_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Road.h"

class RoadNetwork {
private:
    std::vector<std::shared_ptr<Road>> roads;

public:
    // Constructor and destructor
    RoadNetwork() = default;
    ~RoadNetwork() = default;

    // Prevent copying
    RoadNetwork(const RoadNetwork&) = delete;
    RoadNetwork& operator=(const RoadNetwork&) = delete;

    // Allow moving
    RoadNetwork(RoadNetwork&&) = default;
    RoadNetwork& operator=(RoadNetwork&&) = default;

    // Road management
    void addRoad(std::shared_ptr<Road> road);
    bool removeRoad(const Road* road);
    
    // Getters
    size_t getRoadCount() const { return roads.size(); }
    const std::vector<std::shared_ptr<Road>>& getRoads() const { return roads; }

    // Network operations
    void update();
    bool isConnected() const;
    void optimizeTraffic();
    double getAverageTraffic() const;
};

#endif