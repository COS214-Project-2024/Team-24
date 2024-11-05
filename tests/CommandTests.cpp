#include <gtest/gtest.h>
#include "../src/BuildCommand.h"
#include "../src/DemolishCommand.h"
#include "../src/UpdateResourcesCommand.h"
#include "../src/ResourceManager.h"
#include "../src/Residential.h"
#include "../src/Commercial.h"

class CommandTests : public ::testing::Test {
protected:
    std::shared_ptr<Residential> residential;
    std::shared_ptr<Commercial> commercial;
    ResourceManager& resourceManager;
    Point testPoint;

    CommandTests() 
        : resourceManager(ResourceManager::getInstance())
        , testPoint(2,2) {
    }

    void SetUp() override {
        residential = std::make_shared<Residential>("Test House", Point(0,0));
        commercial = std::make_shared<Commercial>("Test Shop", Point(1,1));
        resourceManager.resetToDefaults();
    }
};

TEST_F(CommandTests, BasicResourceOperation) {
    // Initial state should be default values
    EXPECT_EQ(resourceManager.getResourceAmount("power"), 1000.0);
    EXPECT_EQ(resourceManager.getResourceAmount("water"), 1000.0);
    EXPECT_EQ(resourceManager.getResourceAmount("waste"), 0.0);
    
    // Test setting resource amount
    resourceManager.setResourceAmount("power", 1500.0);
    EXPECT_EQ(resourceManager.getResourceAmount("power"), 1500.0);
    
    // Test updating resource
    resourceManager.updateResource("power", 200.0);
    EXPECT_EQ(resourceManager.getResourceAmount("power"), 1700.0);
}

TEST_F(CommandTests, ResourceCapacityTest) {
    // Test capacity enforcement
    resourceManager.setResourceCapacity("power", 1500.0);
    resourceManager.setResourceAmount("power", 2000.0);  // Should be capped at 1500
    EXPECT_EQ(resourceManager.getResourceAmount("power"), 1500.0);
}

TEST_F(CommandTests, ResourceConsumptionTest) {
    // Test resource consumption
    resourceManager.setResourceAmount("water", 1000.0);
    resourceManager.consumeResource("water", 300.0);
    EXPECT_EQ(resourceManager.getResourceAmount("water"), 700.0);
}

TEST_F(CommandTests, ResourceAvailabilityTest) {
    resourceManager.setResourceAmount("power", 500.0);
    EXPECT_TRUE(resourceManager.hasEnoughResource("power", 300.0));
    EXPECT_FALSE(resourceManager.hasEnoughResource("power", 600.0));
}

TEST_F(CommandTests, BuildCommandExecution) {
    BuildCommand buildCmd(residential.get(), testPoint);
    buildCmd.execute();
    EXPECT_TRUE(buildCmd.isExecuted());
    EXPECT_EQ(residential->getLocation(), testPoint);
}
  