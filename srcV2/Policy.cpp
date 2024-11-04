#include "Policy.h"

Policy::Policy(const std::string& name, const std::string& description, 
               double cost, double impact)
    : name(name)
    , description(description)
    , cost(cost)
    , impact(impact) {}

std::string Policy::getName() const {
    return name;
}

std::string Policy::getDescription() const {
    return description;
}

double Policy::getCost() const {
    return cost;
}

double Policy::getImpact() const {
    return impact;
}

bool Policy::getIsActive() const {
    return isActive;
}

void Policy::setActive(bool active) {
    isActive = active;
} 