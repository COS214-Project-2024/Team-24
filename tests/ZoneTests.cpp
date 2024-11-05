#include <gtest/gtest.h>
#include "../src/Zone.h"
#include "../src/Residential.h"
#include "../src/Commercial.h"
#include "../src/Industrial.h"
#include "../src/Landmark.h"

class ZoneTests : public ::testing::Test {
protected:
    Zone* zone;
    Point location;

    void SetUp() override {
        location = Point(0, 0);
        zone = new Zone("Test Zone", location, 4);  // 4x4 zone
    }

    void TearDown() override {
        delete zone;
    }
};

// Test zone creation
TEST_F(ZoneTests, Creation) {
    EXPECT_EQ(zone->getName(), "Test Zone");
    EXPECT_EQ(zone->getLocation().getX(), 0);
    EXPECT_EQ(zone->getLocation().getY(), 0);
    EXPECT_EQ(zone->getSize(), 4);
    EXPECT_TRUE(zone->getBuildings().empty());
}

// Test building placement
TEST_F(ZoneTests, BuildingPlacement) {
    Building* building = new Residential("Test House", Point(1, 1));
    
    EXPECT_TRUE(zone->addBuilding(building));
    EXPECT_EQ(zone->getBuildings().size(), 1);
    EXPECT_EQ(zone->getBuildings()[0], building);
}

// Test building capacity
TEST_F(ZoneTests, BuildingCapacity) {
    // Should be able to add buildings up to capacity
    for (int i = 0; i < 16; i++) {  // 4x4 = 16 spots
        Building* building = new Residential(
            "House " + std::to_string(i), 
            Point(i % 4, i / 4)
        );
        EXPECT_TRUE(zone->addBuilding(building));
    }
    
    // Should fail to add more buildings
    Building* extraBuilding = new Residential("Extra House", Point(0, 0));
    EXPECT_FALSE(zone->addBuilding(extraBuilding));
    delete extraBuilding;
}

// Test building removal
TEST_F(ZoneTests, BuildingRemoval) {
    Building* building = new Residential("Test House", Point(1, 1));
    zone->addBuilding(building);
    
    EXPECT_TRUE(zone->removeBuilding(building));
    EXPECT_TRUE(zone->getBuildings().empty());
}

// Test zone update
TEST_F(ZoneTests, ZoneUpdate) {
    Building* building = new Residential("Test House", Point(1, 1));
    zone->addBuilding(building);
    building->build();
    
    zone->update();
    EXPECT_TRUE(building->isBuilt());
    EXPECT_GT(building->getCondition(), 0.0);
}

// Test zone maintenance
TEST_F(ZoneTests, ZoneMaintenance) {
    Building* building = new Residential("Test House", Point(1, 1));
    zone->addBuilding(building);
    building->build();
    building->setCondition(0.5);
    
    zone->maintain();
    EXPECT_GT(building->getCondition(), 0.5);
}

// Test visitor pattern
TEST_F(ZoneTests, VisitorPattern) {
    Building* residential = new Residential("House", Point(0, 0));
    Building* commercial = new Commercial("Shop", Point(1, 0));
    Building* industrial = new Industrial("Factory", Point(2, 0));
    Building* landmark = new Landmark("Monument", Point(3, 0));
    
    zone->addBuilding(residential);
    zone->addBuilding(commercial);
    zone->addBuilding(industrial);
    zone->addBuilding(landmark);
    
    class TestVisitor : public BuildingVisitor {
    public:
        int visitCount = 0;
        
        void visitResidential(Residential*) override { visitCount++; }
        void visitCommercial(Commercial*) override { visitCount++; }
        void visitIndustrial(Industrial*) override { visitCount++; }
        void visitLandmark(Landmark*) override { visitCount++; }
    };
    
    TestVisitor visitor;
    zone->accept(&visitor);
    EXPECT_EQ(visitor.visitCount, 4);
}

// Test building placement validation
TEST_F(ZoneTests, BuildingPlacementValidation) {
    // Test valid position
    Building* building1 = new Residential("House 1", Point(1, 1));
    EXPECT_TRUE(zone->canAcceptBuilding(building1));
    bool added1 = zone->addBuilding(building1);
    EXPECT_TRUE(added1);
    if (!added1) {
        delete building1;
    }
    
    // Test invalid position (outside zone)
    Building* building2 = new Residential("House 2", Point(5, 5));
    EXPECT_FALSE(zone->canAcceptBuilding(building2));
    bool added2 = zone->addBuilding(building2);
    EXPECT_FALSE(added2);
    if (!added2) {
        delete building2;
    }
    
    // Test null building
    EXPECT_FALSE(zone->canAcceptBuilding(nullptr));
}

// Test overlapping buildings
TEST_F(ZoneTests, BuildingOverlap) {
    Point location(1, 1);
    
    // Add first building
    Building* building1 = new Residential("House 1", location);
    bool added1 = zone->addBuilding(building1);
    EXPECT_TRUE(added1);
    if (!added1) {
        delete building1;
    }
    
    // Try to add second building at same location
    Building* building2 = new Commercial("Shop", location);
    bool added2 = zone->addBuilding(building2);
    EXPECT_FALSE(added2);
    if (!added2) {
        delete building2;
    }
}

// Test zone capacity checks
TEST_F(ZoneTests, ZoneCapacityChecks) {
    // Fill the zone to capacity
    for (int i = 0; i < 16; i++) {  // 4x4 zone
        Building* building = new Residential(
            "House " + std::to_string(i), 
            Point(i % 4, i / 4)
        );
        EXPECT_TRUE(zone->canAcceptBuilding(building));
        EXPECT_TRUE(zone->addBuilding(building));
    }
    
    EXPECT_TRUE(zone->isFull());
    
    // Try to add one more building
    Building* extraBuilding = new Residential("Extra House", Point(0, 0));
    EXPECT_FALSE(zone->canAcceptBuilding(extraBuilding));
    EXPECT_FALSE(zone->addBuilding(extraBuilding));
    
    delete extraBuilding;
}

// Test valid positions
TEST_F(ZoneTests, ValidPositions) {
    // Test boundary conditions
    EXPECT_TRUE(zone->isValidPosition(Point(0, 0)));     // Top-left
    EXPECT_TRUE(zone->isValidPosition(Point(3, 3)));     // Bottom-right
    EXPECT_TRUE(zone->isValidPosition(Point(2, 2)));     // Middle
    
    // Test invalid positions
    EXPECT_FALSE(zone->isValidPosition(Point(-1, 0)));   // Left of zone
    EXPECT_FALSE(zone->isValidPosition(Point(0, -1)));   // Above zone
    EXPECT_FALSE(zone->isValidPosition(Point(4, 0)));    // Right of zone
    EXPECT_FALSE(zone->isValidPosition(Point(0, 4)));    // Below zone
    EXPECT_FALSE(zone->isValidPosition(Point(4, 4)));    // Outside corner
} 