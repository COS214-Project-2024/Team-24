#ifndef MAINTENANCEVISITOR_H
#define MAINTENANCEVISITOR_H

#include <vector>
#include <string>
#include "BuildingVisitor.h"

class MaintenanceVisitor : public BuildingVisitor
{
    
    public:
        void visitIndustrial();
        void visitResidential();
        void visitCommercial();
        void visitLandmark();

};

#endif
