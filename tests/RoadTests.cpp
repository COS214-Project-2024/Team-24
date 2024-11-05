#include <gtest/gtest.h>
#include "../src/Road.h"
#include "../src/RoadNetwork.h"
#include "../src/RoadBuilder.h"
#include "../src/Residential.h"
#include "../src/Commercial.h"

class RoadTests : public ::testing::Test {
protected:
    std::shared_ptr<Road> road;
    std::shared_ptr<Residential> building1;
    std::shared_ptr<Commercial> building2;
    RoadNetwork network;
    RoadBuilder builder;

    void SetUp() override {
        road = std::make_shared<Road>("main", "Test Road");
        building1 = std::make_shared<Residential>("Building 1", Point(0,0));
        building2 = std::make_shared<Commercial>("Building 2", Point(1,1));
    }
};

// Test Road Creation
TEST_F(RoadTests, RoadCreation) {
    EXPECT_EQ(road->getRoadType(), "main");
    EXPECT_EQ(road->getRoadName(), "Test Road");
    EXPECT_EQ(road->getTrafficLevel(), 0);
    EXPECT_EQ(road->getNumberOfBuildings(), 0);
}

// Test Building Connections
TEST_F(RoadTests, BuildingConnections) {
    EXPECT_TRUE(road->connectBuilding(building1));
    EXPECT_EQ(road->getNumberOfBuildings(), 1);
    
    // Test duplicate connection
    EXPECT_FALSE(road->connectBuilding(building1));
    EXPECT_EQ(road->getNumberOfBuildings(), 1);
}

// Test Building Disconnections
TEST_F(RoadTests, BuildingDisconnections) {
    road->connectBuilding(building1);
    EXPECT_TRUE(road->disconnectBuilding(building1));
    EXPECT_EQ(road->getNumberOfBuildings(), 0);
    
    // Test disconnecting non-existent building
    EXPECT_FALSE(road->disconnectBuilding(building2));
}

// Test Traffic Level Management
TEST_F(RoadTests, TrafficManagement) {
    road->setTrafficLevel(50);
    EXPECT_EQ(road->getTrafficLevel(), 50);
    
    // Test max traffic cap
    road->setTrafficLevel(150);
    EXPECT_EQ(road->getTrafficLevel(), 100);
    
    // Test negative traffic prevention
    road->setTrafficLevel(-10);
    EXPECT_EQ(road->getTrafficLevel(), 0);
}

// Test RoadBuilder
TEST_F(RoadTests, RoadBuilder) {
    auto customRoad = builder.setType("highway")
                            .setName("Highway 1")
                            .setTrafficLevel(30)
                            .build();
    
    EXPECT_EQ(customRoad->getRoadType(), "highway");
    EXPECT_EQ(customRoad->getRoadName(), "Highway 1");
    EXPECT_EQ(customRoad->getTrafficLevel(), 30);
}

// Test RoadBuilder Reset
TEST_F(RoadTests, RoadBuilderReset) {
    builder.setType("highway")
          .setName("Highway 1")
          .setTrafficLevel(30);
    
    builder.reset();
    auto defaultRoad = builder.build();
    
    EXPECT_EQ(defaultRoad->getRoadType(), "standard");
    EXPECT_EQ(defaultRoad->getRoadName(), "New Road");
    EXPECT_EQ(defaultRoad->getTrafficLevel(), 0);
}

// Test RoadNetwork Management
TEST_F(RoadTests, RoadNetworkManagement) {
    network.addRoad(road);
    EXPECT_EQ(network.getRoadCount(), 1);
    
    EXPECT_TRUE(network.removeRoad(road.get()));
    EXPECT_EQ(network.getRoadCount(), 0);
}

// Test Network Traffic Optimization
TEST_F(RoadTests, NetworkTrafficOptimization) {
    auto road1 = builder.setTrafficLevel(80).build();
    auto road2 = builder.setTrafficLevel(20).build();
    
    network.addRoad(road1);
    network.addRoad(road2);
    
    network.optimizeTraffic();
    
    // After optimization, traffic levels should be more balanced
    EXPECT_LT(std::abs(road1->getTrafficLevel() - road2->getTrafficLevel()), 
              std::abs(80 - 20));
}

// Test Network Connectivity
TEST_F(RoadTests, NetworkConnectivity) {
    auto road1 = builder.build();
    auto road2 = builder.build();
    
    network.addRoad(road1);
    network.addRoad(road2);
    
    // Initially not connected (no buildings)
    EXPECT_FALSE(network.isConnected());
    
    // Add buildings to make it connected
    road1->connectBuilding(building1);
    road2->connectBuilding(building2);
    
    EXPECT_TRUE(network.isConnected());
}

// Test Average Traffic Calculation
TEST_F(RoadTests, AverageTrafficCalculation) {
    auto road1 = builder.setTrafficLevel(60).build();
    auto road2 = builder.setTrafficLevel(40).build();
    
    network.addRoad(road1);
    network.addRoad(road2);
    
    EXPECT_EQ(network.getAverageTraffic(), 50.0);
} 