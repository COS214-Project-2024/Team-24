#ifndef ROADBUILDER_H
#define ROADBUILDER_H

#include <string>
#include <memory>
#include "Road.h"

class RoadBuilder {
private:
    std::string roadType;
    std::string roadName;
    int trafficLevel;

public:
    // Constructor with default values
    RoadBuilder();

    // Builder methods (chainable)
    RoadBuilder& setType(const std::string& type);
    RoadBuilder& setName(const std::string& name);
    RoadBuilder& setTrafficLevel(int traffic);

    // Build method
    std::shared_ptr<Road> build() const;

    // Reset builder
    void reset();
};

#endif