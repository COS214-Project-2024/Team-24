#ifndef BUILDINGVISITOR_H
#define BUILDINGVISITOR_H

class Residential;
class Commercial;
class Industrial;
class Landmark;

class BuildingVisitor {
public:
    virtual ~BuildingVisitor();
    virtual void visitResidential(Residential* residential) = 0;
    virtual void visitCommercial(Commercial* commercial) = 0;
    virtual void visitIndustrial(Industrial* industrial) = 0;
    virtual void visitLandmark(Landmark* landmark) = 0;
};

#endif
