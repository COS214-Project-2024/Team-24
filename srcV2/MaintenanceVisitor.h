#ifndef MAINTENANCEVISITOR_H
#define MAINTENANCEVISITOR_H

#include "BuildingVisitor.h"
#include <string>

// Forward declarations
class Building;
class Residential;
class Commercial;
class Industrial;
class Landmark;

class MaintenanceVisitor : public BuildingVisitor {
public:
    void visitResidential(Residential* residential) override;
    void visitCommercial(Commercial* commercial) override;
    void visitIndustrial(Industrial* industrial) override;
    void visitLandmark(Landmark* landmark) override;

private:
    void performMaintenance(Building* building, const std::string& type);
};

#endif // MAINTENANCEVISITOR_H
