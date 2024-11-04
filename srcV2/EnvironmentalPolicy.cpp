#include "EnvironmentalPolicy.h"
#include <iostream>

EnvironmentalPolicy::EnvironmentalPolicy(const std::string& name, const std::string& description,
                                       double cost, double impact, double pollutionLimit)
    : Policy(name, description, cost, impact)
    , pollutionThreshold(pollutionLimit)
    , greenSpaceRequirement(0.1)
    , requiresImpactStudy(false)
    , implemented(false) {
}

void EnvironmentalPolicy::implement() {
    if (!implemented) {
        applyEffects();
        implemented = true;
        std::cout << "Implemented environmental policy: " << name << std::endl;
    }
}

void EnvironmentalPolicy::withdraw() {
    if (implemented) {
        removeEffects();
        implemented = false;
        std::cout << "Withdrawn environmental policy: " << name << std::endl;
    }
}

void EnvironmentalPolicy::applyEffects() {
    isActive = true;
    std::cout << "Applied environmental effects for: " << name << std::endl;
}

void EnvironmentalPolicy::removeEffects() {
    isActive = false;
    std::cout << "Removed environmental effects for: " << name << std::endl;
}

double EnvironmentalPolicy::calculateEffect() const {
    double effect = impact;
    if (requiresImpactStudy) effect *= 1.5;
    effect *= (1.0 + greenSpaceRequirement);
    return effect;
}

void EnvironmentalPolicy::setPollutionThreshold(double threshold) {
    pollutionThreshold = threshold;
}

void EnvironmentalPolicy::setGreenSpaceRequirement(double requirement) {
    greenSpaceRequirement = requirement;
} 