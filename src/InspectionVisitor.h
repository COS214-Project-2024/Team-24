#ifndef INSPECTIONVISITOR_H
#define INSPECTIONVISITOR_H

#include <vector>
#include <string>
#include "BuildingVisitor.h"
#include "Industrial.h"

class InspectionVisitor : public BuildingVisitor
{
    
    public:
        void visitIndustrial();
        void visitResidential();
        void visitCommercial();
        void visitLandmark();

};

#endif
