#include <gtest/gtest.h>
#include "../src/Government.h"
#include "../src/Statistics.h"

class GovernmentStatisticsTests : public ::testing::Test {
protected:
    Government* government;

    void SetUp() override {
        government = new Government("Test City");
        // Force an initial statistics update
        government->updateStatistics();
    }

    void TearDown() override {
        delete government;
    }
};

// Test basic statistics tracking
TEST_F(GovernmentStatisticsTests, BasicStatisticsTracking) {
    const Statistics& stats = government->getStatistics();
    
    // Test that values exist (not testing specific values)
    EXPECT_GE(stats.getCurrentValue("approvalRating"), 0.0);
    EXPECT_GE(stats.getCurrentValue("treasuryBalance"), 0.0);
}

// Test tax rate tracking
TEST_F(GovernmentStatisticsTests, TaxRateTracking) {
    const Statistics& stats = government->getStatistics();
    
    // Test that tax rates exist and are within expected ranges
    EXPECT_GE(stats.getCurrentValue("residential_tax"), 0.0);
    EXPECT_LE(stats.getCurrentValue("residential_tax"), 0.1);
    
    EXPECT_GE(stats.getCurrentValue("commercial_tax"), 0.0);
    EXPECT_LE(stats.getCurrentValue("commercial_tax"), 0.1);
    
    EXPECT_GE(stats.getCurrentValue("industrial_tax"), 0.0);
    EXPECT_LE(stats.getCurrentValue("industrial_tax"), 0.1);
}

// Test service level tracking
TEST_F(GovernmentStatisticsTests, ServiceLevelTracking) {
    // First set some service funding
    government->setServiceFunding("education", 1000.0);
    government->setServiceFunding("healthcare", 1000.0);
    
    // Get current service levels
    EXPECT_GT(government->getServiceLevel("education"), 0.0);
    EXPECT_GT(government->getServiceLevel("healthcare"), 0.0);
}

// Test approval rating changes
TEST_F(GovernmentStatisticsTests, ApprovalRatingChanges) {
    double initialApproval = government->getApprovalRating();
    
    // Increase tax rates (should lower approval)
    government->adjustTaxRate("residential", 0.10);  // Double the tax rate
    government->updateApprovalRating();
    
    EXPECT_LT(government->getApprovalRating(), initialApproval);
}

// Test treasury balance tracking
TEST_F(GovernmentStatisticsTests, TreasuryTracking) {
    double initialBalance = government->getTreasuryBalance();
    
    // Set a reasonable tax rate and collect taxes
    government->adjustTaxRate("residential", 0.05);
    government->collectTaxes();
    
    EXPECT_GE(government->getTreasuryBalance(), initialBalance);
}

// Test policy status tracking
TEST_F(GovernmentStatisticsTests, PolicyStatusTracking) {
    EXPECT_FALSE(government->isPolicyActive("Green Initiative"));
    
    government->setPolicy("Green Initiative", true);
    EXPECT_TRUE(government->isPolicyActive("Green Initiative"));
}

// Test multiple statistics updates
TEST_F(GovernmentStatisticsTests, MultipleUpdates) {
    double initialBalance = government->getTreasuryBalance();
    
    // Simulate multiple update cycles
    for(int i = 0; i < 3; i++) {
        government->collectTaxes();
        government->provideCityServices();
        government->updateStatistics();
    }
    
    const Statistics& stats = government->getStatistics();
    EXPECT_GE(stats.getGrowthRate("treasuryBalance"), -1.0);
}

// Test service funding effects
TEST_F(GovernmentStatisticsTests, ServiceFundingEffects) {
    double initialApproval = government->getApprovalRating();
    
    // Increase service funding
    government->setServiceFunding("education", 2000.0);
    government->provideCityServices();
    government->updateApprovalRating();
    
    EXPECT_GE(government->getApprovalRating(), initialApproval);
} 