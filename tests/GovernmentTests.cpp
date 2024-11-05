#include <gtest/gtest.h>
#include "../src/Government.h"

class GovernmentTests : public ::testing::Test {
protected:
    Government* government;

    void SetUp() override {
        government = new Government("Test City");
    }

    void TearDown() override {
        delete government;
    }
};

// Test Initial State
TEST_F(GovernmentTests, InitialState) {
    EXPECT_EQ(government->getTreasuryBalance(), 10000.0);
    EXPECT_EQ(government->getApprovalRating(), 50.0);
    EXPECT_EQ(government->getTaxRate("residential"), 0.05);
    EXPECT_EQ(government->getTaxRate("commercial"), 0.07);
    EXPECT_EQ(government->getTaxRate("industrial"), 0.06);
}

// Test Tax Rate Adjustment
TEST_F(GovernmentTests, TaxRateAdjustment) {
    government->adjustTaxRate("residential", 0.06);
    EXPECT_EQ(government->getTaxRate("residential"), 0.06);
    
    // Test invalid tax type
    government->adjustTaxRate("invalid", 0.1);
    EXPECT_EQ(government->getTaxRate("invalid"), 0.0);
}

// Test Tax Collection
TEST_F(GovernmentTests, TaxCollection) {
    double initialBalance = government->getTreasuryBalance();
    government->collectTaxes();
    EXPECT_GE(government->getTreasuryBalance(), initialBalance);
}

// Test Budget Update
TEST_F(GovernmentTests, BudgetUpdate) {
    government->collectTaxes();  // Get some money first
    double initialBalance = government->getTreasuryBalance();
    government->updateBudget();
    EXPECT_NE(government->getTreasuryBalance(), initialBalance);
}

// Test Service Funding
TEST_F(GovernmentTests, ServiceFunding) {
    government->setServiceFunding("education", 1000.0);
    EXPECT_EQ(government->getServiceLevel("education"), 1000.0);
    
    // Test invalid service
    EXPECT_EQ(government->getServiceLevel("invalid"), 0.0);
}

// Test City Services
TEST_F(GovernmentTests, CityServices) {
    double initialApproval = government->getApprovalRating();
    government->setServiceFunding("education", 1000.0);
    government->provideCityServices();
    EXPECT_NE(government->getApprovalRating(), initialApproval);
}

// Test Policy Management
TEST_F(GovernmentTests, PolicyManagement) {
    EXPECT_FALSE(government->isPolicyActive("Green Initiative"));
    
    government->setPolicy("Green Initiative", true);
    EXPECT_TRUE(government->isPolicyActive("Green Initiative"));
    
    government->setPolicy("Green Initiative", false);
    EXPECT_FALSE(government->isPolicyActive("Green Initiative"));
}

// Test Approval Rating Updates
TEST_F(GovernmentTests, ApprovalRating) {
    double initialApproval = government->getApprovalRating();
    
    // Increase tax rates (should lower approval)
    government->adjustTaxRate("residential", 0.10);
    government->updateApprovalRating();
    
    EXPECT_LT(government->getApprovalRating(), initialApproval);
}

// Test Multiple Updates
TEST_F(GovernmentTests, MultipleUpdates) {
    double initialBalance = government->getTreasuryBalance();
    double initialApproval = government->getApprovalRating();
    
    // Simulate multiple update cycles
    for(int i = 0; i < 3; i++) {
        government->collectTaxes();
        government->provideCityServices();
        government->updateBudget();
        government->updateApprovalRating();
        government->updatePolicies();
        government->updateStatistics();
    }
    
    EXPECT_NE(government->getTreasuryBalance(), initialBalance);
    EXPECT_NE(government->getApprovalRating(), initialApproval);
}

// Test Service Level Impact
TEST_F(GovernmentTests, ServiceLevelImpact) {
    double initialApproval = government->getApprovalRating();
    
    // Set low service funding
    government->setServiceFunding("education", 100.0);
    government->setServiceFunding("healthcare", 100.0);
    government->provideCityServices();
    government->updateApprovalRating();
    
    double lowFundingApproval = government->getApprovalRating();
    
    // Set high service funding
    government->setServiceFunding("education", 1000.0);
    government->setServiceFunding("healthcare", 1000.0);
    government->provideCityServices();
    government->updateApprovalRating();
    
    EXPECT_GT(government->getApprovalRating(), lowFundingApproval);
}

// Test Statistics Updates
TEST_F(GovernmentTests, StatisticsTracking) {
    const Statistics& stats = government->getStatistics();
    
    // Perform various actions
    government->collectTaxes();
    government->provideCityServices();
    government->updateStatistics();
    
    // Check that statistics are being tracked
    EXPECT_GE(stats.getCurrentValue("treasuryBalance"), 0.0);
    EXPECT_GE(stats.getCurrentValue("approvalRating"), 0.0);
} 