#ifndef BUDGET_H
#define BUDGET_H

#include <map>
#include <string>
#include <sstream>

class Budget {
public:
    // Constructor
    Budget(double initialBalance = 0.0);

    // Fund management
    bool allocateFunds(const std::string& department, double amount);
    void addFunds(double amount);
    bool spendFunds(double amount);
    
    // Revenue management
    void collectRevenue(double amount);
    void setTaxRate(double rate);
    
    // Getters
    double getBalance() const { return balance; }
    double getTaxRate() const { return taxRate; }
    double getDepartmentAllocation(const std::string& department) const;
    
    // Reporting
    std::string generateReport() const;
    void update();

private:
    double balance;
    double taxRate{0.1};  // 10% default tax rate
    double reserves{0.0};
    
    std::map<std::string, double> allocations;
    
    // Utility methods
    bool hasSufficientFunds(double amount) const;
    void initializeDepartments();
};

#endif
