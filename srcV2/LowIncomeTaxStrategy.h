#ifndef LOWINCOMETAXSTRATEGY_H
#define LOWINCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Tax strategy for low-income individuals.
 */
class LowIncomeTaxStrategy : public TaxStrategy {
private:
    double taxRate; ///< Tax rate for low-income.
    double incomeThreshold; ///< Income threshold for the tax strategy.

public:
    /**
     * @brief Constructs a LowIncomeTaxStrategy with a specified tax rate.
     * @param rate The tax rate, default is 0.15.
     */
    explicit LowIncomeTaxStrategy(double rate = 0.15) 
        : taxRate(rate), incomeThreshold(30000.0) {}

    /**
     * @brief Calculates the tax based on income.
     * @param income The income to calculate tax for.
     * @return The calculated tax.
     */
    double calculateTax(double income) const override;

    /**
     * @brief Checks if the income is valid for the strategy.
     * @param income The income to validate.
     * @return True if valid, false otherwise.
     */
    bool isValidIncome(double income) const override;

    /**
     * @brief Gets the name of the tax strategy.
     * @return The name of the strategy.
     */
    std::string getStrategyName() const override { return "Low Income Tax"; }
};

#endif // LOWINCOMETAXSTRATEGY_H
