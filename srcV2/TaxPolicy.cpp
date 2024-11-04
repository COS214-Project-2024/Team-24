#include "TaxPolicy.h"
#include <iostream>

TaxPolicy::TaxPolicy(const std::string& name, const std::string& description,
                     double cost, double impact, double rate, const std::string& type)
    : Policy(name, description, cost, impact)
    , taxRate(rate)
    , taxType(type) {
}

void TaxPolicy::implement() {
    if (!isImplemented) {
        applyEffects();
        isImplemented = true;
        std::cout << "Implemented tax policy: " << name << std::endl;
    }
}

void TaxPolicy::withdraw() {
    if (isImplemented) {
        removeEffects();
        isImplemented = false;
        std::cout << "Withdrawn tax policy: " << name << std::endl;
    }
}

void TaxPolicy::applyEffects() {
    // Apply tax rate changes
    isActive = true;
    std::cout << "Applied tax effects for: " << name << std::endl;
}

void TaxPolicy::removeEffects() {
    // Remove tax rate changes
    isActive = false;
    std::cout << "Removed tax effects for: " << name << std::endl;
}

double TaxPolicy::calculateEffect() const {
    return taxRate * impact;
}

double TaxPolicy::getTaxRate() const {
    return taxRate;
}

void TaxPolicy::setTaxRate(double newRate) {
    taxRate = newRate;
}