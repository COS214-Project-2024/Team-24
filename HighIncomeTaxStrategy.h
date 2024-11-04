#ifndef HIGHINCOMETAXSTRATEGY_H
#define HIGHINCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @class HighIncomeTaxStrategy
 * @brief Tax strategy for individuals with high income.
 *
 * This strategy applies a higher tax rate to individuals exceeding
 * a defined income threshold, aiming to increase revenue from high earners.
 */
class HighIncomeTaxStrategy : public TaxStrategy {
private:
    double taxRate;            ///< Tax rate for high income earners.
    double incomeThreshold;    ///< Minimum income to qualify for high income tax.

public:
    /**
     * @brief Constructs a HighIncomeTaxStrategy with a specified rate.
     * @param rate The tax rate for high income individuals (default is 0.35).
     */
    explicit HighIncomeTaxStrategy(double rate = 0.35);

    /**
     * @brief Calculates tax for a given income based on the strategy.
     * @param income The income to tax.
     * @return The calculated tax amount.
     */
    double calculateTax(double income) const override;

    /**
     * @brief Checks if an income level qualifies for this tax strategy.
     * @param income The income level to check.
     * @return True if income qualifies, false otherwise.
     */
    bool isValidIncome(double income) const override;

    /// Returns the name of the tax strategy.
    std::string getStrategyName() const override { return "High Income Tax"; }
};

#endif // HIGHINCOMETAXSTRATEGY_H
