#ifndef INSPECTIONVISITOR_H
#define INSPECTIONVISITOR_H

#include <vector>
#include <string>
#include "BuildingVisitor.h"
#include "Industrial.h"

class InspectionVisitor : public BuildingVisitor
{
    
    public:
        void visitIndustrial(Industrial* building);
        void visitResidential(Residential* building);
        void visitCommercial(Commercial* building);
        void visitLandmark(Landmark* building);

};

#endif
