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

/**
 * @brief Visitor class for performing maintenance on buildings.
 */
class MaintenanceVisitor : public BuildingVisitor {
public:
    /**
     * @brief Visits a Residential building for maintenance.
     * @param residential Pointer to the Residential building.
     */
    void visitResidential(Residential* residential) override;

    /**
     * @brief Visits a Commercial building for maintenance.
     * @param commercial Pointer to the Commercial building.
     */
    void visitCommercial(Commercial* commercial) override;

    /**
     * @brief Visits an Industrial building for maintenance.
     * @param industrial Pointer to the Industrial building.
     */
    void visitIndustrial(Industrial* industrial) override;

    /**
     * @brief Visits a Landmark building for maintenance.
     * @param landmark Pointer to the Landmark building.
     */
    void visitLandmark(Landmark* landmark) override;

private:
    /**
     * @brief Performs maintenance on a given building.
     * @param building The building to maintain.
     * @param type The type of maintenance to perform.
     */
    void performMaintenance(Building* building, const std::string& type);
};

#endif // MAINTENANCEVISITOR_H
