// PolicyMemento.h
#ifndef POLICYMEMENTO_H
#define POLICYMEMENTO_H

#include <string>
#include "TaxPolicy.h"
#include "ZoningPolicy.h"
#include "EnvironmentalPolicy.h"

class PolicyMemento {
private:
    std::string timestamp;  // When the memento was created
    
    // Store the actual policy objects
    TaxPolicy* taxPolicy;
    ZoningPolicy* zoningPolicy;
    EnvironmentalPolicy* envPolicy;

public:
    // Constructor
    PolicyMemento(TaxPolicy* tax = nullptr, 
                 ZoningPolicy* zoning = nullptr,
                 EnvironmentalPolicy* env = nullptr);
    
    // Getters
    TaxPolicy* getTaxPolicy() const;
    ZoningPolicy* getZoningPolicy() const;
    EnvironmentalPolicy* getEnvironmentalPolicy() const;
    const std::string& getTimestamp() const;
    void implement(const std::string& policy);
};

#endif // POLICYMEMENTO_H
