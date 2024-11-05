#include <gtest/gtest.h>
#include "../src/ZoneManager.h"
#include "../src/Residential.h"
#include "../src/Commercial.h"
#include "../src/Industrial.h"
#include "../src/Landmark.h"

class ZoneManagerTests : public ::testing::Test {
protected:
    ZoneManager* manager;

    void SetUp() override {
        manager = new ZoneManager();
    }

    void TearDown() override {
        delete manager;
    }
};

// Test zone creation
TEST_F(ZoneManagerTests, ZoneCreation) {
    Zone* zone = manager->createZone("Test Zone", Point(0, 0), 4);
    ASSERT_NE(zone, nullptr);
    EXPECT_EQ(zone->getName(), "Test Zone");
    EXPECT_EQ(zone->getLocation().getX(), 0);
    EXPECT_EQ(zone->getLocation().getY(), 0);
    EXPECT_EQ(zone->getSize(), 4);
}

// Test zone finding
TEST_F(ZoneManagerTests, ZoneFinding) {
    Zone* zone1 = manager->createZone("Zone 1", Point(0, 0), 4);
    Zone* zone2 = manager->createZone("Zone 2", Point(5, 5), 4);
    
    EXPECT_EQ(manager->findZone("Zone 1"), zone1);
    EXPECT_EQ(manager->findZone("Zone 2"), zone2);
    EXPECT_EQ(manager->findZone("Non-existent Zone"), nullptr);
}

// Test building placement
TEST_F(ZoneManagerTests, BuildingPlacement) {
    Zone* zone = manager->createZone("Residential Zone", Point(0, 0), 4);
    Building* building = new Residential("House", Point(1, 1));
    
    EXPECT_TRUE(manager->placeBuilding(building, zone));
    EXPECT_TRUE(zone->getBuildings().size() == 1);
}

// Test compatible zone finding
TEST_F(ZoneManagerTests, FindCompatibleZone) {
    // Create zones with specific types
    Zone* residentialZone = manager->createZone("Residential Zone", Point(0, 0), 4);
    residentialZone->setZoneType("Residential");
    
    Zone* commercialZone = manager->createZone("Commercial Zone", Point(5, 5), 4);
    commercialZone->setZoneType("Commercial");
    
    // Create buildings
    Building* residential = new Residential("House", Point(1, 1));
    Building* commercial = new Commercial("Shop", Point(1, 1));
    
    // Find compatible zones
    Zone* foundResZone = manager->findCompatibleZone(residential);
    EXPECT_EQ(foundResZone, residentialZone);
    
    Zone* foundComZone = manager->findCompatibleZone(commercial);
    EXPECT_EQ(foundComZone, commercialZone);
    
    // Try placing buildings
    bool placedRes = false;
    bool placedCom = false;
    
    if (foundResZone) {
        placedRes = manager->placeBuilding(residential, foundResZone);
    }
    
    if (foundComZone) {
        placedCom = manager->placeBuilding(commercial, foundComZone);
    }
    
    EXPECT_TRUE(placedRes);
    EXPECT_TRUE(placedCom);
    
    // Clean up if placement failed
    if (!placedRes) delete residential;
    if (!placedCom) delete commercial;
}

// Test zone removal
TEST_F(ZoneManagerTests, ZoneRemoval) {
    Zone* zone = manager->createZone("Test Zone", Point(0, 0), 4);
    EXPECT_TRUE(manager->removeZone(zone));
    EXPECT_EQ(manager->findZone("Test Zone"), nullptr);
}

// Test zone capacity
TEST_F(ZoneManagerTests, ZoneCapacity) {
    Zone* zone = manager->createZone("Test Zone", Point(0, 0), 2); // 2x2 zone
    
    // Should fit 4 buildings (2x2)
    for (int i = 0; i < 4; i++) {
        Building* building = new Residential(
            "House " + std::to_string(i),
            Point(i % 2, i / 2)
        );
        EXPECT_TRUE(manager->placeBuilding(building, zone));
    }
    
    // Fifth building should fail
    Building* extraBuilding = new Residential("Extra House", Point(0, 0));
    EXPECT_FALSE(manager->placeBuilding(extraBuilding, zone));
    delete extraBuilding;
}

// Test zone update
TEST_F(ZoneManagerTests, ZoneUpdate) {
    Zone* zone = manager->createZone("Test Zone", Point(0, 0), 4);
    Building* building = new Residential("House", Point(1, 1));
    
    manager->placeBuilding(building, zone);
    building->build();
    
    manager->update();
    EXPECT_TRUE(building->isBuilt());
    EXPECT_GT(building->getCondition(), 0.0);
} 