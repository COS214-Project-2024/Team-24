#include <gtest/gtest.h>
#include "../src/ResourceManager.h"
#include "../src/Residential.h"
#include "../src/Commercial.h"
#include "../src/Industrial.h"

class ResourceManagerTests : public ::testing::Test {
protected:
    ResourceManager& manager = ResourceManager::getInstance();

    void SetUp() override {
        // Reset resources and capacities to initial values
        manager.setResourceAmount("power", 1000.0);
        manager.setResourceAmount("water", 1000.0);
        manager.setResourceAmount("waste", 0.0);
        
        // Reset capacities to default values
        manager.setResourceCapacity("power", 2000.0);
        manager.setResourceCapacity("water", 2000.0);
        manager.setResourceCapacity("waste", 1000.0);
    }
};

// Test resource initialization
TEST_F(ResourceManagerTests, Initialization) {
    EXPECT_EQ(manager.getResourceAmount("power"), 1000.0);
    EXPECT_EQ(manager.getResourceAmount("water"), 1000.0);
    EXPECT_EQ(manager.getResourceAmount("waste"), 0.0);
}

// Test resource addition
TEST_F(ResourceManagerTests, ResourceAddition) {
    manager.addResource("power", 500.0);
    EXPECT_EQ(manager.getResourceAmount("power"), 1500.0);
}

// Test resource consumption
TEST_F(ResourceManagerTests, ResourceConsumption) {
    manager.consumeResource("power", 500.0);
    EXPECT_EQ(manager.getResourceAmount("power"), 500.0);
}

// Test resource update
TEST_F(ResourceManagerTests, ResourceUpdate) {
    manager.updateResource("power", -200.0);
    EXPECT_EQ(manager.getResourceAmount("power"), 800.0);
    
    manager.updateResource("power", 300.0);
    EXPECT_EQ(manager.getResourceAmount("power"), 1100.0);
}

// Test resource capacity
TEST_F(ResourceManagerTests, ResourceCapacity) {
    // Try to add beyond capacity
    manager.addResource("power", 2000.0);  // Capacity is 2000
    EXPECT_EQ(manager.getResourceAmount("power"), 2000.0);
    
    // Test capacity getter
    EXPECT_EQ(manager.getResourceCapacity("power"), 2000.0);
    
    // Test setting new capacity
    manager.setResourceCapacity("power", 3000.0);
    EXPECT_EQ(manager.getResourceCapacity("power"), 3000.0);
}

// Test resource availability check
TEST_F(ResourceManagerTests, ResourceAvailability) {
    EXPECT_TRUE(manager.hasEnoughResource("power", 500.0));
    EXPECT_FALSE(manager.hasEnoughResource("power", 2500.0));
}

// Test invalid resource handling
TEST_F(ResourceManagerTests, InvalidResource) {
    EXPECT_EQ(manager.getResourceAmount("invalid_resource"), 0.0);
    EXPECT_FALSE(manager.hasEnoughResource("invalid_resource", 1.0));
}

// Test resource setting
TEST_F(ResourceManagerTests, ResourceSetting) {
    // First, verify the initial capacity
    EXPECT_EQ(manager.getResourceCapacity("power"), 2000.0);
    
    // Test normal setting
    manager.setResourceAmount("power", 1500.0);
    EXPECT_EQ(manager.getResourceAmount("power"), 1500.0);
    
    // Test setting beyond capacity
    manager.setResourceAmount("power", 3000.0);  // Should be capped at 2000
    EXPECT_EQ(manager.getResourceAmount("power"), 2000.0);
} 