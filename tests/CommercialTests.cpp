#include <gtest/gtest.h>
#include "../src/Commercial.h"
#include "../src/Point.h"
#include "../src/BuildingVisitor.h"

class CommercialTests : public ::testing::Test {
protected:
    Commercial* building;
    Point location;

    void SetUp() override {
        location = Point(1, 1);
        building = new Commercial("Test Shop", location);
    }

    void TearDown() override {
        delete building;
    }
};

// Test basic commercial creation
TEST_F(CommercialTests, Creation) {
    EXPECT_EQ(building->getBuildingType(), "Commercial");
    EXPECT_FALSE(building->isBuilt());
    EXPECT_DOUBLE_EQ(building->getRevenue(), 0.0);
    EXPECT_EQ(building->getCurrentCustomers(), 0);
}

// Test revenue generation
TEST_F(CommercialTests, RevenueGeneration) {
    building->build();
    
    // Initial state
    double initialRevenue = building->getRevenue();
    EXPECT_DOUBLE_EQ(initialRevenue, 0.0);
    
    // Update should generate some revenue when built and operational
    building->update();
    EXPECT_GT(building->getRevenue(), initialRevenue);
}

// Test customer traffic
TEST_F(CommercialTests, CustomerTraffic) {
    building->build();
    
    // Should start with no customers
    EXPECT_EQ(building->getCurrentCustomers(), 0);
    
    // Update should bring in customers
    building->update();
    EXPECT_GT(building->getCurrentCustomers(), 0);
}

// Test retail efficiency
TEST_F(CommercialTests, RetailEfficiency) {
    building->build();
    double initialEfficiency = building->getRetailEfficiency();
    
    // Damage the building to reduce efficiency
    building->setCondition(0.5);
    building->update();  // Update needed to recalculate efficiency
    
    EXPECT_LT(building->getRetailEfficiency(), initialEfficiency);
    double damagedEfficiency = building->getRetailEfficiency();
    
    // Maintain to improve efficiency
    building->maintain();
    building->update();  // Update needed to recalculate efficiency
    
    EXPECT_GT(building->getRetailEfficiency(), damagedEfficiency);
}

// Test resource consumption
TEST_F(CommercialTests, ResourceConsumption) {
    building->build();
    
    // Should consume resources when operational
    EXPECT_TRUE(building->hasEnoughResources());
    building->consumeResources();
    
    // Still should have resources (thanks to ResourceManager)
    EXPECT_TRUE(building->hasEnoughResources());
}

// Test visitor pattern
TEST_F(CommercialTests, VisitorAcceptance) {
    class TestVisitor : public BuildingVisitor {
    public:
        bool visitedCommercial = false;
        
        void visitResidential(Residential*) override {}
        void visitCommercial(Commercial*) override { visitedCommercial = true; }
        void visitIndustrial(Industrial*) override {}
        void visitLandmark(Landmark*) override {}
    };
    
    TestVisitor visitor;
    building->accept(&visitor);
    EXPECT_TRUE(visitor.visitedCommercial);
} 