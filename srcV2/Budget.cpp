#include "Budget.h"
#include <iostream>
#include <iomanip>

Budget::Budget(double initialBalance) 
    : balance(initialBalance) {
    initializeDepartments();
}

void Budget::initializeDepartments() {
    allocations["Infrastructure"] = 0.0;
    allocations["Education"] = 0.0;
    allocations["Healthcare"] = 0.0;
    allocations["Emergency"] = 0.0;
}

bool Budget::allocateFunds(const std::string& department, double amount) {
    if (!hasSufficientFunds(amount)) {
        std::cout << "Insufficient funds for allocation to " << department << std::endl;
        return false;
    }

    allocations[department] = amount;
    balance -= amount;
    
    std::cout << "Allocated $" << std::fixed << std::setprecision(2) 
              << amount << " to " << department << std::endl;
    return true;
}

void Budget::addFunds(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Added $" << std::fixed << std::setprecision(2) 
                  << amount << " to budget" << std::endl;
    }
}

bool Budget::spendFunds(double amount) {
    if (!hasSufficientFunds(amount)) {
        std::cout << "Insufficient funds for expenditure" << std::endl;
        return false;
    }

    balance -= amount;
    return true;
}

void Budget::collectRevenue(double amount) {
    double taxedAmount = amount * taxRate;
    balance += taxedAmount;
    
    std::cout << "Collected $" << std::fixed << std::setprecision(2) 
              << taxedAmount << " in revenue" << std::endl;
}

void Budget::setTaxRate(double rate) {
    if (rate >= 0.0 && rate <= 1.0) {
        taxRate = rate;
        std::cout << "Tax rate set to " << (rate * 100) << "%" << std::endl;
    }
}

double Budget::getDepartmentAllocation(const std::string& department) const {
    auto it = allocations.find(department);
    return (it != allocations.end()) ? it->second : 0.0;
}

std::string Budget::generateReport() const {
    std::stringstream report;
    report << std::fixed << std::setprecision(2);
    report << "Budget Report\n";
    report << "-------------\n";
    report << "Current Balance: $" << balance << "\n";
    report << "Tax Rate: " << (taxRate * 100) << "%\n";
    report << "Reserves: $" << reserves << "\n\n";
    report << "Department Allocations:\n";
    
    for (const auto& [department, amount] : allocations) {
        report << department << ": $" << amount << "\n";
    }
    
    return report.str();
}

void Budget::update() {
    // Update reserves and other periodic calculations
    reserves = balance * 0.1;  // Keep 10% as reserves
}

bool Budget::hasSufficientFunds(double amount) const {
    return (balance - reserves) >= amount;
}
