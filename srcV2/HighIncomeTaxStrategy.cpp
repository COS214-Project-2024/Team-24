#include "HighIncomeTaxStrategy.h"

double HighIncomeTaxStrategy::calculateTax(double income) const {
    if (income <= incomeThreshold) {
        return 0.0;  // Below threshold, no high income tax
    }
    return (income - incomeThreshold) * taxRate;
}

bool HighIncomeTaxStrategy::isValidIncome(double income) const {
    return TaxStrategy::isValidIncome(income);
}

