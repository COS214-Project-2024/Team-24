#include "Citizen.h"
#include <iostream>
#include <cmath>

Citizen::Citizen(const std::string& citizenName, int citizenAge)
    : name(citizenName)
    , age(citizenAge)
    , health(1.0)
    , happiness(0.5) {
    
    std::cout << "Created citizen " << name << " (Age: " << age << ")" << std::endl;
}

void Citizen::update() {
    updateHappiness();
    
    if (shouldMove()) {
        moveTo(destination);
    }

    // Basic happiness decay over time if homeless
    if (!residence) {
        happiness -= 0.01;
    }

    // Health affects happiness
    happiness *= health;
}

double Citizen::getHappiness() const {
    return happiness;
}

void Citizen::moveTo(const Point& newLocation) {
    // Calculate distance to move
    double dx = newLocation.getX() - location.getX();
    double dy = newLocation.getY() - location.getY();
    double distance = std::sqrt(dx*dx + dy*dy);

    // Move at citizen's speed
    if (distance > speed) {
        double ratio = speed / distance;
        location = Point(
            location.getX() + dx * ratio,
            location.getY() + dy * ratio
        );
    } else {
        location = newLocation;
    }

    std::cout << name << " moved to location (" 
              << location.getX() << "," 
              << location.getY() << ")" << std::endl;
}

void Citizen::setResidence(Building* building) {
    if (building) {
        if (building->canAcceptResident() && building->addResident(this)) {
            if (residence) {
                residence->removeResident(this);
            }
            residence = building;
            location = building->getLocation();
            happiness += 0.1; // Happiness boost from new home
            std::cout << name << " moved into new residence" << std::endl;
        }
    } else if (residence) {
        residence->removeResident(this);
        residence = nullptr;
        happiness -= 0.2; // Significant happiness decrease from losing home
        std::cout << name << " lost residence" << std::endl;
    }
}

void Citizen::notifyBuildingConditionChanged(Building* building) {
    if (building == residence) {
        handleBuildingCondition(building);
    }
}

void Citizen::adjustHealth(double amount) {
    health += amount;
    validateHealth();
    
    if (health < 0.3) {
        std::cout << "Warning: " << name << "'s health is critical!" << std::endl;
    }
}

void Citizen::updateHappiness() {
    // Clamp happiness between 0 and 1
    if (happiness < 0.0) happiness = 0.0;
    if (happiness > 1.0) happiness = 1.0;

    // Log if citizen is very unhappy
    if (happiness < 0.2) {
        std::cout << name << " is very unhappy!" << std::endl;
    }
}

void Citizen::validateHealth() {
    if (health < 0.0) health = 0.0;
    if (health > 1.0) health = 1.0;
}

bool Citizen::shouldMove() const {
    return location != destination && speed > 0;
}

void Citizen::handleBuildingCondition(Building* building) {
    if (!building) return;

    double condition = building->getCondition();
    if (condition < 0.3) {
        // Consider moving out if building is in bad condition
        happiness -= 0.1;
        if (condition < 0.1) {
            setResidence(nullptr); // Move out of dangerous building
        }
    }
}