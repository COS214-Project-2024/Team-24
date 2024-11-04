#ifndef ENVIRONMENTALPOLICY_H
#define ENVIRONMENTALPOLICY_H

#include "Policy.h"

/**
 * @class EnvironmentalPolicy
 * @brief Represents an environmental policy with specific thresholds and requirements.
 *
 * This policy class includes features for pollution control, green space requirements, and
 * the need for environmental impact studies. It provides methods for implementing and
 * withdrawing the policy and calculates its environmental effect.
 */
class EnvironmentalPolicy : public Policy {
private:
    double pollutionThreshold;       ///< Maximum allowed pollution level.
    double greenSpaceRequirement;    ///< Required percentage of green space.
    bool requiresImpactStudy;        ///< Indicates if an environmental study is required.
    bool implemented;                ///< True if the policy is currently implemented.

public:
    /**
     * @brief Constructs an EnvironmentalPolicy with specified attributes.
     * @param name The name of the policy.
     * @param description Description of the policy.
     * @param cost Cost of implementing the policy.
     * @param impact Environmental impact value.
     * @param pollutionLimit Pollution limit for the policy.
     */
    EnvironmentalPolicy(const std::string& name, const std::string& description,
                        double cost, double impact, double pollutionLimit);

    /// Implements the policy.
    void implement() override;

    /// Withdraws the policy.
    void withdraw() override;

    /**
     * @brief Calculates the environmental effect of the policy.
     * @return The calculated effect value.
     */
    double calculateEffect() const override;

    /// Checks if the policy is currently implemented.
    bool isImplemented() const { return implemented; }

    /// Sets a new pollution threshold for the policy.
    void setPollutionThreshold(double threshold);

    /// Sets a green space requirement for the policy.
    void setGreenSpaceRequirement(double requirement);

protected:
    /// Applies the policy's effects to the environment.
    void applyEffects() override;

    /// Removes the policy's effects from the environment.
    void removeEffects() override;
};

#endif // ENVIRONMENTALPOLICY_H
