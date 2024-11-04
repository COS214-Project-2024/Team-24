#ifndef POLICY_H
#define POLICY_H

#include <string>

class Policy {
    
protected:
    std::string name;
    std::string description;
    double cost;
    double impact;
    bool isActive{false};
    bool isImplemented{false};
public:
    // Constructor
    Policy(const std::string& name, const std::string& description, 
           double cost, double impact);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getCost() const;
    double getImpact() const;
    bool getIsActive() const;

    virtual void applyEffects() = 0;
    virtual void removeEffects() = 0;

    // Setters
    void setActive(bool active);
    
    // Pure virtual methods
    virtual void implement() = 0;
    virtual void withdraw() = 0;
    virtual double calculateEffect() const = 0;

    // Virtual destructor
    virtual ~Policy() = default;
};

#endif // POLICY_H 