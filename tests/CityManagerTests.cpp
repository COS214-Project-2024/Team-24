#include <gtest/gtest.h>
#include "../src/CityManager.h"
#include "../src/Residential.h"

class CityManagerTests : public ::testing::Test {
protected:
    CityManager* city;

    void SetUp() override {
        city = new CityManager("Test City");
    }

    void TearDown() override {
        delete city;
    }
};

// Test city creation
TEST_F(CityManagerTests, Creation) {
    EXPECT_EQ(city->getName(), "Test City");
    ASSERT_NE(city->getZoneManager(), nullptr);
}

// Test zone management
TEST_F(CityManagerTests, ZoneManagement) {
    Zone* zone = city->createZone("Residential Area", Point(0, 0), 4);
    ASSERT_NE(zone, nullptr);
    EXPECT_EQ(zone->getName(), "Residential Area");
    
    // Test zone finding
    EXPECT_EQ(city->findZone("Residential Area"), zone);
    EXPECT_EQ(city->findZone("Non-existent Zone"), nullptr);
}

// Test building placement
TEST_F(CityManagerTests, BuildingPlacement) {
    Zone* zone = city->createZone("Test Zone", Point(0, 0), 4);
    Building* residential = new Residential("House", Point(1, 1));
    
    EXPECT_TRUE(city->placeBuilding(residential, zone));
    EXPECT_EQ(zone->getBuildings().size(), 1);
    
    // Test invalid placement (overlapping)
    Building* overlapping = new Residential("Overlapping House", Point(1, 1));
    EXPECT_FALSE(city->placeBuilding(overlapping, zone));
    delete overlapping;
}

// Test updates
TEST_F(CityManagerTests, Updates) {
    Zone* zone = city->createZone("Test Zone", Point(0, 0), 4);
    Building* residential = new Residential("House", Point(1, 1));
    
    city->placeBuilding(residential, zone);
    city->update();  // Should update all zones and buildings
} 