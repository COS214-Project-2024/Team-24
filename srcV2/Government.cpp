#include "Government.h"
#include <iostream>
#include <algorithm>

Government::Government(const std::string& name)
    : cityName(name)
    , treasuryBalance(10000.0)  // Starting funds
    , approvalRating(50.0) {    // Starting approval rating
    
    std::cout << "Government established for " << cityName << std::endl;
    
    // Initialize basic service funding
    serviceFunding["infrastructure"] = 1000.0;
    serviceFunding["education"] = 1000.0;
    serviceFunding["healthcare"] = 1000.0;
}

void Government::collectTaxes() {
    double revenue = calculateTaxRevenue();
    treasuryBalance += revenue;
    
    std::cout << "Collected " << revenue << " in taxes. New balance: " 
              << treasuryBalance << std::endl;
}

void Government::updateBudget() {
    // Deduct service costs
    for (const auto& [service, funding] : serviceFunding) {
        treasuryBalance -= funding;
    }
    
    std::cout << "Updated budget. New treasury balance: " << treasuryBalance << std::endl;
}

void Government::adjustTaxRate(const std::string& taxType, double newRate) {
    if (newRate < 0.0 || newRate > 1.0) {
        std::cout << "Invalid tax rate. Must be between 0 and 1" << std::endl;
        return;
    }

    auto it = taxRates.find(taxType);
    if (it != taxRates.end()) {
        it->second = newRate;
        std::cout << "Adjusted " << taxType << " tax rate to " << newRate << std::endl;
    }
}

double Government::getTaxRate(const std::string& taxType) const {
    auto it = taxRates.find(taxType);
    return (it != taxRates.end()) ? it->second : 0.0;
}

void Government::setServiceFunding(const std::string& service, double amount) {
    if (amount < 0.0) {
        std::cout << "Cannot set negative funding amount" << std::endl;
        return;
    }

    serviceFunding[service] = amount;
    std::cout << "Set " << service << " funding to " << amount << std::endl;
}

double Government::getServiceLevel(const std::string& service) const {
    auto it = serviceFunding.find(service);
    return (it != serviceFunding.end()) ? it->second : 0.0;
}

double Government::calculateTaxRevenue() {
    double totalRevenue = 0.0;
    
    for (const auto& [type, rate] : taxRates) {
        // Simple calculation based on tax rates
        double typeRevenue = rate * 1000.0;  // Base value for each type
        totalRevenue += typeRevenue;
    }
    
    return totalRevenue;
}

void Government::updateStatistics() {
    statistics.addDataPoint("treasury_balance", treasuryBalance);
    statistics.addDataPoint("approval_rating", approvalRating);
    
    for (const auto& [type, rate] : taxRates) {
        statistics.addDataPoint(type + "_tax_rate", rate);
    }
}

void Government::setPolicy(const std::string& policyName, bool active) {
    activePolicies[policyName] = active;
    std::cout << "Policy '" << policyName << "' set to " 
              << (active ? "active" : "inactive") << std::endl;
    
    // Update approval based on policy change
    calculateApprovalImpact(policyName, active ? 5.0 : -5.0);
}

bool Government::isPolicyActive(const std::string& policyName) const {
    auto it = activePolicies.find(policyName);
    return (it != activePolicies.end()) ? it->second : false;
}

void Government::updatePolicies() {
    adjustBudgetForPolicies();
    updateServiceLevels();
    updateApprovalRating();
}

void Government::updateApprovalRating() {
    // Base approval changes on:
    // 1. Service levels
    double serviceApproval = 0.0;
    for (const auto& [service, funding] : serviceFunding) {
        serviceApproval += funding / 1000.0;  // Normalize to 0-1 range
    }
    
    // 2. Tax rates (lower = better approval)
    double taxApproval = 0.0;
    for (const auto& [type, rate] : taxRates) {
        taxApproval += (1.0 - rate);  // Inverse of tax rate
    }
    
    // Update approval rating (0-100 scale)
    approvalRating = std::clamp(
        (serviceApproval * 50.0 + taxApproval * 50.0) / 
        (serviceFunding.size() + taxRates.size()),
        0.0, 100.0
    );
}

void Government::provideCityServices() {
    for (const auto& [service, funding] : serviceFunding) {
        if (funding > 0 && treasuryBalance >= funding) {
            treasuryBalance -= funding;
            calculateApprovalImpact(service, funding / 1000.0);
        } else {
            std::cout << "Warning: Insufficient funds for " << service << std::endl;
            calculateApprovalImpact(service, -5.0);
        }
    }
}

void Government::calculateApprovalImpact(const std::string& event, double magnitude) {
    approvalRating = std::clamp(approvalRating + magnitude, 0.0, 100.0);
}

void Government::adjustBudgetForPolicies() {
    for (const auto& [policy, active] : activePolicies) {
        if (active) {
            // Apply policy costs/benefits
            double policyCost = 100.0;  // Base cost for policies
            treasuryBalance -= policyCost;
        }
    }
}

void Government::updateServiceLevels() {
    for (auto& [service, funding] : serviceFunding) {
        // Adjust service levels based on funding and policies
        if (funding < 500.0) {
            calculateApprovalImpact(service, -2.0);
        } else if (funding > 2000.0) {
            calculateApprovalImpact(service, 1.0);
        }
    }
}