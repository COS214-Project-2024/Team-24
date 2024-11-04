#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <map>
#include <vector>
#include "Statistics.h"

/**
 * @class Government
 * @brief Manages the finances, policies, services, and overall management of a city.
 *
 * The Government class provides methods to manage the city's budget, tax rates, policies,
 * services, and approval rating. It tracks various statistics and ensures efficient city operations.
 */
class Government {
public:
    /**
     * @brief Constructs a Government object for a specified city.
     * @param cityName The name of the city this government manages.
     */
    Government(const std::string& cityName);

    // Financial management

    /**
     * @brief Collects taxes from various sectors and updates treasury balance.
     */
    void collectTaxes();

    /**
     * @brief Updates the budget by calculating revenue and adjusting for expenses.
     */
    void updateBudget();

    /**
     * @brief Adjusts the tax rate for a specific type (e.g., residential, commercial).
     * @param taxType The type of tax to adjust.
     * @param newRate The new tax rate for the specified type.
     */
    void adjustTaxRate(const std::string& taxType, double newRate);

    /**
     * @brief Gets the tax rate for a specific category.
     * @param taxType The type of tax to retrieve.
     * @return The current tax rate for the specified type.
     */
    double getTaxRate(const std::string& taxType) const;

    /**
     * @brief Retrieves the current treasury balance.
     * @return The balance in the treasury.
     */
    double getTreasuryBalance() const { return treasuryBalance; }

    // Policy management

    /**
     * @brief Activates or deactivates a specific policy.
     * @param policyName The name of the policy to modify.
     * @param active True to activate, false to deactivate.
     */
    void setPolicy(const std::string& policyName, bool active);

    /**
     * @brief Checks if a specific policy is currently active.
     * @param policyName The name of the policy to check.
     * @return True if the policy is active, false otherwise.
     */
    bool isPolicyActive(const std::string& policyName) const;

    /**
     * @brief Updates all active policies, applying their effects on the city.
     */
    void updatePolicies();

    // Approval rating

    /**
     * @brief Gets the current approval rating of the government.
     * @return The approval rating, scaled from 0 to 100.
     */
    double getApprovalRating() const { return approvalRating; }

    /**
     * @brief Updates the government's approval rating based on recent events and policy impacts.
     */
    void updateApprovalRating();

    // City management

    /**
     * @brief Provides essential city services to citizens and adjusts funding as necessary.
     */
    void provideCityServices();

    /**
     * @brief Gets the current funding level for a specified city service.
     * @param service The name of the service.
     * @return The funding level for the specified service.
     */
    double getServiceLevel(const std::string& service) const;

    /**
     * @brief Sets the funding level for a specific city service.
     * @param service The name of the service.
     * @param amount The funding amount to allocate.
     */
    void setServiceFunding(const std::string& service, double amount);

    // Statistics

    /**
     * @brief Gets a reference to the current city statistics.
     * @return A reference to a Statistics object containing the city's data.
     */
    const Statistics& getStatistics() const { return statistics; }

    /**
     * @brief Updates the city's statistics based on recent events and changes.
     */
    void updateStatistics();

private:
    std::string cityName;                 ///< The name of the city.
    double treasuryBalance{0.0};          ///< The city's current treasury balance.
    double approvalRating{50.0};          ///< Government's approval rating (0-100 scale).

    /// Tax rates for different categories (residential, commercial, industrial).
    std::map<std::string, double> taxRates{
        {"residential", 0.05},
        {"commercial", 0.07},
        {"industrial", 0.06}
    };

    /// Tracks the active or inactive status of various policies.
    std::map<std::string, bool> activePolicies;

    /// Funding levels for different city services.
    std::map<std::string, double> serviceFunding;

    Statistics statistics;                ///< Contains various statistics for the city.

    // Private utility methods

    /**
     * @brief Calculates the impact of an event on the approval rating.
     * @param event The event affecting approval rating.
     * @param magnitude The magnitude of impact on approval.
     */
    void calculateApprovalImpact(const std::string& event, double magnitude);

    /**
     * @brief Adjusts the city budget based on active policies.
     */
    void adjustBudgetForPolicies();

    /**
     * @brief Calculates tax revenue based on current tax rates and applicable policies.
     * @return The calculated tax revenue.
     */
    double calculateTaxRevenue();

    /**
     * @brief Updates service levels based on available funding and policy influences.
     */
    void updateServiceLevels();
};

#endif // GOVERNMENT_H
