#include <gtest/gtest.h>
#include "../src/Landmark.h"
#include "../src/Point.h"
#include "../src/BuildingVisitor.h"

class LandmarkTests : public ::testing::Test {
protected:
    Landmark* building;
    Point location;

    void SetUp() override {
        location = Point(1, 1);
        building = new Landmark("Historic Tower", location);
    }

    void TearDown() override {
        delete building;
    }
};

// Test basic landmark creation
TEST_F(LandmarkTests, Creation) {
    EXPECT_EQ(building->getBuildingType(), "Landmark");
    EXPECT_FALSE(building->isBuilt());
    EXPECT_GT(building->getTourismValue(), 0.0);
    EXPECT_EQ(building->getVisitorCount(), 0);
}

// Test tourism value
TEST_F(LandmarkTests, TourismValue) {
    building->build();
    
    // Initial value at full condition
    double initialValue = building->getTourismValue();
    EXPECT_DOUBLE_EQ(initialValue, 100.0);  // Base value * 1.0 condition
    
    // Reduce condition to 50%
    building->setCondition(0.5);
    EXPECT_DOUBLE_EQ(building->getTourismValue(), 50.0);  // Base value * 0.5 condition
    
    // Improve condition through maintenance
    building->maintain();
    EXPECT_GT(building->getTourismValue(), 50.0);
    EXPECT_LE(building->getTourismValue(), 100.0);
}

// Test visitor count
TEST_F(LandmarkTests, VisitorCount) {
    building->build();
    
    // Should start with no visitors
    EXPECT_EQ(building->getVisitorCount(), 0);
    
    // Update should bring in visitors
    building->update();
    EXPECT_GT(building->getVisitorCount(), 0);
}

// Test maintenance impact
TEST_F(LandmarkTests, MaintenanceImpact) {
    building->build();
    building->setCondition(0.5);
    building->update();
    
    int visitorsBeforeMaintenance = building->getVisitorCount();
    
    building->maintain();
    building->update();
    
    // Better condition should attract more visitors
    EXPECT_GT(building->getVisitorCount(), visitorsBeforeMaintenance);
}

// Test resource consumption
TEST_F(LandmarkTests, ResourceConsumption) {
    building->build();
    
    EXPECT_TRUE(building->hasEnoughResources());
    building->consumeResources();
    
    // Should still have resources (ResourceManager)
    EXPECT_TRUE(building->hasEnoughResources());
}

// Test historical value
TEST_F(LandmarkTests, HistoricalValue) {
    EXPECT_EQ(building->getLandmarkType(), "Historical");
    EXPECT_GT(building->getTourismValue(), 50.0);  // Significant historical value
}

// Test visitor pattern
TEST_F(LandmarkTests, VisitorAcceptance) {
    class TestVisitor : public BuildingVisitor {
    public:
        bool visitedLandmark = false;
        
        void visitResidential(Residential*) override {}
        void visitCommercial(Commercial*) override {}
        void visitIndustrial(Industrial*) override {}
        void visitLandmark(Landmark*) override { visitedLandmark = true; }
    };
    
    TestVisitor visitor;
    building->accept(&visitor);
    EXPECT_TRUE(visitor.visitedLandmark);
} 