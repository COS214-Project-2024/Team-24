#ifndef LOWINCOMETAXSTRATEGY_H
#define LOWINCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

class LowIncomeTaxStrategy : public TaxStrategy {
private:
    double taxRate;
    double incomeThreshold;

public:
    explicit LowIncomeTaxStrategy(double rate = 0.15) 
        : taxRate(rate)
        , incomeThreshold(30000.0) {}

    double calculateTax(double income) const override;
    bool isValidIncome(double income) const override;
    std::string getStrategyName() const override { return "Low Income Tax"; }
};

#endif