#include "CitizenManager.h"
#include <algorithm>
#include <numeric>
#include <random>
#include <iostream>

std::unique_ptr<Citizen> CitizenManager::createCitizen(const std::string& name) {
    // Generate random age between 18 and 80
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> age_dist(18, 80);
    int age = age_dist(gen);

    auto newCitizen = std::make_unique<Citizen>(name, age);
    citizens.push_back(std::move(newCitizen));
    return std::make_unique<Citizen>(name, age);
}

void CitizenManager::updateCitizens() {
    for (auto& citizen : citizens) {
        if (citizen) {
            citizen->update();  // Basic update for each citizen
        }
    }
}


void CitizenManager::handleCitizenNeeds() {
    for (auto& citizen : citizens) {
        if (citizen) {
            // Check if citizen needs housing
            if (!citizen->hasHome()) {
                // Logic to find housing could be added here
                std::cout << "Citizen " << citizen->getName() << " needs housing" << std::endl;
            }

            // Check health
            if (!citizen->isHealthy()) {
                citizen->adjustHealth(0.1);  // Try to improve health
            }
        }
    }
}

double CitizenManager::calculateHappiness() const {
    if (citizens.empty()) return 0.0;

    double totalHappiness = std::accumulate(citizens.begin(), citizens.end(), 0.0,
        [](double sum, const std::unique_ptr<Citizen>& citizen) {
            return sum + citizen->getHappiness();
        });

    return totalHappiness / citizens.size();
}


void CitizenManager::removeCitizen(long id) {
    citizens.erase(
        std::remove_if(citizens.begin(), citizens.end(),
            [id](const std::unique_ptr<Citizen>& citizen) {
                // Since we don't have getId(), we'll use name length as a simple example
                // In a real implementation, you'd want to add an ID field to Citizen
                return citizen->getName().length() == id;
            }),
        citizens.end()
    );
} 