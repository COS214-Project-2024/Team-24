#ifndef BUILDINGVISITOR_H
#define BUILDINGVISITOR_H

#include <vector>
#include <string>

class Industrial;
class Residential;
class Commercial;
class Landmark;

class BuildingVisitor
{

    public:
        virtual void visitIndustrial(Industrial* building) = 0;
        virtual void visitResidential(Residential* building) = 0;
        virtual void visitCommercial(Commercial* building) = 0;
        virtual void visitLandmark(Landmark* building) = 0;

};

#endif
