#include <gtest/gtest.h>
#include "../src/Industrial.h"
#include "../src/Point.h"
#include "../src/BuildingVisitor.h"

class IndustrialTests : public ::testing::Test {
protected:
    Industrial* building;
    Point location;

    void SetUp() override {
        location = Point(1, 1);
        building = new Industrial("Test Factory", location);
    }

    void TearDown() override {
        delete building;
    }
};

// Test basic industrial creation
TEST_F(IndustrialTests, Creation) {
    EXPECT_EQ(building->getBuildingType(), "Industrial");
    EXPECT_DOUBLE_EQ(building->getBaseProductionRate(), 10.0);
    EXPECT_DOUBLE_EQ(building->getProductionRate(), 10.0);
    EXPECT_GT(building->getPollutionLevel(), 0.0);
}

// Test production
TEST_F(IndustrialTests, Production) {
    building->build();
    
    // Should produce resources when operational
    double initialProduction = building->getProductionRate();
    building->update();
    
    // Production should be affected by condition and efficiency
    EXPECT_GT(building->getProductionRate() * building->getCondition(), 0.0);
}

// Test pollution generation
TEST_F(IndustrialTests, PollutionGeneration) {
    building->build();
    
    double initialPollution = building->getPollutionLevel();
    building->update();
    
    // Should generate pollution during operation
    EXPECT_GE(building->getPollutionLevel(), initialPollution);
}

// Test efficiency
TEST_F(IndustrialTests, ProductionEfficiency) {
    building->build();
    
    // Damage the building to reduce efficiency
    building->setCondition(0.5);
    building->update();
    double damagedProduction = building->getProductionRate() * building->getCondition();
    
    // Maintain to improve efficiency
    building->maintain();
    building->update();
    double repairedProduction = building->getProductionRate() * building->getCondition();
    
    EXPECT_GT(repairedProduction, damagedProduction);
}

// Test resource consumption
TEST_F(IndustrialTests, ResourceConsumption) {
    building->build();
    
    EXPECT_TRUE(building->hasEnoughResources());
    building->consumeResources();
    
    // Should still have resources (ResourceManager)
    EXPECT_TRUE(building->hasEnoughResources());
}

// Test waste generation
TEST_F(IndustrialTests, WasteGeneration) {
    building->build();
    building->update();
    
    // Should generate waste during operation
    EXPECT_GT(building->getWasteProduction(), 0.0);
}

// Test visitor pattern
TEST_F(IndustrialTests, VisitorAcceptance) {
    class TestVisitor : public BuildingVisitor {
    public:
        bool visitedIndustrial = false;
        
        void visitResidential(Residential*) override {}
        void visitCommercial(Commercial*) override {}
        void visitIndustrial(Industrial*) override { visitedIndustrial = true; }
        void visitLandmark(Landmark*) override {}
    };
    
    TestVisitor visitor;
    building->accept(&visitor);
    EXPECT_TRUE(visitor.visitedIndustrial);
} 