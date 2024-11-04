#include "InspectionVisitor.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include <iostream>

void InspectionVisitor::visitResidential(Residential* residential) {
    if (!residential) return;
    std::cout << "Inspecting Residential Building:\n"
              << "- Occupancy Rate: " << residential->getOccupancyRate() * 100.0 << "%\n"
              << "- Comfort Level: " << residential->getComfortLevel() << "/100\n"
              << "- Satisfaction: " << residential->getSatisfactionLevel() << "/100\n"
              << "- Parking Available: " << (residential->hasAvailableParking() ? "Yes" : "No") << "\n";
}

void InspectionVisitor::visitCommercial(Commercial* commercial) {
    if (!commercial) return;
    std::cout << "Inspecting Commercial Building:\n"
              << "- Revenue: $" << commercial->getRevenue() << "\n"
              << "- Current Customers: " << commercial->getCurrentCustomers() << " customers\n"
              << "- Retail Efficiency: " << commercial->getRetailEfficiency() * 100.0 << "%\n";
}

void InspectionVisitor::visitIndustrial(Industrial* industrial) {
    if (!industrial) return;
    std::cout << "Inspecting Industrial Building:\n"
              << "- Pollution Level: " << industrial->getPollutionLevel() << " units\n"
              << "- Production Rate: " << industrial->getProductionRate() << " units/day\n"
              << "- Product Type: " << industrial->getProductType() << "\n";
}

void InspectionVisitor::visitLandmark(Landmark* landmark) {
    if (!landmark) return;
    std::cout << "Inspecting Landmark Building\n"
              << "- Condition: " << landmark->getCondition() * 100.0 << "%\n"
              << "- Building Type: " << landmark->getBuildingType() << "\n";
} 