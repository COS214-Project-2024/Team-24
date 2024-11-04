#include "ZoningPolicy.h"
#include <iostream>

ZoningPolicy::ZoningPolicy(const std::string& name, const std::string& description,
                          double cost, double impact, const std::string& type)
    : Policy(name, description, cost, impact)
    , zoneType(type)
    , densityLimit(1.0)
    , mixedUseAllowed(false) {
}

void ZoningPolicy::implement() {
    if (!isImplemented) {
        applyEffects();
        isImplemented = true;
        std::cout << "Implemented zoning policy: " << name << std::endl;
    }
}

void ZoningPolicy::withdraw() {
    if (isImplemented) {
        removeEffects();
        isImplemented = false;
        std::cout << "Withdrawn zoning policy: " << name << std::endl;
    }
}

void ZoningPolicy::applyEffects() {
    isActive = true;
    std::cout << "Applied zoning effects for: " << name << std::endl;
}

void ZoningPolicy::removeEffects() {
    isActive = false;
    std::cout << "Removed zoning effects for: " << name << std::endl;
}

double ZoningPolicy::calculateEffect() const {
    double effect = impact;
    if (mixedUseAllowed) effect *= 1.2;
    effect *= densityLimit;
    return effect;
}

void ZoningPolicy::setDensityLimit(double limit) {
    densityLimit = limit;
}

void ZoningPolicy::setMixedUse(bool allowed) {
    mixedUseAllowed = allowed;
} 