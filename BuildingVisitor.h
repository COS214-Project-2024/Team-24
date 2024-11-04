#ifndef BUILDINGVISITOR_H
#define BUILDINGVISITOR_H

class Residential;
class Commercial;
class Industrial;
class Landmark;

/**
 * @class BuildingVisitor
 * @brief Abstract class for implementing the Visitor pattern on different Building types.
 *
 * This class defines visit functions for various types of buildings (e.g., Residential,
 * Commercial), allowing operations to be performed on these building types
 * without modifying their structure.
 */
class BuildingVisitor {
public:
    /// Virtual destructor for cleanup in derived classes.
    virtual ~BuildingVisitor();

    /**
     * @brief Visit function for Residential buildings.
     * @param residential Pointer to the Residential building.
     */
    virtual void visitResidential(Residential* residential) = 0;

    /**
     * @brief Visit function for Commercial buildings.
     * @param commercial Pointer to the Commercial building.
     */
    virtual void visitCommercial(Commercial* commercial) = 0;

    /**
     * @brief Visit function for Industrial buildings.
     * @param industrial Pointer to the Industrial building.
     */
    virtual void visitIndustrial(Industrial* industrial) = 0;

    /**
     * @brief Visit function for Landmark buildings.
     * @param landmark Pointer to the Landmark building.
     */
    virtual void visitLandmark(Landmark* landmark) = 0;
};

#endif // BUILDINGVISITOR_H
