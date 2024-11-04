#ifndef INSPECTIONVISITOR_H
#define INSPECTIONVISITOR_H

#include "BuildingVisitor.h"

class InspectionVisitor : public BuildingVisitor {
public:
    void visitResidential(Residential* residential) override;
    void visitCommercial(Commercial* commercial) override;
    void visitIndustrial(Industrial* industrial) override;
    void visitLandmark(Landmark* landmark) override;
};

#endif // INSPECTIONVISITOR_H
