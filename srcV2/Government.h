#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <map>
#include <vector>
#include "Statistics.h"

/**
 * @class Government
 * @brief Manages city policies, finances, and services, maintaining a balanced economy.
 *
 * The Government class collects taxes, manages policies, adjusts city services, and
 * keeps track of city statistics, approval ratings, and budget.
 */
class Government {
public:
    /**
     * @brief Constructs a Government instance for a city.
     * @param cityName The name of the city.
     */
    Government(const std::string& cityName);

    /// Collects taxes from different sectors.
    void collectTaxes();

    /// Updates the city budget based on expenses and revenue.
    void updateBudget();

    /**
     * @brief Adjusts the tax rate for a specific type.
     * @param taxType The type of tax to adjust.
     * @param newRate The new tax rate.
     */
    void adjustTaxRate(const std::string& taxType, double newRate);

    /**
     * @brief Gets the current tax rate for a given type.
     * @param taxType The tax type to retrieve.
     * @return The tax rate for the specified type.
     */
    double getTaxRate(const std::string& taxType) const;

    /// Returns the current balance in the treasury.
    double getTreasuryBalance() const { return treasuryBalance; }

    /**
     * @brief Activates or deactivates a policy.
     * @param policyName The name of the policy.
     * @param active True to activate, false to deactivate.
     */
    void setPolicy(const std::string& policyName, bool active);

    /**
     * @brief Checks if a policy is currently active.
     * @param policyName The name of the policy.
     * @return True if active, false otherwise.
     */
    bool isPolicyActive(const std::string& policyName) const;

    /// Updates the statuses of active policies.
    void updatePolicies();

    /// Returns the current approval rating of the government.
    double getApprovalRating() const { return approvalRating; }

    /// Updates the approval rating based on current factors.
    void updateApprovalRating();

    /// Provides city services and adjusts service levels.
    void provideCityServices();

    /**
     * @brief Gets the funding level for a specific service.
     * @param service The name of the service.
     * @return The funding level of the service.
     */
    double getServiceLevel(const std::string& service) const;

    /**
     * @brief Sets the funding for a specified service.
     * @param service The name of the service.
     * @param amount The funding amount.
     */
    void setServiceFunding(const std::string& service, do
