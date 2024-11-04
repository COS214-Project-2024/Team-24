#include "LowIncomeTaxStrategy.h"

double LowIncomeTaxStrategy::calculateTax(double income) const {
    if (income >= incomeThreshold) {
        return 0.0;  // Above threshold, not eligible for low income tax
    }
    return income * taxRate;
}

bool LowIncomeTaxStrategy::isValidIncome(double income) const {
    return TaxStrategy::isValidIncome(income);
}


