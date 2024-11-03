#ifndef MAINTENANCEVISITOR_H
#define MAINTENANCEVISITOR_H

#include <vector>
#include <string>
#include "BuildingVisitor.h"

class MaintenanceVisitor : public BuildingVisitor
{
    
    public:
        void visitIndustrial(Industrial* building);
        void visitResidential(Residential* building);
        void visitCommercial(Commercial* building);
        void visitLandmark(Landmark* building);
};

#endif
