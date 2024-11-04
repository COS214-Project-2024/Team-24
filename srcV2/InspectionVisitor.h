#ifndef INSPECTIONVISITOR_H
#define INSPECTIONVISITOR_H

#include "BuildingVisitor.h"

/**
 * @brief Visitor class for inspecting different types of buildings.
 */
class InspectionVisitor : public BuildingVisitor {
public:
    /**
     * @brief Visits a Residential building.
     * @param residential Pointer to the Residential building.
     */
    void visitResidential(Residential* residential) override;

    /**
     * @brief Visits a Commercial building.
     * @param commercial Pointer to the Commercial building.
     */
    void visitCommercial(Commercial* commercial) override;

    /**
     * @brief Visits an Industrial building.
     * @param industrial Pointer to the Industrial building.
     */
    void visitIndustrial(Industrial* industrial) override;

    /**
     * @brief Visits a Landmark building.
     * @param landmark Pointer to the Landmark building.
     */
    void visitLandmark(Landmark* landmark) override;
};

#endif // INSPECTIONVISITOR_H
