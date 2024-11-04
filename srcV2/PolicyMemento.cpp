#include "PolicyMemento.h"
#include <ctime>
#include <iomanip>
#include <sstream>

PolicyMemento::PolicyMemento(TaxPolicy* tax, ZoningPolicy* zoning, EnvironmentalPolicy* env)
    : taxPolicy(tax)
    , zoningPolicy(zoning)
    , envPolicy(env) {
    // Create timestamp
    auto now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    timestamp = oss.str();
}

TaxPolicy* PolicyMemento::getTaxPolicy() const {
    return taxPolicy;
}

ZoningPolicy* PolicyMemento::getZoningPolicy() const {
    return zoningPolicy;
}

EnvironmentalPolicy* PolicyMemento::getEnvironmentalPolicy() const {
    return envPolicy;
}

const std::string& PolicyMemento::getTimestamp() const {
    return timestamp;
}

void PolicyMemento::implement(const std::string& policy) {
    if (policy == "tax" && taxPolicy) {
        taxPolicy->implement();
    }
    else if (policy == "zoning" && zoningPolicy) {
        zoningPolicy->implement();
    }
    else if (policy == "environmental" && envPolicy) {
        envPolicy->implement();
    }
} 