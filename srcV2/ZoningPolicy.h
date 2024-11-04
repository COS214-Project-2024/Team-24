#ifndef ZONINGPOLICY_H
#define ZONINGPOLICY_H

#include "Policy.h"

class ZoningPolicy : public Policy {
private:
    std::string zoneType;  // residential, commercial, industrial
    double densityLimit;
    bool mixedUseAllowed;

public:
    ZoningPolicy(const std::string& name, const std::string& description,
                 double cost, double impact, const std::string& type);

    // Implement pure virtual methods
    void implement() override;
    void withdraw() override;
    double calculateEffect() const override;

    // Additional methods
    void setDensityLimit(double limit);
    void setMixedUse(bool allowed);

protected:
    // Add these protected methods
    void applyEffects() override;
    void removeEffects() override;
};

#endif 