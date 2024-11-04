#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <map>
#include <vector>
#include "Statistics.h"

class Government {
public:
    Government(const std::string& cityName);
    
    // Financial management
    void collectTaxes();
    void updateBudget();
    void adjustTaxRate(const std::string& taxType, double newRate);
    double getTaxRate(const std::string& taxType) const;
    double getTreasuryBalance() const { return treasuryBalance; }
    
    // Policy management
    void setPolicy(const std::string& policyName, bool active);
    bool isPolicyActive(const std::string& policyName) const;
    void updatePolicies();
    
    // Approval rating
    double getApprovalRating() const { return approvalRating; }
    void updateApprovalRating();
    
    // City management
    void provideCityServices();
    double getServiceLevel(const std::string& service) const;
    void setServiceFunding(const std::string& service, double amount);
    
    // Statistics
    const Statistics& getStatistics() const { return statistics; }
    void updateStatistics();

private:
    std::string cityName;
    double treasuryBalance{0.0};
    double approvalRating{50.0};  // 0-100 scale
    
    // Tax rates for different categories
    std::map<std::string, double> taxRates{
        {"residential", 0.05},
        {"commercial", 0.07},
        {"industrial", 0.06}
    };
    
    // Active policies
    std::map<std::string, bool> activePolicies;
    
    // City services and their funding levels
    std::map<std::string, double> serviceFunding;
    
    // Statistics tracking
    Statistics statistics;
    
    // Private utility methods
    void calculateApprovalImpact(const std::string& event, double magnitude);
    void adjustBudgetForPolicies();
    double calculateTaxRevenue();
    void updateServiceLevels();
};

#endif // GOVERNMENT_H
