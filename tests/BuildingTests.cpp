#include <gtest/gtest.h>
#include "../src/Building.h"
#include "../src/Residential.h"
#include "../src/Point.h"

// Test fixture for building tests
class BuildingTestFixture : public ::testing::Test {
protected:
    Building* building;
    Point location;

    void SetUp() override {
        location = Point(1, 1);
        building = new Residential("Test House", location);
    }

    void TearDown() override {
        delete building;
    }
};

// Test building creation
TEST(BuildingTests, Creation) {
    Point loc(0, 0);
    Residential building("Test Building", loc);
    EXPECT_EQ(building.getLocation().getX(), 0);
    EXPECT_EQ(building.getLocation().getY(), 0);
    EXPECT_EQ(building.getBuildingType(), "Residential");
    EXPECT_FALSE(building.isBuilt());
}

// Test building condition
TEST_F(BuildingTestFixture, Condition) {
    EXPECT_DOUBLE_EQ(building->getCondition(), 1.0);
    building->setCondition(0.5);
    EXPECT_DOUBLE_EQ(building->getCondition(), 0.5);
}

// Test building location
TEST_F(BuildingTestFixture, Location) {
    EXPECT_EQ(building->getLocation().getX(), 1);
    EXPECT_EQ(building->getLocation().getY(), 1);
    
    Point newLoc(2, 2);
    building->setLocation(newLoc);
    EXPECT_EQ(building->getLocation().getX(), 2);
    EXPECT_EQ(building->getLocation().getY(), 2);
}

// Test building lifecycle
TEST_F(BuildingTestFixture, Lifecycle) {
    EXPECT_FALSE(building->isBuilt());
    
    building->build();
    EXPECT_TRUE(building->isBuilt());
    EXPECT_DOUBLE_EQ(building->getCondition(), 1.0);
    
    building->demolish();
    EXPECT_FALSE(building->isBuilt());
    EXPECT_DOUBLE_EQ(building->getCondition(), 0.0);
}

// Test resource consumption
TEST_F(BuildingTestFixture, Resources) {
    building->build();
    EXPECT_TRUE(building->hasEnoughResources());
    
    // Consume resources multiple times
    for (int i = 0; i < 5; i++) {
        building->consumeResources();
    }
    
    // Building should still have resources due to ResourceManager
    EXPECT_TRUE(building->hasEnoughResources());
}

// Test maintenance
TEST_F(BuildingTestFixture, Maintenance) {
    building->build();
    building->setCondition(0.3);
    EXPECT_DOUBLE_EQ(building->getCondition(), 0.3);
    
    building->maintain();
    EXPECT_GT(building->getCondition(), 0.3);
}