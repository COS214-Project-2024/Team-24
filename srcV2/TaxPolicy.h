#ifndef TAXPOLICY_H
#define TAXPOLICY_H

#include "Policy.h"

class TaxPolicy : public Policy {
private:
    double taxRate{0.0};
    std::string taxType;  // e.g., "income", "property", "sales"

public:
    TaxPolicy(const std::string& name, const std::string& description,
              double cost, double impact, double rate, const std::string& type);

    // Implement pure virtual methods
    void implement() override;
    void withdraw() override;
    double calculateEffect() const override;

    // Additional methods
    double getTaxRate() const;
    void setTaxRate(double newRate);

    protected:
    // Add these protected methods
    void applyEffects() override;
    void removeEffects() override;
};

#endif 