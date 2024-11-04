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
     * @brief Constructs a Hig
