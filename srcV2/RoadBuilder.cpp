#include "RoadBuilder.h"
#include <algorithm>

RoadBuilder::RoadBuilder()
    : roadType("standard")
    , roadName("New Road")
    , trafficLevel(0) {
}

RoadBuilder& RoadBuilder::setType(const std::string& type) {
    roadType = type;
    return *this;
}

RoadBuilder& RoadBuilder::setName(const std::string& name) {
    roadName = name;
    return *this;
}

RoadBuilder& RoadBuilder::setTrafficLevel(int traffic) {
    trafficLevel = std::max(0, traffic);  // Negative check done here, MAX_TRAFFIC check in Road
    return *this;
}

std::shared_ptr<Road> RoadBuilder::build() const {
    return std::make_shared<Road>(roadType, roadName, trafficLevel);
}

void RoadBuilder::reset() {
    roadType = "standard";
    roadName = "New Road";
    trafficLevel = 0;
} 