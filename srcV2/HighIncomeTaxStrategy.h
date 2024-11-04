#ifndef HIGHINCOMETAXSTRATEGY_H
#define HIGHINCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

class HighIncomeTaxStrategy : public TaxStrategy {
private:
    double taxRate;
    double incomeThreshold;

public:
    explicit HighIncomeTaxStrategy(double rate = 0.35) 
        : taxRate(rate)
        , incomeThreshold(100000.0) {}

    double calculateTax(double income) const override;
    bool isValidIncome(double income) const override;
    std::string getStrategyName() const override { return "High Income Tax"; }
};

#endif