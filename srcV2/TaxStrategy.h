#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

#include <string>

class TaxStrategy {
public:
    virtual ~TaxStrategy() = default;
    
    // Pure virtual method for calculating tax (note the const)
    virtual double calculateTax(double income) const = 0;
    virtual bool isValidIncome(double income) const;
    virtual std::string getStrategyName() const = 0;

protected:
    TaxStrategy() = default;
};

#endif