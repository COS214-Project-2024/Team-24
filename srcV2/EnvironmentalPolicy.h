#ifndef ENVIRONMENTALPOLICY_H
#define ENVIRONMENTALPOLICY_H

#include "Policy.h"

class EnvironmentalPolicy : public Policy {
private:
    double pollutionThreshold;
    double greenSpaceRequirement;
    bool requiresImpactStudy;
    bool implemented;

public:
    EnvironmentalPolicy(const std::string& name, const std::string& description,
                       double cost, double impact, double pollutionLimit);

    // Implement pure virtual methods
    void implement() override;
    void withdraw() override;
    double calculateEffect() const override;
    bool isImplemented() const { return implemented; }

    // Additional methods
    void setPollutionThreshold(double threshold);
    void setGreenSpaceRequirement(double requirement);

protected:
    void applyEffects() override;
    void removeEffects() override;
};

#endif 