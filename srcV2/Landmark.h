#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"
#include "BuildingVisitor.h"

/**
 * @brief Represents a landmark building with tourism value.
 */
class Landmark : public Building {
public:
    /**
     * @brief Constructs a Landmark building with the given name and location.
     * @param name The name of the building.
     * @param location The location of the building.
     */
    Landmark(const std::string& name, const Point& location);
    
    /**
     * @brief Updates the state of the landmark.
     */
    void update() override;

    /**
     * @brief Consumes resources required for the landmark.
     */
    void consumeResources() override;

    /**
     * @brief Checks if there are enough resources for the landmark.
     * @return True if there are enough resources, false otherwise.
     */
    bool hasEnoughResources() const override;

    /**
     * @brief Performs maintenance on the landmark.
     */
    void maintain() override;

    /**
     * @brief Accepts a visitor for processing.
     * @param visitor The visitor to accept.
     */
    void accept(BuildingVisitor* visitor) override;

    /**
     * @brief Gets the tourism value of the landmark.
     * @return The tourism value.
     */
    double getTourismValue() const;

    /**
     * @brief Gets the type of the landmark.
     * @return The landmark type.
     */
    std::string getLandmarkType() const;

    /**
     * @brief Gets the current number of visitors.
     * @return The visitor count.
     */
    int getVisitorCount() const;

private:
    /**
     * @brief Updates the number of visitors.
     */
    void updateVisitors();

    double powerConsumption{15.0}; ///< Power consumption of the landmark.
    double waterConsumption{10.0}; ///< Water consumption of the landmark.
    double baseTourismValue{100.0}; ///< Base tourism value of the landmark.
    int currentVisitors{0}; ///< Current number of visitors.
    std::string landmarkType{"Historical"}; ///< Type of landmark.
};

#endif // LANDMARK_H
