#ifndef BUILDINGVISITOR_H
#define BUILDINGVISITOR_H

#include <vector>
#include <string>
#include "Building.h"

class BuildingVisitor
{

    public:
        virtual void visitIndustrial() = 0;
        virtual void visitResidential() = 0;
        virtual void visitCommercial() = 0;
        virtual void visitLandmark() = 0;

};

#endif
