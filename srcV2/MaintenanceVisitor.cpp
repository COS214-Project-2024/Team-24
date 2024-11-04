#include "MaintenanceVisitor.h"
#include "Building.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include <iostream>

void MaintenanceVisitor::visitResidential(Residential* residential) {
    if (!residential) return;
    performMaintenance(residential, "Residential");
}

void MaintenanceVisitor::visitCommercial(Commercial* commercial) {
    if (!commercial) return;
    performMaintenance(commercial, "Commercial");
}

void MaintenanceVisitor::visitIndustrial(Industrial* industrial) {
    if (!industrial) return;
    performMaintenance(industrial, "Industrial");
}

void MaintenanceVisitor::visitLandmark(Landmark* landmark) {
    if (!landmark) return;
    performMaintenance(landmark, "Landmark");
}

void MaintenanceVisitor::performMaintenance(Building* building, const std::string& type) {
    if (!building) return;

    double oldCondition = building->getCondition();
    building->maintain();
    double newCondition = building->getCondition();

    std::cout << type << " Building Maintenance Report:\n"
              << "- Previous Condition: " << (oldCondition * 100.0) << "%\n"
              << "- New Condition: " << (newCondition * 100.0) << "%\n"
              << "- Improvement: " << ((newCondition - oldCondition) * 100.0) << "%\n"
              << std::endl;
} 